/*-------------- SUMO ROBOT ESP32-C3------------------------
  ===================  Seksyen 1 - HEADER        ===================
  ------------------------------------------------------------------*/
//-------------------------------------------------------------------
//=  A. - Library  - #include and #define  yang diperlukan          =
//-------------------------------------------------------------------
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#define motorkiriA1   0
#define motorkiriA2   1 
#define motorkananB1  3 
#define motorkananB2  4 
#define buzzer 5  

//------BLE------------------------------------------------------
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

BLECharacteristic *pCharacteristic;
String command = "S";
//-------------------------------------------------------------------
//=  B. - ISTIHAR Sambungan nama Pin dengan Nombor Fizikal PIN      =
//-------------------------------------------------------------------


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
  Serial.println(" Sistem Robot Mula");

 //-- istihar fungsi komunikasi Bluetooth.
// BLE START
  // =============================

  BLEDevice::init("ESP32C3-ROBOT");

  BLEServer *pServer = BLEDevice::createServer();

  BLEService *pService =
      pServer->createService(SERVICE_UUID);

  pCharacteristic =
      pService->createCharacteristic(
        CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_WRITE |
        BLECharacteristic::PROPERTY_READ
      );

  pService->start();

  BLEAdvertising *pAdvertising =
      BLEDevice::getAdvertising();

  pAdvertising->addServiceUUID(SERVICE_UUID);

  pAdvertising->setScanResponse(true);

  BLEDevice::startAdvertising();

  Serial.println("ESP32-C3 ROBOT READY");
}

//##################  Seksyen 2 - TAMAT #############################


//==============  Seksyen 3 - Fungsi Utama (LOOP) ===================
//-------------------------------------------------------------------
void loop() {

   // Baca arahan BLE
  String data = pCharacteristic->getValue();

  if (data.length() > 0) {

    command = data;

    Serial.print("Command = ");
    Serial.println(command);

    // Bersihkan data selepas membaca
    pCharacteristic->setValue("");
  }
    

    //---Kawalan Motor Gerak ke DEPAN --
    if (command =="F"){
      digitalWrite(motorkiriA1,HIGH);
      digitalWrite(motorkiriA2,LOW);
      digitalWrite(motorkananB1,LOW);
      digitalWrite(motorkananB2,HIGH);
      Serial.println(" Motor Gerak ke DEPAN");
    }
    
    //---Kawalan Motor Gerak ke Depan --
    else if (command =="B"){
      digitalWrite(motorkiriA1,LOW);
      digitalWrite(motorkiriA2,HIGH);
      digitalWrite(motorkananB1,HIGH);
      digitalWrite(motorkananB2,LOW);
      Serial.println(" Motor Gerak ke UNDUR ");
    }

    //---Kawalan Motor Henti --
    else if (command =="S"){
      digitalWrite(motorkiriA1,LOW);
      digitalWrite(motorkiriA2,LOW);
      digitalWrite(motorkananB1,LOW);
      digitalWrite(motorkananB2,LOW);
      Serial.println(" Motor HENTI");
    }

   //---Kawalan Motor Gerak ke KIRI --
    else if (command =="L"){
      digitalWrite(motorkiriA1,LOW);
      digitalWrite(motorkiriA2,HIGH);
      digitalWrite(motorkananB1,LOW);
      digitalWrite(motorkananB2,HIGH);
      Serial.println(" Motor Gerak ke KIRI");
    }

   //---Kawalan Motor Gerak ke KANAN --
    else if (command =="R"){
      digitalWrite(motorkiriA1,HIGH);
      digitalWrite(motorkiriA2,LOW);
      digitalWrite(motorkananB1,HIGH);
      digitalWrite(motorkananB2,LOW);
      Serial.println(" Motor Gerak ke KANAN");
    }

    else if (command =="H"){
      digitalWrite(buzzer,HIGH);
      Serial.println(" buzzer bunyi");
    }

     else if (command =="h"){
      digitalWrite(buzzer,LOW);
      Serial.println(" buzzer senyap");
    }
  
}