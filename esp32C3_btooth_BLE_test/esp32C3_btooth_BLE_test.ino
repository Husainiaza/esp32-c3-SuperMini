#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

// UUID (Universally Unique Identifier) khusus untuk Service dan Characteristic
// Anda boleh tukar UUID ini (jana di uuidgenerator.net jika perlu)
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

void setup() {
  Serial.begin(115200);
  Serial.println("Memulakan BLE Server...");

  // 1. Berikan nama pada ESP32-C3 anda (Nama ini akan muncul di iPhone)
  BLEDevice::init("ESP32-C3_iOS");

  // 2. Cipta BLE Server
  BLEServer *pServer = BLEDevice::createServer();

  // 3. Cipta BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // 4. Cipta BLE Characteristic (Tetapkan sifat BACA dan TULIS)
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  // 5. Tetapkan mesej awal yang iPhone boleh baca
  pCharacteristic->setValue("Hai dari ESP32-C3!");

  // 6. Mulakan perkhidmatan (Service)
  pService->start();

  // 7. Mula memancarkan (Advertise) isyarat supaya peranti iOS boleh menemuinya
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  
  // Konfigurasi tambahan untuk kestabilan sambungan dengan iPhone (Apple Guidelines)
  pAdvertising->setMinPreferred(0x06);  
  pAdvertising->setMinPreferred(0x12);
  
  BLEDevice::startAdvertising();
  Serial.println("Isyarat BLE sedang dipancarkan. Sila scan di iPhone anda!");
}

void loop() {
  // Dalam contoh asas ini, kita biarkan kosong. 
  // BLE berjalan di latar belakang (background task).
  delay(2000);
}