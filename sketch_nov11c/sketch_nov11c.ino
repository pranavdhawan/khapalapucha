#include "DHT.h"
#include <SPI.h>
#include <Wire.h>
#include "RTClib.h"
#include "SD.h"
#define DHTTYPE DHT22
#define ECHO_TO_SERIAL 1 
#define LOG_INTERVAL 360000 


//DHT dht(dhtPin, DHTTYPE);
//RTC_DS1307 rtc;

// code for pins here
//

float soilTemp = 0; 
float soilMoistureRaw = 0; 
float soilMoisture = 0; 
float humidity = 0; 
float airTemp = 0; 
float heatIndex = 0; 
float sunlight = 0; 
bool watering = false;
bool wateredToday = false;
DateTime now;
File logfile;


void error(char *str)
{
  Serial.print("error: ");
  Serial.println(str);
  
  // red LED indicates error
  digitalWrite(LEDPinRed, HIGH);
  
  while(1);
}
