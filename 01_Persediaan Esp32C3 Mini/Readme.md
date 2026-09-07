# **PERSEDIAAN AWAL ESP32C3 Mini**

## *Pengenalan ESP32 C Mini*
ESP32 Super Mini adalah Developement Board berasaskan dari Cip Espressif ESP32-C3 iaitu sebahagian dari Keluarga ESP32. Kelebihannya berbanding dengan ESP32 yang lain adalah papan litarnya yang kompak  dan 
pengunaannya tenaga dengan kecekapan kuasa yang rendah ketika mod deep sleep. Ianya terbina dengan siap dengan WiFi dan Bluetooth. ESP32-C3 Super mini adalah cip sigle-core dengan akitektur pemproses RiSC-V 32Bit.
Ia mempunyai 16 pin, dengan 11 GPIO boleh atur cara yang menyokong ADC, PWM, UART, I2C, dan SPI.

```http
Jadual PIN Sambungan GPIO
```

| Input     | Nombor GPIO Pin     | Aktuator/Sensor                      |
| :-------- | :-------            | :-------------------                 |
| GPIO 0    |  `00`               | **General-purpose I/O, ADC1, PWM**            |
| GPIO 1    |  `01`               | **General-purpose I/O, ADC1, PWM**            |
| GPIO 2    |  `02`               | **General-purpose I/O ADC1, Strapping Pin (Boot Mode) (avoid for general use)**            |
| GPIO 3    |  `03`               | **General-purpose I/O, PWM**    |
| GPIO 4    |  `04`               | **General-purpose I/O, PWM, default SPI SCK pin**   |
| GPIO 5    |  `05`               | **General-purpose I/O, PWM, default SPI MISO pin**    |
| GPIO 6    |  `06`               | **General-purpose I/O, PWM, default SPI MOSI pin**   |
| GPIO 7    |  `07`               | **General-purpose I/O, PWM, default SPI SS pin**            |
| GPIO 8    |  `08`               | **onboard LED (active low); Strapping Pin (avoid for general use); Default I2C SDA pin**   |
| GPIO 9    |  `09`               | **BOOT Button, Strapping Pin (avoid for general use), Default I2C SCL pin**         |
| GPIO 10   |  `10`               | **General-purpose I/O, PWM**       |
| GPIO 20   |  `20`               | **General-purpose I/O, PWM, default UART RX Pin**       |
| GPIO 21   |  `20`               | **General-purpose I/O, PWM, default UART TX Pin**       |

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
#*Hold down the BOOT button.*
#*Press and release the RESET button (while still holding BOOT).*
#*Then release the BOOT button.*

```
## 
