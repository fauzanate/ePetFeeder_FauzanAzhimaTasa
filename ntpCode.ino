void ntpCode(){
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
//  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  strftime(dateTime, sizeof dateTime, "%A, %B %d %Y %H:%M:%S", &timeinfo);
//  dateAndTime = String(dateAndTime + dateTime);
  
//  Serial.println(dateTime);
//  Serial.print("Date: ");
//  Serial.println(&timeinfo, "%A, %B %d %Y");
//  Serial.print("Time: ");
//  Serial.println(&timeinfo, "%H:%M:%S \n");  
  strftime(str, sizeof str, "%H:%M:%S", &timeinfo);
//  Serial.println(str);

  if (strcmp (str, "15:20:00") >= 0){
    myServo.write(90);
    antares.add ("ePet Feeder", servoBuka);
    } if (strcmp (str, "15:20:45") >= 0){
      myServo.write(0);
      antares.add ("ePet Feeder", servoTutup);
    } if (strcmp (str, "15:22:00") >= 0){
      myServo.write(90);
      antares.add ("ePet Feeder", servoBuka);
    } if (strcmp (str, "15:22:45") >= 0){
      myServo.write(0);
      antares.add ("ePet Feeder", servoTutup);
    } 
}
