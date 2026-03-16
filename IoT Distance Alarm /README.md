# ESP32 & Python ile Telegram Bildirimli Güvenlik Sistemi 🚨

Bu proje, bir kapının veya pencerenin açıldığını algılayarak bilgisayar kamerası üzerinden fotoğraf çeken ve bu fotoğrafı anında Telegram üzerinden size gönderen akıllı bir güvenlik sistemidir. 

Sistem iki ana bileşenden oluşur:
1. **ESP32 / Mikrokontrolör:** Üzerindeki HC-SR04 ultrasonik sensör ile mesafeyi ölçer. Kapı açıldığında (mesafe eşik değerini aştığında) yerel ağdaki bilgisayara HTTP GET isteği atarak tetikleme yapar.
2. **Python Flask Sunucusu:** Bilgisayarda arka planda çalışır. ESP32'den sinyal geldiğinde OpenCV kullanarak kameradan anlık bir fotoğraf çeker ve Telegram Bot API aracılığıyla belirlediğiniz sohbete gönderir.

## 🚀 Özellikler
* **Gerçek Zamanlı Mesafe Ölçümü:** HC-SR04 ultrasonik sensör ile hassas algılama.
* **Yerel Ağ İletişimi:** Cihazlar arası hızlı ve kablosuz haberleşme (ESP32 -> Flask).
* **Otomatik Görüntü Yakalama:** Sinyal anında OpenCV ile sıfır gecikmeli fotoğraf çekimi.
* **Anında Bildirim:** Telegram entegrasyonu ile dünyanın neresinde olursanız olun fotoğraf cebinize gelir.

## 🛠️ Kullanılan Teknolojiler ve Donanımlar
* **Donanım:** ESP32 (veya Wi-Fi destekli Arduino), HC-SR04 Ultrasonik Sensör, Jumper Kablolar.
* **Yazılım (C++):** Arduino IDE, `WiFi.h`, `HTTPClient.h`
* **Yazılım (Python):** Python 3.x, `Flask`, `OpenCV (cv2)`, `requests`

## ⚙️ Kurulum ve Çalıştırma

### 1. Python Sunucusunu Ayarlama
Öncelikle gerekli kütüphaneleri bilgisayarınıza kurun:
pip install flask opencv-python requests

security.py dosyasını açın ve şu kısımları kendi Telegram Bot bilgilerinizle güncelleyin:
TOKEN = "BURAYA_TELEGRAM_BOT_TOKEN_GELECEK" 
CHAT_ID = "BURAYA_CHAT_ID_GELECEK"

Ardından sunucuyu başlatın:
python app.py


2. ESP32'yi Ayarlama
Arduino IDE üzerinden .ino dosyasını açın ve aşağıdaki kısımları kendi ağ bilgilerinize göre doldurun:

const char* ssid = "WIFI_AGINIZIN_ADI";
const char* password = "WIFI_SIFRENIZ";
const char* pc_ip = "192.168.1.X";  // Flask sunucusunun çalıştığı bilgisayarın yerel IP adresi

Pin Bağlantıları:
Trig Pini -> Pin 9
Echo Pini -> Pin 10

Kodu ESP32'ye yükleyin. Cihaz Wi-Fi'ye bağlandıktan sonra ölçümlere başlayacaktır.

💡 Nasıl Çalışır?
ESP32 sürekli olarak sensörden gelen mesafeyi ölçer.
Eğer mesafe 50 cm'yi geçerse (kapı/pencere açıldıysa), sistem tetiklendi durumuna geçer ve bilgisayardaki http://[PC_IP]:5001/alert adresine bir istek yollar.
Flask sunucusu bu isteği alır almaz capture_and_send() fonksiyonunu çalıştırır.
Kamera açılır, fotoğraf çekilir (guvenlik_alrmi.jpg olarak kaydedilir) ve Telegram Bot üzerinden uyarı mesajıyla birlikte gönderilir.
Kapı kapandığında (mesafe tekrar 50 cm'nin altına düştüğünde) sistem kendini sıfırlar ve yeni bir ihlal için hazır bekler.

⚠️ Güvenlik Notu
Projeyi forklayacak veya kendi sisteminde kullanacak kişilerin security.py ve .ino dosyalarındaki hassas bilgileri (Token, Şifre vb.) kesinlikle public repolarda paylaşmaması önerilir.
