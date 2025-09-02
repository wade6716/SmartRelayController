#define BLINKER_WIFI
#define BLINKER_MIOT_OUTLET   // 小爱同学支持
#include <Blinker.h>

// WiFi和设备认证信息
char auth[] = "*********";
char ssid[] = "*********";
char pswd[] = "*********";

// 定义组件对象
BlinkerButton manualControlButton("btn-on");     // 手动控制按钮
BlinkerButton autoModeButton("btn-kg");          // 自动模式开关按钮

// 全局状态变量
bool devicePowerState = false;        // 设备电源状态
bool autoModeEnabled = true;          // 自动模式是否启用
const int relayPin = D0;              // 继电器控制引脚

// 定时控制相关变量
unsigned long currentTime = 0;
unsigned long nextLowTime = 120000;   // 下次关闭时间 (2分钟后)
unsigned long nextHighTime = 600000;  // 下次开启时间 (10分钟后)

// 小爱同学电源状态控制
void miotPowerState(const String & state)
{
    BLINKER_LOG("小爱同学设置电源状态: ", state);

    if (state == BLINKER_CMD_ON) {
        digitalWrite(relayPin, HIGH);
        BlinkerMIOT.powerState("on");
        BlinkerMIOT.print();
        devicePowerState = true;
    }
    else if (state == BLINKER_CMD_OFF) {
        digitalWrite(relayPin, LOW);
        BlinkerMIOT.powerState("off");
        BlinkerMIOT.print();
        devicePowerState = false;
    }
}

// 小爱同学查询处理
void miotQuery(int32_t queryCode)
{
    BLINKER_LOG("小爱同学查询代码: ", queryCode);

    switch (queryCode) {
        case BLINKER_CMD_QUERY_ALL_NUMBER:
        case BLINKER_CMD_QUERY_POWERSTATE_NUMBER:
        default:
            BlinkerMIOT.powerState(devicePowerState ? "on" : "off");
            BlinkerMIOT.print();
            break;
    }
}

// 手动控制按钮回调函数
void manualControlCallback(const String & state)
{
    BLINKER_LOG("手动控制按钮状态: ", state);

    if (state == "on") {
        digitalWrite(relayPin, HIGH);
        manualControlButton.print("on");
        devicePowerState = true;
    } else {
        digitalWrite(relayPin, LOW);
        manualControlButton.print("off");
        devicePowerState = false;
    }
}

// 自动模式开关回调函数
void autoModeCallback(const String & state)
{
    BLINKER_LOG("自动模式开关状态: ", state);

    if (state == "on") {
        autoModeEnabled = true;
        autoModeButton.print("on");
    } else {
        autoModeEnabled = false;
        autoModeButton.print("off");
    }
}

// 自动定时控制函数
void handleAutoMode(bool isEnabled)
{
    if (!isEnabled) return;

    // 到达关闭时间
    if (currentTime > nextLowTime) {
        nextLowTime = currentTime + 600000;  // 下次关闭时间设为10分钟后
        digitalWrite(relayPin, LOW);
        devicePowerState = false;
    }

    // 到达开启时间
    if (currentTime > nextHighTime) {
        nextHighTime = currentTime + 600000;  // 下次开启时间设为10分钟后
        digitalWrite(relayPin, HIGH);
        devicePowerState = true;
    }
}

void setup()
{
    // 初始化串口通信
    Serial.begin(115200);
    BLINKER_DEBUG.stream(Serial);
    BLINKER_DEBUG.debugAll();

    // 初始化继电器引脚
    pinMode(relayPin, OUTPUT);
    digitalWrite(relayPin, HIGH);
    devicePowerState = true;

    // 初始化Blinker连接
    Blinker.begin(auth, ssid, pswd);

    // 绑定小爱同学功能
    BlinkerMIOT.attachPowerState(miotPowerState);
    BlinkerMIOT.attachQuery(miotQuery);

    // 绑定按钮回调函数
    manualControlButton.attach(manualControlCallback);
    autoModeButton.attach(autoModeCallback);

    // 初始化自动模式按钮状态
    autoModeButton.print("on");
}

void loop()
{
    // 更新当前时间
    currentTime = millis();

    // 处理自动模式
    handleAutoMode(autoModeEnabled);

    // 运行Blinker服务
    Blinker.run();

    // 更新手动控制按钮显示状态
    String currentState = digitalRead(relayPin) ? "on" : "off";
    manualControlButton.print(currentState);

    // 延时1秒
    Blinker.delay(1000);
}