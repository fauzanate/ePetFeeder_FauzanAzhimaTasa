# ePetFeeder_FauzanAzhimaTasa

ePetFeeder merupkan sistem pemberi pakan otomatis dengan mamanfaatkan sistem IoT (Internet of Things). <br>

Cara penggunaan code: <br>
1. Buka seluruh code pada tab yang sama pada Arduino IDE <br>
![image](https://github.com/fauzanate/ePetFeeder_FauzanAzhimaTasa/assets/120632453/3de7e00f-a063-4ffe-9b82-30baa55acf74)
2. Penggunaan IoT Platform menggunakan Antares <br>
   Data yang di kirimkan ke IoT Platform yaitu: Status pemberian makan, status kelembapan dan suhu kandang, status pakan, 
   kelembapan, suhu, dan jarak.  
![image](https://github.com/fauzanate/ePetFeeder_FauzanAzhimaTasa/assets/120632453/998273c1-ac2d-4f43-806d-2c3514fe112c)

<br>
Deskripsi code: <br>
1. Modul mainCode <br>
   Modul ini merupakan gabungan dari seluruh code yang digunakan. <br>
2. Modul dhtCode <br>
   Modul ini merupakan kode program untuk memonitoring suhu dan kelembapan. Fungsi dari modul ini adalah untuk memonitoring kandang. Jika kelembapan dan suhu dibawah atau di atas normal, maka buzzer akan berbunyi. <br>
3. Modul ntpCode <br>
   Modul ini merupakan kode progran untuk menampilkan date and time zona waktu (Waktu Indonesia Bagian Barat). Penggunaan NTP ini harus connect ke jaringan internet. Fungsinya pada sistem ini adalah untuk memberikan kondisi 
   kapan waktu pemberian pakan perharinya. <br>
4. Modul sdCardCode <br>
   Modul ini merupakan kode program untuk menyimpan data yang telah ter-record olah sensor. Data yang di simpan yaitu: date and time, kelembapan, suhu, dan jarak. <br>
5. Modul serialInterfaceCode <br>
   Modul ini merupakan kode program untuk menampilkan deskripsi fungsi dari sistem yang dibuat. <br>
6. Modul ultrasonicCode <br>
   Modul ini merupakan kode program untuk mendapatkan data jarak. Fungsi dari modul ini adalah untuk memonitoring pakan yang tersimpan pada wadah. Jika pakan sudah mulai habis, maka buzzer akan menyala. <br>

Link YouTube demonstrasi: <br>
https://youtu.be/U2z76166EQM
