/*
    Blynk: 4 Channel Relay Status Sync with Blynk App, Relay and with Push Button
    Source: https://github.com/pkarun/Blynk-Relay-Status-Sync-with-Physical-Button
    Reference: https://community.blynk.cc/t/turn-on-off-4-lights-using-4-physical-buttons-and-blynk/24927/16?u=pkarun

*/



//#define BLYNK_PRINT Serial           // Uncomment for debugging 

#include "settings.h"           
#include "secret.h"                   // <<--- UNCOMMENT this before you use and change values on config.h tab
//#include "my_secret.h"              // <<--- COMMENT-OUT or REMOVE this line before you use. This is my personal settings.

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include <ESP8266mDNS.h>  // For OTA with ESP8266
#include <WiFiUdp.h>  // For OTA
#include <ArduinoOTA.h>  // For OTA


BlynkTimer timer;

void checkPhysicalButton();

int relay1State = LOW;
int pushButton1State = HIGH;

int relay2State = LOW;
int pushButton2State = HIGH;

int relay3State = LOW;
int pushButton3State = HIGH;

int relay4State = LOW;
int pushButton4State = HIGH;

// Every time we connect to the cloud...

BLYNK_CONNECTED() {

  // Request the latest state from the server

  Blynk.syncVirtual(VPIN_BUTTON_1);
  Blynk.syncVirtual(VPIN_BUTTON_2);
  Blynk.syncVirtual(VPIN_BUTTON_3);
  Blynk.syncVirtual(VPIN_BUTTON_4);

  // Alternatively, you could override server state using:
  //Blynk.virtualWrite(VPIN_BUTTON_1, relay1State);
  //Blynk.virtualWrite(VPIN_BUTTON_2, relay2State);
  //Blynk.virtualWrite(VPIN_BUTTON_3, relay3State);
  //Blynk.virtualWrite(VPIN_BUTTON_4, relay4State);

}

// When App button is pushed - switch the state

BLYNK_WRITE(VPIN_BUTTON_1) {
  relay1State = param.asInt();
  digitalWrite(RELAY_PIN_1, relay1State);
}

BLYNK_WRITE(VPIN_BUTTON_2) {
  relay2State = param.asInt();
  digitalWrite(RELAY_PIN_2, relay2State);
}
BLYNK_WRITE(VPIN_BUTTON_3) {
  relay3State = param.asInt();
  digitalWrite(RELAY_PIN_3, relay3State);
}
BLYNK_WRITE(VPIN_BUTTON_4) {
  relay4State = param.asInt();
  digitalWrite(RELAY_PIN_4, relay4State);
}

void checkPhysicalButton()
{
  if (digitalRead(PUSH_BUTTON_1) == LOW) {
    // pushButton1State is used to avoid sequential toggles
    if (pushButton1State != LOW) {

      // Toggle Relay state
      relay1State = !relay1State;
      digitalWrite(RELAY_PIN_1, relay1State);

      // Update Button Widget
      Blynk.virtualWrite(VPIN_BUTTON_1, relay1State);
    }
    pushButton1State = LOW;
  } else {
    pushButton1State = HIGH;
  }

  if (digitalRead(PUSH_BUTTON_2) == LOW) {
    // pushButton2State is used to avoid sequential toggles
    if (pushButton2State != LOW) {

      // Toggle Relay state
      relay2State = !relay2State;
      digitalWrite(RELAY_PIN_2, relay2State);

      // Update Button Widget
      Blynk.virtualWrite(VPIN_BUTTON_2, relay2State);
    }
    pushButton2State = LOW;
  } else {
    pushButton2State = HIGH;
  }

  if (digitalRead(PUSH_BUTTON_3) == LOW) {
    // pushButton3State is used to avoid sequential toggles
    if (pushButton3State != LOW) {

      // Toggle Relay state
      relay3State = !relay3State;
      digitalWrite(RELAY_PIN_3, relay3State);

      // Update Button Widget
      Blynk.virtualWrite(VPIN_BUTTON_3, relay3State);
    }
    pushButton3State = LOW;
  } else {
    pushButton3State = HIGH;
  }

  if (digitalRead(PUSH_BUTTON_4) == LOW) {
    // pushButton4State is used to avoid sequential toggles
    if (pushButton4State != LOW) {

      // Toggle Relay state
      relay4State = !relay4State;
      digitalWrite(RELAY_PIN_4, relay4State);

      // Update Button Widget
      Blynk.virtualWrite(VPIN_BUTTON_4, relay4State);
    }
    pushButton4State = LOW;
  } else {
    pushButton4State = HIGH;
  }
}

void setup()
{

  Serial.begin(115200);
  Blynk.begin(AUTH, WIFI_SSID, WIFI_PASS, SERVER, PORT);
  ArduinoOTA.setHostname(OTA_HOSTNAME);  // For OTA - Use your own device identifying name
  ArduinoOTA.begin();  // For OTA

  pinMode(RELAY_PIN_1, OUTPUT);
  pinMode(PUSH_BUTTON_1, INPUT_PULLUP);
  digitalWrite(RELAY_PIN_1, relay1State);


  pinMode(RELAY_PIN_2, OUTPUT);
  pinMode(PUSH_BUTTON_2, INPUT_PULLUP);
  digitalWrite(RELAY_PIN_2, relay2State);


  pinMode(RELAY_PIN_3, OUTPUT);
  pinMode(PUSH_BUTTON_3, INPUT_PULLUP);
  digitalWrite(RELAY_PIN_3, relay3State);


  pinMode(RELAY_PIN_4, OUTPUT);
  pinMode(PUSH_BUTTON_4, INPUT_PULLUP);
  digitalWrite(RELAY_PIN_4, relay4State);

  // Setup a function to be called every 100 ms
  timer.setInterval(500L, checkPhysicalButton);
}

void loop()
{
  Blynk.run();
  ArduinoOTA.handle();  // For OTA
  timer.run();
}
