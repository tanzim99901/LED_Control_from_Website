void httpget ()
{

  esp.println("AT+CIPSTART=\"TCP\",\"" + server + "\",80");//start a TCP connection.

  if ( esp.find("OK")) {

    Serial.println("TCP connection ready");

  } delay(100);

  String getRequest = "GET " + get_html + " HTTP/1.0\r\nHost:" + server + "\r\n\r\n\r\n\r\n\r\n";
  String sendCmd = "AT+CIPSEND=";
  sendCmd += getRequest.length();
  sendCmd += "\r\n";
  esp.println(sendCmd);
  delay(100);

  if (esp.find(">")) {
    Serial.println("Sending..");
    esp.print(getRequest);

    if ( esp.find("SEND OK")) {
      Serial.println("Packet sent");
      String tmpResp, tmpFin;
      while (esp.available()) 
      {
        tmpResp = esp.readString();
      }
      tmpFin = tmpResp.substring(241, tmpResp.length());
      int closed = tmpFin.indexOf('C');
      tmpFin = tmpResp.substring(241, 241 + closed);
      Serial.println(tmpFin);
      if (tmpFin.indexOf('1') != -1) 
      {
        digitalWrite(redpin, HIGH);
        on_off = "1";
      }
      else if (tmpFin.indexOf('0') != -1) 
      {
        digitalWrite(redpin, LOW);
        on_off = "0";
      }
      //Serial.println(tmpResp);
      //Serial.println(tmpResp.length());
      digitalWrite(whitepin, HIGH);
      
      // close the connection

      esp.println("AT+CIPCLOSE");
      delay(100);
    }
  }
}


//reset the esp8266 module

void reset() {

  esp.println("AT+RST\r\n");

  delay(1000);

  if (esp.find("OK") ) Serial.println("Module Reset");
  delay(1000);
  esp.println("AT+CWMODE=3\r\n");
  if (esp.find("OK") ) Serial.println("Mode changed");
  delay(1000);
}

//connect to your wifi network

void connectWifi() {

  String cmd = "AT+CWJAP=\"" + ssid + "\",\"" + password + "\"";

  esp.println(cmd);

  delay(4000);

  if (esp.find("OK")) {

    Serial.println("Connected!");
    connection = 1;
    digitalWrite(bluepin, HIGH);
  }

  else {
    Serial.println("Cannot connect to wifi");
    connection = 0;
    digitalWrite(bluepin, LOW);
  }
  if (!connection)
  {
    connectWifi();
  }
}
