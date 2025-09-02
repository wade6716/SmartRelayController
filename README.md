# Smart Relay Controller / 智能继电器控制器

[English](#english) | [中文](#中文)

---

## English

### 🔌 Overview

A smart relay controller based on Arduino ESP8266/ESP32 that provides WiFi connectivity, mobile app control, and Xiaomi AI (小爱同学) voice control integration. The device supports both manual and automatic timing control modes for relay-based electrical devices.

### ✨ Features

- **WiFi Connectivity**: Connect to your home WiFi network
- **Mobile App Control**: Control via Blinker mobile app
- **Voice Control**: Compatible with Xiaomi AI (小爱同学)
- **Dual Control Modes**:
  - Manual control via mobile app
  - Automatic timing mode with customizable intervals
- **Real-time Status Feedback**: Live status updates in the app
- **Easy Setup**: Simple configuration and deployment

### 🛠 Hardware Requirements

- ESP8266 or ESP32 development board
- Relay module (compatible with 3.3V/5V logic)
- Jumper wires
- Power supply (5V/3.3V)
- Optional: Breadboard for prototyping

### 📋 Pin Configuration

| Component | Pin | Description |
|-----------|-----|-------------|
| Relay Control | D0 | Digital output to control relay |

### 🚀 Getting Started

#### 1. Hardware Setup
1. Connect the relay module to pin D0 on your ESP board
2. Connect power and ground appropriately
3. Ensure proper power supply for both ESP and relay module

#### 2. Software Setup
1. Install Arduino IDE
2. Install ESP8266/ESP32 board package
3. Install Blinker library:
   ```
Tools > Manage Libraries > Search "Blinker" > Install
   ```

#### 3. Configuration
1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/smart-relay-controller.git
   ```
2. Open `smart-relay-controller.ino` in Arduino IDE
3. Configure your credentials:
   ```cpp
   char auth[] = "your_blinker_auth_key";
   char ssid[] = "your_wifi_ssid";
   char pswd[] = "your_wifi_password";
   ```
4. Upload to your ESP board

#### 4. Mobile App Setup
1. Download Blinker app from App Store/Google Play
2. Add device using the auth key
3. Configure the control interface with buttons:
    - Manual Control Button: `btn-on`
    - Auto Mode Switch: `btn-kg`

### 📱 Usage

#### Manual Control
- Use the mobile app to turn the relay on/off manually
- Real-time status feedback in the app

#### Auto Mode
- Enable auto mode via the app
- Device automatically cycles: ON → OFF (2min) → ON (10min)
- Can be disabled anytime via the app

#### Voice Control
- "小爱同学，打开xxx" (Xiaomi AI, turn on xxx)
- "小爱同学，关闭xxx" (Xiaomi AI, turn off xxx)

### 🔧 Customization

#### Timing Intervals
Modify these values in the code to change timing:
```
cpp
unsigned long nextLowTime = 120000;   // OFF duration (2 minutes)
unsigned long nextHighTime = 600000;  // ON duration (10 minutes)
```
#### Pin Configuration
Change the relay pin if needed:
```
cpp
const int relayPin = D0;  // Change to your preferred pin
```
### 📝 API Reference

#### Key Functions
- `miotPowerState()`: Handles Xiaomi AI voice commands
- `manualControlCallback()`: Processes manual control
- `autoModeCallback()`: Manages auto mode toggle
- `handleAutoMode()`: Executes automatic timing logic

### 🤝 Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

### 🙏 Acknowledgments

- [Blinker Library](https://github.com/blinker-iot/blinker-library) for IoT connectivity
- Xiaomi AI for voice control integration

---

## 中文

### 🔌 项目简介

基于Arduino ESP8266/ESP32的智能继电器控制器，提供WiFi连接、手机App控制和小爱同学语音控制功能。设备支持手动控制和自动定时控制两种模式，适用于各种基于继电器的电气设备控制。

### ✨ 功能特性

- **WiFi连接**：连接家庭WiFi网络
- **手机App控制**：通过点灯Blinker手机应用控制
- **语音控制**：支持小爱同学语音控制
- **双控制模式**：
    - 通过手机App手动控制
    - 自动定时模式，可自定义时间间隔
- **实时状态反馈**：App中实时显示设备状态
- **简易设置**：简单的配置和部署过程

### 🛠 硬件需求

- ESP8266 或 ESP32 开发板
- 继电器模块（兼容3.3V/5V逻辑电平）
- 杜邦线
- 电源适配器（5V/3.3V）
- 可选：面包板用于原型开发

### 📋 引脚配置

| 组件 | 引脚 | 描述 |
|------|------|------|
| 继电器控制 | D0 | 数字输出引脚控制继电器 |

### 🚀 快速开始

#### 1. 硬件连接
1. 将继电器模块连接到ESP板的D0引脚
2. 正确连接电源和地线
3. 确保ESP和继电器模块都有适当的电源供应

#### 2. 软件设置
1. 安装Arduino IDE
2. 安装ESP8266/ESP32板卡包
3. 安装Blinker库：
   ```
   工具 > 管理库 > 搜索"Blinker" > 安装
   ```

#### 3. 配置设置
1. 克隆此仓库：
   ```bash
   git clone https://github.com/yourusername/smart-relay-controller.git
   ```
2. 在Arduino IDE中打开 `smart-relay-controller.ino`
3. 配置您的认证信息：
   ```cpp
   char auth[] = "你的blinker认证密钥";
   char ssid[] = "你的WiFi名称";
   char pswd[] = "你的WiFi密码";
   ```
4. 上传到您的ESP开发板

#### 4. 手机App设置
1. 从应用商店下载点灯Blinker应用
2. 使用认证密钥添加设备
3. 配置控制界面按钮：
    - 手动控制按钮：`btn-on`
    - 自动模式开关：`btn-kg`

### 📱 使用方法

#### 手动控制
- 使用手机App手动开关继电器
- App中实时显示状态反馈

#### 自动模式
- 通过App启用自动模式
- 设备自动循环：开启 → 关闭（2分钟）→ 开启（10分钟）
- 可随时通过App禁用

#### 语音控制
- "小爱同学，打开xxx"
- "小爱同学，关闭xxx"

### 🔧 自定义设置

#### 定时间隔
修改代码中的这些值来改变定时间隔：
```
cpp
unsigned long nextLowTime = 120000;   // 关闭持续时间（2分钟）
unsigned long nextHighTime = 600000;  // 开启持续时间（10分钟）
```
#### 引脚配置
如需要可更改继电器控制引脚：
```
cpp
const int relayPin = D0;  // 改为您需要的引脚
```
### 📝 API参考

#### 主要函数
- `miotPowerState()`：处理小爱同学语音命令
- `manualControlCallback()`：处理手动控制
- `autoModeCallback()`：管理自动模式切换
- `handleAutoMode()`：执行自动定时逻辑

### 🤝 参与贡献

1. Fork 本仓库
2. 创建您的功能分支 (`git checkout -b feature/amazing-feature`)
3. 提交您的更改 (`git commit -m 'Add some amazing feature'`)
4. 推送到分支 (`git push origin feature/amazing-feature`)
5. 打开一个 Pull Request

### 📄 开源许可

本项目采用 MIT 许可证 - 查看 [LICENSE](LICENSE) 文件了解详情。

### 🙏 致谢

- [Blinker库](https://github.com/blinker-iot/blinker-library) 提供物联网连接功能
- 小爱同学提供语音控制集成支持