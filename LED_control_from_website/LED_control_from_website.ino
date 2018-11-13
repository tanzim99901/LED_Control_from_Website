#include "SoftwareSerial.h"
#include <OneWire.h>
#define R_switch 3  // stop switch
#define F_switch 4  // start switch

String ssid = "Zeus";

String password = "google123456";

SoftwareSerial esp(10, 11);// RX, TX

String data;
String on_off;

String server = "tanzim99901.atwebpages.com"; // host website

String get_html = "/value.html"; // html file from where the Switch state has to be read

int whitepin = 5;
int bluepin = 6;
int redpin = 7; // this LED will be controlled from the website

boolean connection = 0;

String go;
boolean play = 1;

void setup() {
  pinMode(R_switch, INPUT);
  pinMode(F_switch, INPUT);
  pinMode (whitepin, OUTPUT);
  pinMode (bluepin, OUTPUT);
  pinMode (redpin, OUTPUT);

  digitalWrite(whitepin, LOW);
  digitalWrite(bluepin, LOW);
  digitalWrite(redpin, LOW);
  on_off = "0";
  Serial.begin(115200);
  while (digitalRead(F_switch));
  esp.begin(9600);
  digitalWrite(redpin, HIGH);
  delay(100);
  digitalWrite(redpin, LOW);
  reset();

  connectWifi();
  Serial.println("DONE CONNECTION!");
}

void loop () 
{
  if (!digitalRead(R_switch))
  {
    digitalWrite(redpin, LOW);
    digitalWrite(bluepin, LOW);
    digitalWrite(redpin, LOW);
    reset();
    play = 0;
    Serial.println("STOP");
  }
  if (play)
  {
    httpget();
    Serial.println("DATA READ");
    delay(1000);
    //httppost();
    digitalWrite(whitepin, LOW);
  }
}








