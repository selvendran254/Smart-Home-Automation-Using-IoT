# Build & Deploy

## Required Hardware
- NodeMCU / ESP8266 module
- DHT11 or DHT22 sensor
- Relay module (1-channel or multi-channel)
- PIR sensor (optional)
- Jumper wires and breadboard
- 5V power supply for relay module

## Software & Libraries
- Arduino IDE
- Add ESP8266 board support (Board Manager)
- Libraries:
  - Blynk
  - ESP8266WiFi
  - PubSubClient (for MQTT)
  - DHT sensor library
  - BlynkTimer (optional)

## Steps
1. Open the appropriate sketch from the `code/` folder (`smart_home_blynk.ino` or `smart_home_mqtt.ino`).
2. Replace credentials (WiFi, Blynk auth, or MQTT broker).
3. Verify and upload the sketch to your NodeMCU.
4. Connect relay and sensors as per `WIRING.md`.
5. For Blynk: create a project in Blynk, add buttons/virtual pins and link to V1, V2, V3.
