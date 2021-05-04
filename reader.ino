#include "WiFi.h"
// set pin numbers
const int inputPin = 4;  // input pin
const int outPin =  5;    // output pin

int state = 0;

void setup() {
  Serial.begin(115200);  
  pinMode(inputPin, INPUT);
  pinMode(outPin, OUTPUT);
}

void loop() {
  state = digitalRead(inputPin);
  Serial.println(state);
  if (state == HIGH) {
    Serial.println("scan start");
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    if (n == 0) {
        Serial.println("no networks found");
    } else {
      Serial.print(n);
      Serial.println(" networks found");
      for (int i = 0; i < n; ++i) {
        // Print SSID and RSSI for each network found
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.print(WiFi.SSID(i));
        Serial.print(" (");
        Serial.print(WiFi.RSSI(i));
        Serial.print(")");
        Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
        delay(10);
      }
    }
    Serial.println("");
    delay(5000);
    digitalWrite(outPin, HIGH);
  } else {
    digitalWrite(outPin, LOW);
  }
}
