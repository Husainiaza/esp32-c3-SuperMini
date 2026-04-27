# **PERSEDIAAN AWAL ESP32C3 Mini**

## *Pengenalan ESP32 C Mini*
ESP32 Super Mini adalah Developement Board berasaskan dari Cip Espressif ESP32-C3 iaitu sebahagian dari Keluarga ESP32. Kelebihannya berbanding dengan ESP32 yang lain adalah papan litarnya yang kompak  dan 
pengunaannya tenaga dengan kecekapan kuasayang rendah ketika mod deep sleep. Ianya terbina dengan siap dengan WiFi dan Bluetooth. ESP32-C3 Super mini adalah cip sigle-core dengan akitektur pemproses RiSC-V 32Bit.


## ESP32-C3 Super Mini - Rajah Kedudukan Pin (Pin Layout)

<img width="915" height="485" alt="image" src="https://github.com/user-attachments/assets/3c1cb27b-ca9c-4549-bbbd-9f5d6dff6cd6" />


## *Koding ESP32 C3 dengan Arduino IDE* 

**1 - Muat Turun ARduino IDE dan install dalam PC anda ( https://www.arduino.cc/en/software/ )**
<img width="1408" height="612" alt="image" src="https://github.com/user-attachments/assets/2e063f55-0d5f-425f-9542-eedec33fb3d4" />

**2 - Selepas Install Arduino IDE kita perlu install pula Board ESP32**

<img width="842" height="549" alt="image" src="https://github.com/user-attachments/assets/5140f2a3-d8a3-4bba-a1ee-d341b95b975e" />

Install esp32 3.x atau update jika versi lama. bila sudah siap install button akan menunjukkan perkataan REMOVE (sepeti dalam rajah di atas)

**3 : Menetapkan Jenis ESP32 C3 yang hendak  digunakan**

<img width="881" height="516" alt="image" src="https://github.com/user-attachments/assets/f3459e72-fd74-4494-8fe2-b649b0a33fbe" /> 

### Meletakkan ESP32 C3 super Mini dalam Mode Bootloader buat kali pertama

Sambungkan ESP32 C3 Super Mini ke komputer bagi tujuanbesedia untuk muat turunkan kod dari Komp[uter ke ESP32 menggunakan port USB
Langkah :
*Hold down the BOOT button.*
*Press and release the RESET button (while still holding BOOT).*
*Then release the BOOT button.*

```
## 
