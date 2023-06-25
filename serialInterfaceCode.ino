void serialInterfaceCode(){
  if (Serial.available()){
    int bacaSerial = Serial.read();
    if (bacaSerial == '?'){
      Serial.println("Kode berikut merupakan kode program ePetFeeder");
      Serial.println("ePetFeeder merupakan suatu sistem pemberi pakan otomatis");
    }
  }
}
