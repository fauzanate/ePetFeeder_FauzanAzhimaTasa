void sdCardCode(){
//  dataMessage = String(&timeinfo) + "," + String(hum) + "," + String(temp)+ "," + String(distance)+ "\r\n";
  dataMessage = "" + String(dateTime) + "," + String(hum) + "," + String(temp)+ "," + String(distance)+ "\r\n";
  Serial.print("Save data: ");
  Serial.println(dataMessage);
  appendFile(SD, "/data_ePetFeeder.txt", dataMessage.c_str());
}


void writeFile(fs::FS &fs, const char * path, const char * message) {
  Serial.printf("Writing file: %s\n", path);
  File file = fs.open(path, FILE_WRITE);
  if(!file) {
    Serial.println("Gagal membuka file untuk writing");
    return;
  }
  if(file.print(message)) {
    Serial.println("File written");
  } else {
    Serial.println("Write failed");
  }
  file.close();
}


void appendFile(fs::FS &fs, const char * path, const char * message) {
  Serial.printf("Appending to file: %s\n", path);
  File file = fs.open(path, FILE_APPEND);
  if(!file) {
    Serial.println("Gagal membuka file untuk appending");
    return;
  }
  if(file.print(message)) {
    Serial.println("Message appended");
  } else {
    Serial.println("Append failed");
  }
  file.close();
}
