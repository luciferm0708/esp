# 🔧 ESP-NOW Motion Detection System with PIR Sensor

<p align="center">
  <img src="https://media.giphy.com/media/YTBj5drpNZF04/giphy.gif" width="250" alt="Motion Sensor Animation"/>
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/f6/PIR_motion_detector_module.jpg/640px-PIR_motion_detector_module.jpg" width="250" alt="PIR Sensor"/>
  <br>
  <strong>⚡️ Wireless Motion Detection using ESP32 + PIR + ESP-NOW</strong>
</p>

<p align="center">
  <img alt="Platform" src="https://img.shields.io/badge/platform-ESP32-blue">
  <img alt="Protocol" src="https://img.shields.io/badge/protocol-ESP--NOW-critical">
  <img alt="License" src="https://img.shields.io/github/license/yourusername/espnow-motion-detector">
  <img alt="Made With" src="https://img.shields.io/badge/Made%20With-C%2B%2B-green">
</p>

---

## 🚀 Project Overview

This project is a **robust wireless motion detection system** built with **ESP32** development boards. It features:

- 📡 **ESP-NOW Protocol**: Low-power, fast communication between ESP32s.
- 👁️ **PIR Sensor**: Detects motion using infrared heat signatures.
- 💡 **LED Indicator**: Lights up when motion is detected.
- 🔀 **Transmitter & Receiver**: One ESP32 detects, the other acts on it (alert, log, control).

This setup is ideal for home automation, security systems, and IoT-based monitoring.

---

## 🛠️ Hardware Requirements

| Component             | Quantity | Purpose                                   |
|-----------------------|----------|-------------------------------------------|
| 🔲 ESP32 Dev Board     | 2        | One for Transmitter, one for Receiver     |
| 👁️ PIR Sensor (HC-SR501)| 1        | Detects human motion                      |
| 💡 LED                | 1        | Visual motion alert on transmitter        |
| 🔌 Jumper Wires        | As needed | Electrical connections                    |
| ⛏️ Breadboard (Optional)| 1        | Rapid prototyping                         |

---

## ⚙️ System Architecture

```plaintext
[🏠 Environment] → [👁️ PIR Sensor] → [📡 ESP32-TX] → (ESP-NOW) → [📡 ESP32-RX] → [🔔 Action / Logging / Alert]
