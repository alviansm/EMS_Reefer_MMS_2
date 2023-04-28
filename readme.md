# Project Information

## Devince Routing Information
Notes: ***Power connection not included, 5 V for modules and sensors***
### Sensors
#### DS18B20
|*No.*|*Information*|*Value*|
| ------------- | ------------- | ------------- |
|1|Signal Type|Digital|
|2|Pin connection|4|
|3|Total Sensor|7|
|4|Status|OK|
|5|Properties Sensing|Temperature|
|6|Unit|Celcius|
#### DHT21
|*No.*|*Information*|*Value*|
| ------------- | ------------- | ------------- |
|1|Signal Type|Digital|
|2|Pin Connection|8|
|3|Total Sensor|1|
|4|Status||
|5|Properties|Temperature & Humidity|
|6|Units|Celcius & RH (%)|
#### ZMCT101C
|*No.*|*Information*|*Value*|
| ------------- | ------------- | ------------- |
|1|Signal Type|Analog|
|2|Pin Connection|A7, A8|
|3|Total Sensor|3|
|4|Status||
|5|Properties|Current|
|6|Units|mA|
### Modules
#### 6-Channel Relay
|*No.*|*Information*|*Value*|
| ------------- | ------------- | ------------- |
|1|Signal Type|Digital|
|2|Pin Connection|34, 35, 36, 37, 38, 39|
#### SD Card Module
|*No.*|*Arduino*|*Module*|
| ------------- | ------------- | ------------- |
|1|CS|53|
|2|MISO|50|
|3|MOSI|51|
|4|CLK|52|
#### RTC Module - DS1307
|*No.*|*Arduino*|*Module*|
| ------------- | ------------- | ------------- |
|1|SCL|21|
|2|SDA|20|
### Buzzer
|*No.*|*Information*|*Value*|
| ------------- | ------------- | ------------- |
|1|Signal Type|Digital|
|2|Pin Connection|5|
#### Nextion Display
|*No.*|*Arduino*|*Module*|
| ------------- | ------------- | ------------- |
|1|2 (RX)|TX|
|2|3 (TX)|RX|
#### ESP32
|*No.*|*Arduino*|*Module*|
| ------------- | ------------- | ------------- |
|1|12 (TX)|17 (RX)|
|2|13 (RX)|16 (TX)|
#### LED Indicator (3.3 V)
|*No.*|*Arduino*|*Indicating*|
| ------------- | ------------- | ------------- |
|1|41|DS18B20|
|2|42|DHT22|
|3|43|ZMCT101C|
|4|44|ZMPT101B|
|5|45|SD Card Module|
|6|46|RTC Module|
|7|47|ESP32 Board|
|8|48|5V Buzzer|
|9|49|Relay Module|

# ToDos
## Clean Code (Split) | Module & Sensor Integration
- [X] Sensor Temperature
- [ ] Sensor humidity
- [X] Sensor current (2) -> Need recallibration
- [X] Modul buzzer (2)
- [X] Module Relay -> Need control functions
- [X] Module microsd
- [X] Module real-time clock
- [X] Module nextion
- [ ] Module esp32
- [X] Integration variables
- [X] MicroSD Writing

## Devices Status 
- [ ] Device status trough LED

## Functions
- [ ] COP calculation
- [ ] Power calculation
- [ ] Enthalpy conversion calculation
- [ ] PCM freezing point
- [ ] Pickload

## Sensing Integration
- [ ] Relay state
- [ ] Sensor variables compilations
- [ ] Send sensor variables and relay state variables to internet server
- [ ] Sens sensor variables and relay state variables to display