  1
  2
  3
  4
  5
  6
  7
  8
  9
 10
 11
 12
 13
 14
 15
 16
 17
 18
 19
 20
 21
 22
 23
 24
 25
 26
 27
 28
 29
 30
 31
 32
 33
 34
 35
 36
 37
 38
 39
 40
 41
 42
 43
 44
 45
 46
 47
 48
 49
 50
 51
 52
 53
 54
 55
 56
 57
 58
 59
 60
 61
 62
 63
 64
 65
 66
 67
 68
 69
 70
 71
 72
 73
 74
 75
 76
 77
 78
# Edu-IoT-C# Learning IoT Board

Panduan Edu-IoT-C3

## Rujukan Pin

#### Jadual

```http
Jadual PIN Sambungan GPIO
```

| Input     | Nombor GPIO Pin     | Aktuator/Sensor      |
| :-------- | :-------            | :------------------- |
| LED1      |  `06`               | **LED 1**            |
| LED2      |  `07`               | **LED 2**            |
| LED3      |  `10`               | **LED 3**            |
| SW2       |  `04`               | **SW Active LOW**    |
| SW4       |  `03`               | **SW Active HIGH**   |
| Buzzer    |  `00`               | **Buzzer(bunyi)**    |
| DHT       |  `05`               | **Suhu dan Humid**   |
| LDR       |  `02`               | ** LDR **            |
| VR        |  `01`               | ** Potentiometer**   |
| OLED      |  `SDA`              | **OLED LED**         |
| OLED      |  `SCL`              | **OLED LED**         |
| Trigger   |  `20`                | **Ultrasonic**       |
| Echo      |  `21`                | **Ultrasonic**       |



# SENSOR DHT22 (AM2301) - baca suhu dan humiditi
## Section 1: Header
```
#include "DHT.h"
```

```
#define DHTPIN 4     
#define DHTTYPE DHT21

DHT dht(DHTPIN, DHTTYPE);
```
## Section 2 : void setup
```
dht.begin();
```
## Section 3 : void loop
```
float humid = dht.readHumidity();
float temp = dht.readTemperature();

Serial.print("Humidity: ");
Serial.println(humid);
Serial.print("Temperature: ");
Serial.print(temp);
Serial.println("°C ");

```
```
#include "DHT.h"
```

```
#define DHTPIN 4     
#define DHTTYPE DHT21

DHT dht(DHTPIN, DHTTYPE);
```
## Section 2 : void setup
```
dht.begin();
```
## Section 3 : void loop
```
float humid = dht.readHumidity();
float temp = dht.readTemperature();

Serial.print("Humidity: ");
Use Control + Shift + m to toggle the tab key moving focus. Alternatively, use esc then tab to move to the next interactive element on the page.
No file chosen
Attach files by dragging & dropping, selecting or pasting them.
