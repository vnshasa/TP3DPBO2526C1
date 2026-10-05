# TP3 DPBO - K-Drama Hub

## Janji

Saya **Vanisha Septiani Auliaputri** dengan NIM **2510735** mengerjakan Tugas Praktikum 3
dalam mata kuliah Desain Pemrograman Berorientasi Objek untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

---

## 1. Deskripsi Program

**K-Drama Hub** adalah program katalog drama Korea yang menyimpan informasi drama, sutradara, penulis, pemeran, dan episode.

Program dibuat dalam tiga bahasa, yaitu **C++**, **Python**, dan **Java**. Struktur class dan alur program dibuat sama pada ketiga bahasa.

Konsep OOP yang digunakan:

| Konsep | Implementasi |
|---|---|
| Minimal 4 kelas | 7 kelas: `Person`, `Actor`, `Director`, `Writer`, `Episode`, `Drama`, `DramaCatalog` |
| Hierarchical Inheritance | `Person` menjadi parent dari `Actor`, `Director`, dan `Writer` |
| Aggregation | `DramaCatalog` dengan `Drama`, serta `Drama` dengan `Actor`, `Director`, dan `Writer` |
| Composition | `Drama` dengan `Episode` |
| Array of Object | C++ menggunakan `vector`, Python menggunakan `list`, Java menggunakan `ArrayList` |
| Encapsulation | Atribut dibuat private dan diakses melalui getter dan setter |
| Polimorfisme | Method `getRole()` dan `displayInfo()` di-override pada class turunan |


---

## 2. Struktur Folder

```text
TP3DPBO2526C1/
├── README.md
├── DesainDiagram.png
├── CPP/
│   ├── Program/
│   │   ├── Person.h
│   │   ├── Actor.h
│   │   ├── Director.h
│   │   ├── Writer.h
│   │   ├── Episode.h
│   │   ├── Drama.h
│   │   ├── DramaCatalog.h
│   │   └── main.cpp
│   └── Dokumentasi/
│       ├── output-cpp-01.png ... output-cpp-11.png
├── Python/
│   ├── Program/
│   │   ├── person.py
│   │   ├── actor.py
│   │   ├── director.py
│   │   ├── writer.py
│   │   ├── episode.py
│   │   ├── drama.py
│   │   ├── drama_catalog.py
│   │   └── main.py
│   └── Dokumentasi/
│       ├── output-python-01.png ... output-python-11.png
└── Java/
    ├── Program/
    │   ├── Person.java
    │   ├── Actor.java
    │   ├── Director.java
    │   ├── Writer.java
    │   ├── Episode.java
    │   ├── Drama.java
    │   ├── DramaCatalog.java
    │   └── Main.java
    └── Dokumentasi/
        ├── output-java-01.png ... output-java-11.png
```

---

## 3. Desain Diagram Program

Diagram berikut menunjukkan class, atribut, method, inheritance, aggregation, dan composition yang digunakan pada program.

![Desain Diagram Class](DesainDiagram.png)

Keterangan simbol:
- `-` = atribut private
- `+` = method public
- panah segitiga kosong = inheritance
- diamond putih = aggregation
- diamond hitam = composition

Nama method pada diagram menggunakan gaya penulisan C++.

### 3.1 Hierarchical Inheritance

```text
             Person
            /   |   \
         Actor Director Writer
```

`Actor`, `Director`, dan `Writer` merupakan turunan dari `Person`. Hubungannya adalah **is-a**.

### 3.2 Aggregation

```text
DramaCatalog ◇── Drama
Drama ◇── Actor
Drama ◇── Director
Drama ◇── Writer
```

Aggregation digunakan karena object yang digunakan tetap dapat berdiri sendiri dan dibuat di luar object pemilik.

### 3.3 Composition

```text
Drama ◆── Episode
```

Composition digunakan karena `Episode` menjadi bagian internal dari `Drama`. Episode yang disimpan sebagai bagian internal dibuat untuk menjadi bagian dari object `Drama`.

