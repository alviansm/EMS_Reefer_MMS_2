#include "sensor-humidity.h"

//Constants
#define DHTPIN A13            //what pin we're connected to
#define DHTTYPE DHT21       //DHT 21  (AM2301)
DHT dht(DHTPIN, DHTTYPE);   //Initialize DHT sensor for normal 16mhz Arduino

//Variables
int hum;  //Stores humidity value
int temp; //Stores temperature value

void setupHumiditySensor() {
    dht.begin();
}

void loopHumiditySensor() {
  //Read data and store it to variables hum and temp
  hum = dht.readHumidity();
  temp= dht.readTemperature();
  
  //Print temp and humidity values to serial monitor
//   Serial.print("Humidity: ");
//   Serial.print(hum);
//   Serial.print("%,  Temperature: ");
//   Serial.print(temp);
//   Serial.println(" Celsius");
  
  senseTemperatureHumid = String(temp);
  senseHumid = String(hum);
}