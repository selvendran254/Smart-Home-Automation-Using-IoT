# Smart Home Automation Using IoT

**Smart Home Automation Using IoT** is a beginner-to-intermediate project that demonstrates remote control and monitoring of home appliances using an ESP8266 (NodeMCU), sensors, relay modules and cloud connectivity (Blynk or MQTT). This repository contains source code, wiring guide, and documentation so you can quickly build and customize your own smart home system.

## Features
- Remote control of appliances from mobile app (Blynk) or MQTT dashboard
- Temperature & humidity monitoring (DHT11/DHT22)
- Motion detection (PIR) support for automation
- Relay control for switching AC/DC loads (through proper relay module)
- Simple automation rules (e.g., turn ON fan if temperature > threshold)
- Expandable: add more sensors and actuators

## Tech Stack
- Hardware: ESP8266 (NodeMCU), DHT11/DHT22, PIR sensor, Relay module
- Software: Arduino IDE, Blynk (or any MQTT broker)
- Optional: Home Assistant / Node-RED integration via MQTT

## Repository Structure
```
Smart-Home-Automation-IoT/
├── code/
│   ├── smart_home_blynk.ino
│   └── smart_home_mqtt.ino
├── docs/
│   ├── BUILD.md
│   └── WIRING.md
├── images/
│   └── wiring_diagram.png
├── .gitignore
├── LICENSE
└── README.md
```

## Quick Start (Blynk)
1. Install Arduino IDE and the following libraries:
   - ESP8266WiFi
   - Blynk (BlynkSimpleEsp8266)
   - DHT sensor library (DHT)
2. Copy `code/smart_home_blynk.ino` into Arduino IDE.
3. Replace the `BLYNK_AUTH`, `WIFI_SSID`, and `WIFI_PASS` constants with your credentials.
4. Upload to NodeMCU, open mobile Blynk app and add Virtual Pins as used in the sketch.
5. Power your relay module from an appropriate power source and never power AC loads directly from the NodeMCU.

## Quick Start (MQTT)
1. Install Arduino IDE and libraries:
   - ESP8266WiFi
   - PubSubClient
   - DHT
2. Configure MQTT broker settings in `smart_home_mqtt.ino` and upload.

## Safety Notes
- Do NOT connect mains AC loads directly to the microcontroller. Use a properly rated relay module with isolation.
- If you are not experienced with mains wiring, seek professional help.

## License
This project is released under the MIT License. See `LICENSE` for details.
