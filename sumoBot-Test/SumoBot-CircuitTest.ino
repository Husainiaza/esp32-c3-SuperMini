/*-------------- SUMO ROBOT ESP32-C3------------------------
  ===================  Seksyen 1 - HEADER        ===================
  ------------------------------------------------------------------*/
//-------------------------------------------------------------------
//=  A. - Library  - #include and #define  yang diperlukan          =
//-------------------------------------------------------------------
#include <Adafruit_SSD1306.h>

#define motorkiriA1   0
#define motorkiriA2   1 
#define motorkananB1  3 
#define motorkananB2  4 
#define buzzer 5  
#define TRIG_PIN  20 
#define ECHO_PIN  21 
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
//-------------------------------------------------------------------
//=  B. - ISTIHAR Sambungan nama Pin dengan Nombor Fizikal PIN      =
//-------------------------------------------------------------------
// Istihar objek bagi Module OLED Display - SSD1306
Adafruit_SSD1306 paparOled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


long duration;
float distance;

//##################  Seksyen 1 - TAMAT #############################


//==================  Seksyen 2 - Fungsi Setup ======================
//-------------------------------------------------------------------
void setup() {

 //-- Motor KIRI
  pinMode(motorkiriA1, OUTPUT);
  pinMode(motorkiriA2, OUTPUT);
 //-- Motor Kanan  F
  pinMode(motorkananB1, OUTPUT);
  pinMode(motorkananB2, OUTPUT);
 //--  buzzer
  pinMode(buzzer, OUTPUT);
  


 //-- istihar fungsi komunikasi Serial.
 
  Serial.begin(115200);
  delay(100);

   if(!paparOled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  Serial.println(" Sistem Robot Mula");

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

 //-----SENSOR 6 - ULTRASONIC --------------------------------------------------
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


  if(Serial.available()> 0){
    char dat = Serial.read();
    Serial.println(dat);
    

    //---Kawalan Motor Gerak ke DEPAN --
    if (dat=='F'){
      digitalWrite(motorkiriA1,HIGH);
      digitalWrite(motorkiriA2,LOW);
      digitalWrite(motorkananB1,LOW);
      digitalWrite(motorkananB2,HIGH);
      Serial.println(" Motor Gerak ke DEPAN");
    }
    
    //---Kawalan Motor Gerak ke Depan --
    else if (dat=='B'){
      digitalWrite(motorkiriA1,LOW);
      digitalWrite(motorkiriA2,HIGH);
      digitalWrite(motorkananB1,HIGH);
      digitalWrite(motorkananB2,LOW);
      Serial.println(" Motor Gerak ke UNDUR ");
    }

    //---Kawalan Motor Henti --
    else if (dat=='S'){
      digitalWrite(motorkiriA1,LOW);
      digitalWrite(motorkiriA2,LOW);
      digitalWrite(motorkananB1,LOW);
      digitalWrite(motorkananB2,LOW);
      Serial.println(" Motor HENTI");
    }

   //---Kawalan Motor Gerak ke KIRI --
    else if (dat=='L'){
      digitalWrite(motorkiriA1,LOW);
      digitalWrite(motorkiriA2,HIGH);
      digitalWrite(motorkananB1,LOW);
      digitalWrite(motorkananB2,HIGH);
      Serial.println(" Motor Gerak ke KIRI");
    }

   //---Kawalan Motor Gerak ke KANAN --
    else if (dat=='R'){
      digitalWrite(motorkiriA1,HIGH);
      digitalWrite(motorkiriA2,LOW);
      digitalWrite(motorkananB1,HIGH);
      digitalWrite(motorkananB2,LOW);
      Serial.println(" Motor Gerak ke KANAN");
    }

    else if (dat=='H'){
      digitalWrite(buzzer,HIGH);
      Serial.println(" buzzer bunyi");
    }

     else if (dat=='h'){
      digitalWrite(buzzer,LOW);
      Serial.println(" buzzer senyap");
    }
  }
}
