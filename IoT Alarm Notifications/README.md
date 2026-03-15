# IoT Door Security System with ESP32-S3

This project is an IoT-based security system that detects door movement using an ultrasonic sensor and sends real-time notifications via a Telegram Bot.

## Components
* ESP32-S3
* HC-SR04 Ultrasonic Sensor
* Jumper Wires & Breadboard

## How it Works
1. The HC-SR04 measures the distance to the door.
2. If the distance exceeds a certain threshold (e.g., door opens), the ESP32 connects to Wi-Fi.
3. It triggers the Telegram API to send a security alert to the user.

## Libraries Used
* UniversalTelegramBot
* ArduinoJson
