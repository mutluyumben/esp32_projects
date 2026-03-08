# 🛡️ ESP32-S3 IoT Security Radar & Dashboard

Bu proje, **ESP32-S3** mikrodenetleyicisi kullanılarak geliştirilmiş; nesne mesafesini hem fiziksel bir **OLED ekran** üzerinde, hem de canlı bir **Web Dashboard** üzerinden takip edebilen akıllı bir güvenlik sistemi prototipidir.

---

### 🚀 Özellikler
* **📡 Hassas Ölçüm:** HC-SR04 Ultrasonik sensör ile gerçek zamanlı mesafe takibi.
* **🖥️ Fiziksel Arayüz:** SSD1306 OLED ekran üzerinde dinamik veri görselleştirme.
* **🌐 IoT Dashboard:** Yerel ağ üzerinden (Wi-Fi) erişilebilen, her saniye güncellenen web arayüzü.
* **🚨 Akıllı Alarm Modu:** Nesne 15 cm'den yakına geldiğinde devreye giren görsel flaşör (OLED) ve web uyarı sistemi.
* **⚡ Donanım Optimizasyonu:** I2C protokolü ve güç yönetimi çözümleri uygulanmıştır.

---

### 🛠️ Kullanılan Bileşenler
* **Mikrodenetleyici:** ESP32-S3 (Dual Core, Wi-Fi & BT)
* **Sensör:** HC-SR04 Ultrasonik Mesafe Sensörü
* **Ekran:** 0.96" SSD1306 OLED (128x64)
* **İletişim:** I2C Protokolü & HTTP Web Server
* **Diğer:** Jumper kablolar, Breadboard

---

### 🔌 Bağlantı Şeması (Pinout)
| Bileşen | Pin (ESP32-S3) |
| :--- | :--- |
| **Ultrasonic TRIG** | GPIO 13 |
| **Ultrasonic ECHO** | GPIO 14 |
| **OLED SDA** | GPIO 7 |
| **OLED SCL** | GPIO 6 |
| **VCC** | 3.3V / 5V |
| **GND** | Ortak Toprak (GND) |

---

### 📦 Kurulum ve Kullanım
1. `config.h` (veya ana kod) içerisindeki `WIFI_SSID` ve `WIFI_PASS` bilgilerini güncelleyin.
2. Gerekli kütüphaneleri (Adafruit SSD1306, Adafruit GFX) Arduino IDE üzerinden kurun.
3. Kodu ESP32-S3 kartınıza yükleyin.
4. Seri port ekranında veya OLED üzerinde yazan **IP adresini** tarayıcınıza girin.
