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
Serial.println(humid);
Serial.print("Temperature: ");
Serial.print(temp);
Serial.println("°C ");

```
# DIGITAL SENSOR INPUT

## Section 3 : void loop - baca semua jenis analog sensor
### Contoh switch INPUT
```
int dataSW2 = digitalRead(sw2);
Serial.print("SW2: ");
Serial.println(dataSW2);  
```

# ANALOG SENSOR INPUT

## Section 3 : void loop - baca semua jenis analog sensor
### Contoh analog sensor LDR
```
int dataLDR = analogRead(sensorLDR);
Serial.print("Cahaya: ");
Serial.println(dataLDR); 
```

# ULTRASONIC
## Section 1: Header
```
#include <Adafruit_SSD1306.h>

#define TRIG_PIN 20
#define ECHO_PIN 21

long duration;
float distance;
```
## Section 2 : void setup
```
pinMode(TRIG_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);

```
## Section 3 : void loop
```
digitalWrite(TRIG_PIN, LOW);
delayMicroseconds(2);

digitalWrite(TRIG_PIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG_PIN, LOW);

duration = pulseIn(ECHO_PIN, HIGH, 30000);
distance = duration * 0.0343 / 2;

Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");
```

# OLED DISPLAY
## Section 1: Header
```
#include <Adafruit_SSD1306.h>
```

```
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 paparOled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
```
## Section 2 : void setup
```
 if(!paparOled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  paparOled.clearDisplay();
  paparOled.setTextSize(1);
  paparOled.setTextColor(WHITE);
  paparOled.setCursor(0,0);
  paparOled.println("--- ESP32C3- MINI ---");
  paparOled.setCursor(0,10);
  paparOled.println("K. Komuniti Sbg Jaya");
  paparOled.setCursor(0,20);
  paparOled.println("--------------------");
  paparOled.display();
  delay(3000);

```
## Section 3 : void loop
```
 paparOled.clearDisplay();
  paparOled.setTextSize(1);
  paparOled.setTextColor(WHITE);
  paparOled.setCursor(0,0);
  //paparOled.println("--- ESP32C3- MINI ---");
  paparOled.println("--  EduIot-Esp32C3 --");
   paparOled.setCursor(0,10);
  paparOled.println("--------------------");
  // ---- display Humidity 
  paparOled.setCursor(0,20);
  paparOled.print("HUM:");
  paparOled.print(humid,0);
  paparOled.print(" %");
  // ---- display Temperature 
  paparOled.setCursor(60,20);
  paparOled.print("TMP:");
  paparOled.print(temp,0);
  paparOled.print(" C");
  // ---- display Light intensity 
  paparOled.setCursor(0,30);
  paparOled.print("LDR:");
  paparOled.print(dataLDR);

  paparOled.setCursor(60,30);
  paparOled.print("ANG:");
  paparOled.print(dataVR);

  paparOled.setCursor(0,40);
  paparOled.print("Jarak:");
  paparOled.print(distance,1);
  paparOled.print(" cm");

  paparOled.setCursor(0,50);
  paparOled.print("SW2:");
  paparOled.print(dataSW2);
  paparOled.setCursor(40,50);
  paparOled.print("SW4:");
  paparOled.print(dataSW4);
 paparOled.display();
```