---

## 4. Atribut dan Method Setiap Kelas

Semua atribut data dibuat **private** dan diakses melalui getter dan setter.

### 4.1 Person

Atribut:
- `name` : string — nama
- `age` : int — umur
- `debutYear` : int — tahun debut

Method:
- `getName()` / `get_name()` — mengambil nama
- `setName(name)` / `set_name(name)` — mengubah nama
- `getAge()` / `get_age()` — mengambil umur
- `setAge(age)` / `set_age(age)` — mengubah umur
- `getDebutYear()` / `get_debut_year()` — mengambil tahun debut
- `setDebutYear(debutYear)` / `set_debut_year(debutYear)` — mengubah tahun debut
- `getRole()` / `get_role()` — mengembalikan peran person
- `displayInfo()` / `display_info()` — menampilkan informasi person

### 4.2 Actor

Atribut tambahan:
- `agency` : string — agensi
- `characterName` : string — nama karakter
- `roleType` : string — jenis peran

Method:
- getter dan setter untuk `agency`, `characterName`, dan `roleType`
- `getRole()` / `get_role()` — override untuk Actor
- `displayInfo()` / `display_info()` — menampilkan informasi Actor

### 4.3 Director

Atribut tambahan:
- `signatureStyle` : string — gaya khas penyutradaraan
- `awardsWon` : int — jumlah penghargaan pada data program

Method:
- getter dan setter untuk `signatureStyle` dan `awardsWon`
- `getRole()` / `get_role()` — override untuk Director
- `displayInfo()` / `display_info()` — menampilkan informasi Director

### 4.4 Writer

Atribut tambahan:
- `penName` : string — nama pena/nama publik
- `specialtyGenre` : string — genre yang terkait dengan karya

Method:
- getter dan setter untuk `penName` dan `specialtyGenre`
- `getRole()` / `get_role()` — override untuk Writer
- `displayInfo()` / `display_info()` — menampilkan informasi Writer

### 4.5 Episode

Atribut:
- `number` : int — nomor episode
- `title` : string — judul episode
- `durationMinutes` : int — durasi episode dalam menit
- `viewerRating` : double — rating penonton dalam persen

Method:
- getter dan setter untuk seluruh atribut
- `display()` — menampilkan data episode

### 4.6 Drama

Atribut:
- `title` : string — judul drama
- `year` : int — tahun tayang
- `genre` : string — genre drama
- `broadcaster` : string — penyiar
- `director` : Director* — aggregation
- `writer` : Writer* — aggregation
- `cast` : vector<Actor*> — aggregation dan array of object
- `episodes` : vector<Episode> — composition dan array of object

Method:
- getter dan setter untuk seluruh atribut
- `getTotalEpisodes()` — menghitung jumlah episode
- `getTotalDuration()` — menghitung total durasi episode
- `getAverageRating()` — menghitung rata-rata rating episode
- `display()` — menampilkan detail drama dan daftar episode

### 4.7 DramaCatalog

Atribut:
- `name` : string — nama katalog
- `dramas` : vector<Drama*> — aggregation dan array of object

Method:
- `getName()` / `get_name()` — mengambil nama katalog
- `setName(name)` / `set_name(name)` — mengubah nama katalog
- `getDramas()` / `get_dramas()` — mengambil daftar drama
- `setDramas(dramas)` / `set_dramas(dramas)` — mengubah daftar drama
- `findDrama(title)` / `find_drama(title)` — mencari drama berdasarkan judul
- `getTotalDramas()` / `get_total_dramas()` — menghitung jumlah drama
- `getTotalEpisodes()` / `get_total_episodes()` — menghitung jumlah episode seluruh drama
- `displaySummary()` / `display_summary()` — menampilkan ringkasan drama
- `displayAll()` / `display_all()` — menampilkan seluruh data katalog

---

## 5. Relasi dan Hubungan Antar Class

### 5.1 Person, Actor, Director, dan Writer

