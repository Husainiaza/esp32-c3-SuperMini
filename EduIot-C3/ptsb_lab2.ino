/*------------------------------------------------------------------
  ===================  Seksyen 1 - HEADER        ===================
// ------------------------------------------------------------------*/

//---------------------------------------------------------------
//=  A. - Library  include and define  yang diperlukan              =
//-------------------------------------------------------------------

#include "DHT.h"

//--------------------------------------------------------------------------
//-----b. - ISTIHAR Sambungan nama Pin dengan Nombor Fizikal PIN ----
//--------------------------------------------------------------------------

#define relay01     6  // digital OUTPUT - RELAY 1
#define relay02     7  // digital OUTPUT - RELAY 2
#define DHTPIN      5     
#define DHTTYPE DHT22

//-----d. - Cipta Objek dari Librari berkaitan------------------ ----
//--------------------------------------------------------------------------

// Istihar objek bagi Module DHT
DHT dht(DHTPIN, DHTTYPE);

//##################  Seksyen 1 - TAMAT #############################


//###################################################
//==================  Seksyen 2 - Fungsi Setup ======================
//-------------------------------------------------------------------

void setup() {
  pinMode(relay01,OUTPUT);
  pinMode(relay02,OUTPUT);
  Serial.begin(115200); // initialize serial
 
  dht.begin();
}
//##################  Seksyen 2 - TAMAT #############################

//==============  Seksyen 3 - Fungsi Utama (LOOP) ===================
//-------------------------------------------------------------------
void loop() {

 //------DHT 22 -------------------------------------------------------------
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();

  Serial.print("Humidity: ");
  Serial.println(humid);
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println("°C ");

  delay(200);

}
//##################  Seksyen 3 - TAMAT #############################
