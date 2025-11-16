/*
  Smart Home Automation - Blynk example for NodeMCU (ESP8266)
  - DHT sensor (temperature + humidity)
  - Relay control via Virtual Pin V1
  - Temperature pushed to V2, Humidity to V3
  - Simple automation: if temp > THRESHOLD, turn on relay
*/

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// ====== CONFIGURATION ======
char BLYNK_AUTH[] = "YOUR_BLYNK_AUTH_TOKEN";
char WIFI_SSID[] = "YOUR_WIFI_SSID";
char WIFI_PASS[] = "YOUR_WIFI_PASSWORD";

#define DHTPIN D2        // D2 on NodeMCU (GPIO4)
#define DHTTYPE DHT22    // DHT22 or DHT11
#define RELAY_PIN D1     // D1 (GPIO5)
#define PIR_PIN D5       // D5 (GPIO14) optional
#define TEMP_THRESHOLD 30.0

DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

// ====== BLYNK HANDLERS ======
BLYNK_WRITE(V1) {
  int state = param.asInt(); // 1 or 0
  digitalWrite(RELAY_PIN, state);
}

void sendSensorReadings() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan(t) || isnan(h)) {
    // read failed
    return;
  }
  Blynk.virtualWrite(V2, t);
  Blynk.virtualWrite(V3, h);

  // Simple automation
  if (t > TEMP_THRESHOLD) {
    digitalWrite(RELAY_PIN, HIGH);
    Blynk.virtualWrite(V1, 1);
  }
}

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  pinMode(PIR_PIN, INPUT);

  Serial.begin(115200);
  dht.begin();
  Blynk.begin(BLYNK_AUTH, WIFI_SSID, WIFI_PASS);

  timer.setInterval(5000L, sendSensorReadings); // every 5 seconds
}

void loop() {
  Blynk.run();
  timer.run();
}
