#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

const char *ssid = ".........";
const char *password = ".........";

const char * url = ".........";

void setup() 
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }  

  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  HTTPClient http;

  http.begin(url);

  int httpCode = http.GET();

  if (httpCode > 0) {
    if (httpCode == HTTP_CODE_OK) {
      Serial.println(http.getString());
    }
  }else{
    Serial.println("HTTP error: " + httpCode);
  }
}

void loop() 
{
  
}
