/*
  Smart Home Automation - MQTT example for NodeMCU (ESP8266)
  - Publishes temperature/humidity to MQTT topics
  - Subscribes to control topic to toggle relay
*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

const char* WIFI_SSID = "YOUR_WIFI_SSID";
const char* WIFI_PASS = "YOUR_WIFI_PASSWORD";
const char* MQTT_SERVER = "broker.hivemq.com"; // example public broker
const int MQTT_PORT = 1883;
const char* MQTT_CLIENT_ID = "NodeMCU_SmartHome_01";
const char* MQTT_TOPIC_TEMP = "smarthome/esp/temp";
const char* MQTT_TOPIC_HUM = "smarthome/esp/hum";
const char* MQTT_TOPIC_CTRL = "smarthome/esp/ctrl";

#define DHTPIN D2
#define DHTTYPE DHT22
#define RELAY_PIN D1

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);

void callback(char* topic, byte* payload, unsigned int length) {
  // simple payload: "ON" or "OFF"
  String msg;
  for (unsigned int i = 0; i < length; i++) msg += (char)payload[i];
  msg.trim();
  if (String(topic) == MQTT_TOPIC_CTRL) {
    if (msg == "ON") digitalWrite(RELAY_PIN, HIGH);
    else if (msg == "OFF") digitalWrite(RELAY_PIN, LOW);
  }
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect(MQTT_CLIENT_ID)) {
      client.subscribe(MQTT_TOPIC_CTRL);
    } else {
      delay(2000);
    }
  }
}

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  client.setServer(MQTT_SERVER, MQTT_PORT);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();

  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (!isnan(t) && !isnan(h)) {
    char tempBuf[16], humBuf[16];
    dtostrf(t, 6, 2, tempBuf);
    dtostrf(h, 6, 2, humBuf);
    client.publish(MQTT_TOPIC_TEMP, tempBuf);
    client.publish(MQTT_TOPIC_HUM, humBuf);
  }
  delay(5000);
}
