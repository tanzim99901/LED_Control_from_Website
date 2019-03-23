// OTHER FUNCTIONS ON THE wifi.ino FILE

#include "SoftwareSerial.h"

#define R_switch 3  // stop switch
#define F_switch 4  // start switch

String ssid = "Zeus";     // your network SSID

String password = "google123456";     // your network password

SoftwareSerial esp(10, 11);// (RX of Arduino, TX of Arduino)

String data;
String on_off;

String server = "tanzim99901.atwebpages.com"; // host website

String get_html = "/value.html"; // html file from where the Switch state has to be read

int whitepin = 5;   // status indicator LED
int bluepin = 6;    // status indicator LED
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
  while (digitalRead(F_switch));    // WAIT FOR THE START SWITCH
  
  esp.begin(9600);
  digitalWrite(redpin, HIGH);
  delay(100);
  digitalWrite(redpin, LOW);
  reset();      // RESET MODULE

  connectWifi();    // CONNECT TO WIFI
  Serial.println("DONE CONNECTION!");
}

void loop ()
{
  // STOP SWITCH
  if (!digitalRead(R_switch))
  {
    digitalWrite(whitepin, LOW);
    digitalWrite(bluepin, LOW);
    digitalWrite(redpin, LOW);
    reset();
    play = 0;
    Serial.println("STOP");
  }
  
  if (play)
  {
    httpget();    // MAIN FUNCTION
    Serial.println("DATA READ");
    delay(1000);
    //httppost();
    digitalWrite(whitepin, LOW);
  }
}








