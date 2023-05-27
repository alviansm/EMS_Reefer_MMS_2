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

##### Pin number
| *No. PCB* | *No. Var* | *Panjang* |
| ------------- | ------------- | ------------- |
| 1 | 6 | 2 m |
| 2 | 3 | 4 m |
| 3 | 1 | 3 m |
| 4 | 5 | 1 m |
| 5 | 4 | 2 m |
| 6 | 2 | 3 m |
| 7 | 7 | 4 m |
> Info (Berdasarkan No. PCB ):
1. Inlet Kondensor
2. Sampel PCM 1
3. Inlet Evaporator
4. Ambient
5. Inlet Kompresor
6. Inlet TXV
7. Sampel PCM 2

#### DHT21
|*No.*|*Information*|*Value*|
| ------------- | ------------- | ------------- |
|1|Signal Type|Digital|
|2|Pin Connection|8|
|3|Total Sensor|1|
|4|Status|Ok|
|5|Properties|Temperature & Humidity|
|6|Units|Celcius & RH (%)|
#### ZMCT101C
|*No.*|*Information*|*Value*|
| ------------- | ------------- | ------------- |
|1|Signal Type|Analog|
|2|Pin Connection|A7, A8|
|3|Total Sensor|3|
|4|Status|1 Ok, 1 Need calibration|
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
- [X] Sensor humidity -> CHanged, from DHT22 to DHT21
- [X] Sensor current (2) -> Need recallibration
- [X] Modul buzzer (2)
- [X] Module Relay -> Need control functions
- [X] Module microsd
- [X] Module real-time clock
- [X] Module nextion
- [X] Module esp32
- [X] Integration variables
- [X] MicroSD Writing

## Devices Status 
- [ ] Device status trough LED (Skip)

## Functions
- [X] COP calculation
- [X] Power calculation
- [X] Enthalpy conversion calculation
- [X] PCM freezing point
- [X] Pickload

## Sensing Integration
- [X] Relay state
- [X] Sensor variables compilations
- [X] Send sensor variables and relay state variables to internet server
- [X] Sens sensor variables and relay state variables to display