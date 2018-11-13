#include <SoftwareSerial.h>

SoftwareSerial SoftSerial(10, 11);  //RX,TX
char ssid[] = "Zeus";            // your network SSID (name)
char pass[] = "google123456";        // your network password
#define default_baud_rate 9600  // set this as the default baud rate of the ESP8266 module  
String target_baud_rate = "9600"; // set this as the baud rate you want to change into
int target;

void setup()
{
  // Setup WiFI
  Serial.begin(9600);
  target  = target_baud_rate.toInt();
  // initialize serial for ESP module
  SoftSerial.begin(default_baud_rate);
  while(!Serial.available();
  SoftSerial.println("AT+RST");
  Serial.println("AT+RST");
  char value;
  while (SoftSerial.available()) {
    value = SoftSerial.read();
    Serial.println(value);

  }
  SoftSerial.println(F("AT"));
  Serial.println(F("AT"));
  delay(1000);

  while (SoftSerial.available()) {
    value = SoftSerial.read();
    Serial.println(value);

  }

  // Baud rates above about 38,000 do not work reliably on the 328p (Pro Mini)
  Serial.println("AT+UART_DEF=" + target_baud_rate + ",8,1,0,0");
  SoftSerial.println("AT+UART_DEF=" + target_baud_rate + ",8,1,0,0");
  delay(1000);


  while (SoftSerial.available()) {
    value = SoftSerial.read();
    Serial.println(value);

  }
  // Restart SoftwareSerial for the slower baud rate for the WiFi

  SoftSerial.end();
  SoftSerial.begin(target);

}

void loop()
{
  
}




