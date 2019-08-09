

#include "ThingSpeak.h"
#include <ESP8266WiFi.h>
    char ssid[] = "POCO PHONE";    //  your network SSID (name) 
    char pass[] = "9738553570";   // your network password
    WiFiClient  client;

unsigned long myChannelNumber =768204;
const char * myWriteAPIKey ="KE0JV8ZL1F8PY2DQ";

int red_pin = D0;
int orange_pin = D1;
int green_pin = D6;

int r_status;
int o_status;
int g_status;
String signalid = "BN01";
String f_status;
String final_str;
String concatin1;
String concatin2;

void setup() {
  pinMode(red_pin,INPUT);  
  pinMode(orange_pin,INPUT); 
  pinMode(green_pin,INPUT);
   WiFi.begin(ssid, pass);
  ThingSpeak.begin(client); 
  Serial.begin(9600);
  Serial.println ("hii");  

}                                                                                                                                                                                                                           
void loop() {
 r_status = digitalRead(red_pin);
 o_status = digitalRead(orange_pin);
 g_status = digitalRead(green_pin);
  Serial.println(r_status);
  Serial.println(o_status);
  Serial.println(g_status);
  concatin1 = String(r_status)+String(o_status)+String(g_status);
 delay(5000);
  Serial.println();
  Serial.println(digitalRead(red_pin));
    Serial.println(digitalRead(orange_pin));
      Serial.println(digitalRead(green_pin));

      concatin2 = String(digitalRead(red_pin))+String(digitalRead(orange_pin))+String(digitalRead(green_pin));



Serial.println(concatin1);
Serial.println(concatin2);


 if ( concatin1 == concatin2)
 {
  Serial.println("Faulty Signal");
  f_status = '0';
 }

 else
 {
  f_status= '1';
    Serial.println("Everything is working fine");

 }

  final_str = f_status+signalid;
   Serial.println(  final_str);
   ThingSpeak.writeField(myChannelNumber, 1, final_str, myWriteAPIKey);
  delay(20000); // ThingSpeak will only accept updates every 15 seconds.


}

