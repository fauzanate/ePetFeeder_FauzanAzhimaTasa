#include <AntaresESP32HTTP.h>
#include <time.h>
#include <DHT.h>      
#include <FS.h>
#include <SD.h>
#include <SPI.h>
#include <ESP32Servo.h>

//Konfigurasi wifi ke antares
#define ACCESSKEY     "42bd47a9b5ba0154:613de132d2f6e535"
#define WIFISSID      "pau"
#define PASSWORD      "fauzan0201"
#define projectName   "SmartPetFeeder"
#define deviceName    "ePetFeeder"

AntaresESP32HTTP antares(ACCESSKEY);

//============================================== NTP ==============================================
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 21600;
const int   daylightOffset_sec = 3600;

String servoBuka = "Pakan Keluar";
String servoTutup = "Pakan Tidak Keluar";

char str[100];        //Variable ubah Time ke Char
char dateTime[100];   //Variable ubah dateTime ke Char
struct tm timeinfo;
String dateAndTime;

//============================================== DHT11 ==============================================
#define DHTPIN 22           // Buat variabel DHTPIN, mengarah pada pin D2
#define DHTTYPE DHT11       // Tentukan tipe DHT menjadi DHT11
DHT dht(DHTPIN, DHTTYPE);   // Buat objek dht

float hum;
float temp;

//============================================== ULTRASONIC ==============================================
// Tentukan pin trig dan echo Ultrasonic
#define trigPin 32
#define echoPin 33

// Buat variable data untuk Ultrasonik
long duration;
float distance;

String kapasitasPenuh = "Kapasitas Penuh";
String kapasitasKosong = "Kapasitas Kosong";

//============================================== SD CARD ==============================================
// Tentukan pin SD Card
#define SD_CS 5
String dataMessage;

//============================================== SERVO ==============================================
Servo myServo;

//============================================== BUZZER ==============================================
#define buzzer 14


void setup()
{
  antares.setDebug(true);
  Serial.begin(115200);      // Buka komunikasi serial pada baudrate 9600
  
//  antares.wifiConnection(WIFISSID,PASSWORD);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFISSID, PASSWORD);
  Serial.println("");
 
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(WIFISSID);
  
  dht.begin();             // Inisiasi objek dht

  myServo.attach(27);     //Pin Servo
  myServo.write(0);

  pinMode(buzzer, OUTPUT); // Buzzer sebagai output
  
  pinMode(trigPin, OUTPUT); // Set trigPin sebagai Output
  pinMode(echoPin, INPUT); // Set echoPin sebagai Input

  // Mendapatkan waktu ke server
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  
  // Inisialisasi SD card
  SD.begin(SD_CS);  
  if(!SD.begin(SD_CS)) {
    Serial.println("SD Card Error");
    return;
  }
  uint8_t cardType = SD.cardType();
  if(cardType == CARD_NONE) {
    Serial.println("SD Card Tidak Terpasang");
    return;
  }
  Serial.println("Inisialisasi SD Card.......");
  if (!SD.begin(SD_CS)) {
    Serial.println("ERROR - SD Card Gagal Inisialisasi");
    return;    
  }
  File file = SD.open("/data_ePetFeeder.txt");
  if(!file) {
    Serial.println("File Tidak Ditemukan");
    Serial.println("Membuat File Baru...........");
    writeFile(SD, "/data_ePetFeeder.txt", "Date and Time, Temperature, Humidity, Distance \r\n");
  }
  else {
    Serial.println("File Sudah Tersedia");  
  }
  file.close();
}


void loop() {
  ntpCode();
  dhtCode();
  ultrasonicCode();
  sdCardCode();
  serialInterfaceCode();
  
  Serial.println("==================================================================");
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  
  Serial.println("Humidity: " + (String)hum + " %");       // Print kelembapan (%)
  Serial.println("Temperature: " + (String)temp + " *C");  // Print temperatur (*C)

  Serial.println("Distance: " + (String)distance + " CM");       // Print Jarak (CM)

   
  antares.add ("Humidity", hum);
  antares.add ("Temperature", temp);
  
  antares.add ("Jarak", distance);
  
    
  antares.send(projectName,deviceName);
  delay(10000);
}
