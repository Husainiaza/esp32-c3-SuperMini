/*------------------------------------------------------------------
  ===================  Seksyen 1 - HEADER        ===================
  ------------------------------------------------------------------*/

//-------------------------------------------------------------------
//=  A. - Library  include and define  yang diperlukan              =
//-------------------------------------------------------------------

#include <Adafruit_SSD1306.h>
#include "DHT.h"

//--------------------------------------------------------------------------
//-----b. - ISTIHAR Sambungan nama Pin dengan Nombor Fizikal PIN ----
//--------------------------------------------------------------------------

#define relay01     6  // digital OUTPUT - RELAY 1
#define relay02     7  // digital OUTPUT - RELAY 2
#define led3        10  // digital OUTPUT - RELAY 2
#define buzzer      0  // digital OUTPUT - BUZZER
#define sensorLDR   2  // analog INPUT   - Sensor Cahaya
#define sensorVR    1  // analog INPUT   - Sensor Cahaya
#define DHTPIN      5     
#define DHTTYPE DHT22

//---Penentuan Saiz Skrin OLED --
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels


//-----d. - Cipta Objek dari Librari berkaitan------------------ ----
//--------------------------------------------------------------------------

// Istihar objek bagi Module DHT
DHT dht(DHTPIN, DHTTYPE);

// Istihar objek bagi Module OLED Display - SSD1306
Adafruit_SSD1306 paparOled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


//##################  Seksyen 1 - TAMAT #############################


//###################################################
//==================  Seksyen 2 - Fungsi Setup ======================
//-------------------------------------------------------------------

void setup() {
  pinMode(relay01,OUTPUT);
  pinMode(relay02,OUTPUT);
  pinMode(led3,OUTPUT);
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

 //-----LED ------------------------------------------------------------------
  digitalWrite(relay01,HIGH);
  digitalWrite(relay02,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(buzzer,LOW);
  delay(500);
  digitalWrite(relay01,LOW);
  digitalWrite(relay02,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(buzzer,HIGH);
  delay(500);

 //------SENSOR 1 -------------------------------------------------------------
    
  int dataLDR = analogRead(sensorLDR);
  Serial.print("Cahaya: ");
  Serial.println(dataLDR);  

 //------SENSOR 1 -------------------------------------------------------------
    
  int dataVR = analogRead(sensorVR);
  Serial.print("Cahaya: ");
  Serial.println(dataVR);  

 //------SENSOR 2 -------------------------------------------------------------
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();

  Serial.print("Humidity: ");
  Serial.println(humid);
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println("°C ");

 //------DISPLAY OLED   -----------------------------------------------------------

  paparOled.clearDisplay();
  paparOled.setTextSize(1);
  paparOled.setTextColor(WHITE);
  paparOled.setCursor(0,0);
  //paparOled.println("--- ESP32C3- MINI ---");
  paparOled.println("--  EduIot-Esp32C3 --");
  paparOled.setCursor(0,10);
  paparOled.println("K. Komuniti Sbg Jaya");
  paparOled.setCursor(0,20);
  paparOled.println("--------------------");
  // ---- display Humidity 
  paparOled.setCursor(0,30);
  paparOled.print("HUM:");
  paparOled.print(humid,0);
  paparOled.print(" %");
  // ---- display Temperature 
  paparOled.setCursor(60,30);
  paparOled.print("TMP:");
  paparOled.print(temp,0);
  paparOled.print(" C");
  // ---- display Light intensity 
  paparOled.setCursor(0,40);
  paparOled.print("LDR:");
  paparOled.print(dataLDR);

  paparOled.setCursor(60,40);
  paparOled.print("ANG:");
  paparOled.print(dataVR);
  paparOled.display();
 //-----------end ----------------------------------

}
//##################  Seksyen 3 - TAMAT #############################