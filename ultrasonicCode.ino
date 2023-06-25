void ultrasonicCode(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  // Kalkulasikan jarak
  distance = duration * 0.034 / 2;

  if (distance >= 12.00){
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    delay(1000);
    antares.add ("Kapasitas", kapasitasKosong);
    }else if (distance < 12.00){
    antares.add ("Kapasitas", kapasitasPenuh);
  }
}