`Person` menjadi parent class yang menyimpan atribut umum seperti nama, umur, dan tahun debut.

`Actor`, `Director`, dan `Writer` merupakan child class yang mewarisi atribut dan method dari `Person`, kemudian menambahkan atribut sesuai perannya masing-masing.

Hubungan ini merupakan **Hierarchical Inheritance** karena satu parent memiliki beberapa child.

### 5.2 Drama dengan Actor, Director, dan Writer

`Drama` memiliki hubungan **Aggregation** dengan `Actor`, `Director`, dan `Writer`.

Object-object tersebut dibuat sebagai object tersendiri di luar `Drama`, kemudian direferensikan oleh `Drama`. Karena itu keberadaan `Drama` tidak menentukan keberadaan object Actor, Director, maupun Writer.

### 5.3 Drama dengan Episode

`Drama` memiliki hubungan **Composition** dengan `Episode`.

Episode merupakan bagian internal dari Drama. Pada C++, episode disimpan sebagai object dalam `vector<Episode>`. Pada Python dan Java, `Drama` membuat object Episode internal sendiri berdasarkan data episode yang diberikan.

### 5.4 DramaCatalog dengan Drama

`DramaCatalog` memiliki hubungan **Aggregation** dengan `Drama`.

Object Drama dibuat terlebih dahulu, kemudian disimpan dalam daftar drama milik katalog. Dengan demikian, Drama tidak bergantung pada lifecycle `DramaCatalog`.

---

## 6. Array of Object

Array of Object digunakan pada beberapa bagian program:

| Lokasi | C++ | Python | Java |
|---|---|---|---|
| `DramaCatalog.dramas` | `vector<Drama*>` | `list[Drama]` | `ArrayList<Drama>` |
| `Drama.cast` | `vector<Actor*>` | `list[Actor]` | `ArrayList<Actor>` |
| `Drama.episodes` | `vector<Episode>` | `list[Episode]` | `ArrayList<Episode>` |

Collection tersebut digunakan untuk menyimpan lebih dari satu object dalam satu class.

---

## 7. Alur Main Program

Alur program berlaku sama untuk C++, Python, dan Java.

1. Program membuat object `DramaCatalog` dengan nama **K-Drama Hub**.
2. Program membuat dua drama awal, yaitu **Reply 1988** dan **Crash Landing on You**, beserta data Director, Writer, Actor, dan episode.
3. Kedua drama disimpan ke dalam `DramaCatalog`.
4. Program menampilkan **DATA SEBELUM PENAMBAHAN**.
5. Program mencari `Reply 1988`, lalu mengambil daftar episode, menambahkan episode ke-20, dan menyimpan kembali daftar episode melalui setter.
6. Program mencari `Crash Landing on You`, lalu mengambil daftar pemeran, menambahkan `Kim Jung-hyun`, dan menyimpan kembali daftar pemeran melalui setter.
7. Program mengambil daftar drama dari catalog, menambahkan **Hospital Playlist**, lalu menyimpan kembali daftar drama melalui setter.
8. Program menampilkan **DATA SESUDAH PENAMBAHAN**.
9. Program selesai.

Data program sebelum penambahan:
- 2 drama
- 35 episode

Data program setelah penambahan:
- 3 drama
- 48 episode

---

## 8. Cara Menjalankan Program

### C++

Jalankan dari folder `CPP/Program`:

```bash
g++ -std=c++17 main.cpp -o kdrama
```

Kemudian:

```bash
kdrama
```

### Python

Jalankan dari folder `Python/Program`:

```bash
python main.py
```

### Java

Jalankan dari folder `Java/Program`:

```bash
javac *.java
java Main
```

---

## 9. Dokumentasi

Dokumentasi berikut merupakan screenshot langsung dari terminal masing-masing bahasa. Urutan screenshot mengikuti alur program dari data sebelum penambahan sampai data setelah penambahan.

### C++

1. Data sebelum penambahan dan detail Reply 1988  
![C++ 01](CPP/Dokumentasi/output-cpp-01.png)

