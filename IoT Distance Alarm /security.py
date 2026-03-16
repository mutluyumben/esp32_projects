import cv2
import requests
from flask import Flask
import time
import os

app = Flask(__name__)

# --- AYARLAR ---
TOKEN = "***:***" 
CHAT_ID = "***" 
# ---------------

def capture_and_send():
    os.environ['OPENCV_AVFOUNDATION_SKIP_AUTH'] = '0'

    cam = cv2.VideoCapture(0) 
    time.sleep(1) 
    ret, frame = cam.read()
    
    if ret:
        file_path = "guvenlik_alrmi.jpg"
        cv2.imwrite(file_path, frame)
        cam.release()
        
        # Telegram API ile fotoğraf gönderimi
        url = f"https://api.telegram.org/bot{TOKEN}/sendPhoto"
        with open(file_path, "rb") as photo:
            payload = {"chat_id": CHAT_ID, "caption": "⚠️ UYARI: Kapı açıldı! Hareket algılandı."}
            files = {"photo": photo}
            r = requests.post(url, data=payload, files=files)
            print("Telegram mesajı gönderildi:", r.status_code)
    else:
        print("Kameraya erişilemedi!")
        cam.release()

@app.route('/alert')
def alert():
    print("ESP32'den sinyal geldi! Fotoğraf çekiliyor...")
    capture_and_send()
    return "Tamam", 200

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5001)
