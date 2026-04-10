/*------------------------------------------------------------------
  ===================  Seksyen 1 - HEADER        ===================
  ------------------------------------------------------------------*/

//-------------------------------------------------------------------
//=  A. - Library  include and define  yang diperlukan              =
//-------------------------------------------------------------------


#include <WiFi.h>
#include <MQTT.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"

//--------------------------------------------------------------------------
//-----b. - ISTIHAR Sambungan nama Pin dengan Nombor Fizikal PIN ----
//--------------------------------------------------------------------------


#define relay01     6  // digital OUTPUT - RELAY 1
#define relay02     7  // digital OUTPUT - RELAY 2
#define buzzer      3  // digital OUTPUT - BUZZER
#define sensorLDR   4  // analog INPUT   - Sensor Cahaya
#define sensorTEMT  2
#define sensorLine   1
#define DHTPIN      5    
#define DHTTYPE DHT22


//---Penentuan Saiz Skrin OLED --
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


DHT dht(DHTPIN, DHTTYPE);


// Istihar objek bagi Module OLED Display - SSD1306
Adafruit_SSD1306 paparOled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


//##################  Seksyen 1 - TAMAT #############################
//--------------FUNCTION----------------------------



void setup() {
  pinMode(relay01,OUTPUT);
  pinMode(relay02,OUTPUT);
  pinMode(buzzer,OUTPUT);
  
  Serial.begin(115200); // initialize serial




  dht.begin();


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




}
//##################  Seksyen 2 - TAMAT #############################


//==============  Seksyen 3 - Fungsi Utama (LOOP) ===================
//-------------------------------------------------------------------
void loop() {

   //------SENSOR 1 -------------------------------------------------------------
   
  int dataLDR = analogRead(sensorLDR);
  Serial.print("Cahaya: ");
  Serial.println(dataLDR);  


 //------SENSOR 2 -------------------------------------------------------------
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();


  Serial.print("Humidity: ");
  Serial.println(humid);
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println("°C ");
  
  //------SENSOR TEMP6000 -------------------------------------------------------------

  int sensorCahaya = analogRead(sensorTEMT);
  Serial.print("Nilai Raw: ");
  Serial.println(sensorCahaya);

//------SENSOR LINE -------------------------------------------------------------

  int dataSensorLine = analogRead(sensorLine);
  Serial.print("Nilai IR: ");
  Serial.println(dataSensorLine);


  //------RELAY 1 & 2 -------------------------------------------------------------
 digitalWrite(relay01,HIGH);
 delay(300);
 digitalWrite(relay02,HIGH);
 delay(300);
 digitalWrite(buzzer,HIGH);
 delay(300);
 digitalWrite(relay01,LOW);
 digitalWrite(relay02,LOW);
 digitalWrite(buzzer,LOW);


 //------DISPLAY OLED   -----------------------------------------------------------


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
  paparOled.setCursor(0,30);
  paparOled.print("Humidity: ");
  paparOled.print(humid);
  paparOled.setCursor(0,40);
  paparOled.print("Temperature: ");
  paparOled.print(temp);
  paparOled.print(" C ");
  paparOled.display();
 //-----------end ----------------------------------


  }



//##################  Seksyen 3 - TAMAT #############################