2. Daftar episode Reply 1988 sebelum penambahan  
![C++ 02](CPP/Dokumentasi/output-cpp-02.png)

3. Detail Crash Landing on You sebelum penambahan  
![C++ 03](CPP/Dokumentasi/output-cpp-03.png)

4. Daftar episode Crash Landing on You  
![C++ 04](CPP/Dokumentasi/output-cpp-04.png)

5. Proses penambahan data dan ringkasan sesudah penambahan  
![C++ 05](CPP/Dokumentasi/output-cpp-05.png)

6. Detail Reply 1988 setelah penambahan  
![C++ 06](CPP/Dokumentasi/output-cpp-06.png)

7. Daftar episode Reply 1988 setelah penambahan  
![C++ 07](CPP/Dokumentasi/output-cpp-07.png)

8. Detail Crash Landing on You setelah penambahan actor  
![C++ 08](CPP/Dokumentasi/output-cpp-08.png)

9. Daftar episode Crash Landing on You  
![C++ 09](CPP/Dokumentasi/output-cpp-09.png)

10. Detail Hospital Playlist  
![C++ 10](CPP/Dokumentasi/output-cpp-10.png)

11. Daftar episode Hospital Playlist  
![C++ 11](CPP/Dokumentasi/output-cpp-11.png)

### Python

1. Data sebelum penambahan dan detail Reply 1988  
![Python 01](Python/Dokumentasi/output-python-01.png)

2. Daftar episode Reply 1988 sebelum penambahan  
![Python 02](Python/Dokumentasi/output-python-02.png)

3. Detail Crash Landing on You sebelum penambahan  
![Python 03](Python/Dokumentasi/output-python-03.png)

4. Daftar episode Crash Landing on You  
![Python 04](Python/Dokumentasi/output-python-04.png)

5. Proses penambahan data dan ringkasan sesudah penambahan  
![Python 05](Python/Dokumentasi/output-python-05.png)

6. Detail Reply 1988 setelah penambahan  
![Python 06](Python/Dokumentasi/output-python-06.png)

7. Daftar episode Reply 1988 setelah penambahan  
![Python 07](Python/Dokumentasi/output-python-07.png)

8. Detail Crash Landing on You setelah penambahan actor  
![Python 08](Python/Dokumentasi/output-python-08.png)

9. Daftar episode Crash Landing on You  
![Python 09](Python/Dokumentasi/output-python-09.png)

10. Detail Hospital Playlist  
![Python 10](Python/Dokumentasi/output-python-10.png)

11. Daftar episode Hospital Playlist  
![Python 11](Python/Dokumentasi/output-python-11.png)

### Java

1. Data sebelum penambahan dan detail Reply 1988  
![Java 01](Java/Dokumentasi/output-java-01.png)

2. Daftar episode Reply 1988 sebelum penambahan  
![Java 02](Java/Dokumentasi/output-java-02.png)

3. Detail Crash Landing on You sebelum penambahan  
![Java 03](Java/Dokumentasi/output-java-03.png)

4. Daftar episode Crash Landing on You  
![Java 04](Java/Dokumentasi/output-java-04.png)

5. Proses penambahan data dan ringkasan sesudah penambahan  
![Java 05](Java/Dokumentasi/output-java-05.png)

6. Detail Reply 1988 setelah penambahan  
![Java 06](Java/Dokumentasi/output-java-06.png)

7. Daftar episode Reply 1988 setelah penambahan  
![Java 07](Java/Dokumentasi/output-java-07.png)

8. Detail Crash Landing on You setelah penambahan actor  
![Java 08](Java/Dokumentasi/output-java-08.png)

9. Daftar episode Crash Landing on You  
![Java 09](Java/Dokumentasi/output-java-09.png)

10. Detail Hospital Playlist  
![Java 10](Java/Dokumentasi/output-java-10.png)

11. Daftar episode Hospital Playlist  
![Java 11](Java/Dokumentasi/output-java-11.png)
