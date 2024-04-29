String kurang = "KURANG";
String normal = "NORMAL";
String lebih = "LEBIH";

void dhtCode(){
  hum = dht.readHumidity();      // Baca kelembapan
  temp = dht.readTemperature();  // Baca temperatur
  if (isnan(hum) || isnan(temp)) {     // Cek jika sensor error
      Serial.println("Gagal Membaca DHT sensor! UUHUYYYY");
      return;
  }
  if (hum < 55.00 && temp < 29.00){
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    delay(3000);
    antares.add("Status Kandang", kurang);
  } else if (55.00 <= hum <= 70.00 && 29.00 <= temp <= 32.00){
    antares.add ("Status Kandang", normal);  
  } else if (hum > 70.00 && temp > 32.00){
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    delay(1000);
    antares.add ("Status Kandang",lebih); 
  }
}

// TEST REPO
