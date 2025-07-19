# 🔧 ESP-NOW Motion Detection System with PIR Sensor

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/f6/PIR_motion_detector_module.jpg/640px-PIR_motion_detector_module.jpg" width="350" />
  <br/><em>Reliable Wireless Motion Detection System using ESP32 + PIR + ESP-NOW</em>
</p>

---

## 📡 Project Overview

This project demonstrates a **wireless motion detection** system built on the **ESP32 microcontroller platform**, utilizing:

- **Passive Infrared (PIR) sensor** for detecting motion.
- **ESP-NOW** protocol for low-latency, peer-to-peer communication between ESP32 devices.
- **Onboard LED indicator** for real-time visual feedback.

One ESP32 acts as the **transmitter**, detecting motion and sending the alert. Another ESP32 acts as the **receiver**, which can be extended to control alarms, lights, or log data.

---

## 🧰 Hardware Components

| Component                | Quantity | Description                                     |
|--------------------------|----------|-------------------------------------------------|
| ESP32 Dev Module         | 2        | One for transmitter, one for receiver          |
| PIR Motion Sensor        | 1        | HC-SR501 or equivalent                         |
| LED                      | 1        | Visual feedback on motion                      |
| Jumper Wires             | -        | For connections                                |
| Breadboard (optional)    | 1        | For prototyping                                |

---

## 📐 System Architecture

