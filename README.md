# Sınav Değerlendirme Sistemi

Bu proje, öğrencilerin sınav performanslarını değerlendiren ve analiz eden bir yazılımdır. Öğrencilerin cevaplarına göre doğru, yanlış ve boş cevapları hesaplar; sınıf ortalamasını ve standart sapmayı belirler; her bir öğrenci için T-skoru ve harf notu ataması yapar.

## 📂 İçindekiler

1. [Özellikler](#özellikler)
2. [Kullanım](#kullanım)
3. [Fonksiyonlar](#fonksiyonlar)
4. [Gereksinimler](#gereksinimler)
5. [Matematiksel Temeller](#matematiksel-temeller)
6. [Derleme ve Çalıştırma](#derleme-ve-çalıştırma)


---

## 🛠 Özellikler

- **Cevap Anahtarı Üretme:** Rastgele bir cevap anahtarı oluşturur.
- **Sınav Uygulama:** Öğrenci cevaplarını doğru, yanlış ve boş ihtimallerine göre üretir.
- **Harf Notu Hesaplama:** Öğrencilerin T-skorlarına göre harf notlarını belirler.
- **Sınıf Analizi:** Sınıfın ortalaması ve standart sapmasını hesaplar.
- **Esneklik:** Soru sayısı, öğrenci sayısı, doğru ve boş cevap olasılıkları kullanıcıdan alınabilir.

---

## 🚀 Kullanım

### Girdi
1. Öğrenci sayısı (`max 100`).
2. Soru sayısı (`max 100`).
3. Boş bırakma ihtimali (`0.0 - 1.0` aralığında).
4. Doğru cevap verme ihtimali (`0.0 - 1.0` aralığında).

### Çıktı
- **Cevap Anahtarı:** Sınavın doğru cevapları.
- **Öğrenci Cevapları:** Her öğrencinin verdiği cevaplar.
- **HBN (Ham Başarı Notu):** Öğrencilerin performansına göre hesaplanan puanlar.
- **T-Skoru:** Öğrencilerin başarı düzeylerini karşılaştıran skor.
- **Harf Notları:** Her öğrencinin aldığı harf notu.

---

## 🔧 Fonksiyonlar

- `cevap_anahtari_uret`: Rastgele bir cevap anahtarı oluşturur.
- `sinavi_uygula`: Öğrenci cevaplarını oluşturur.
- `ogrencileri_puanla`: Her öğrencinin HBN'sini hesaplar.
- `sinif_ortalamasi_hesapla`: Sınıf ortalamasını belirler.
- `standart_sapma_hesapla`: Standart sapmayı hesaplar.
- `T_skoru_hesapla`: Her öğrencinin T-skorunu hesaplar.
- `ogrenci_notlari_yazdir`: Harf notlarını ekrana yazdırır.

---

## 💻 Gereksinimler

- **C Derleyicisi:** GCC veya benzeri bir derleyici.
- **Platform:** Windows, Linux veya macOS.
- **Ek Kütüphaneler:** Matematik işlemleri için `<math.h>` kütüphanesi kullanılmaktadır.

---

## 🧪 Matematiksel Temeller

Bu proje, öğrenci performansını analiz etmek için aşağıdaki matematiksel konseptleri kullanır:
- **Standart Sapma:** Performans dağılımını ölçmek için.
- **T-Skoru:** Standartlaştırılmış skorlar arasında kıyaslama yapmak için.
- **HBN (Ham Başarı Notu):** Yanlış ve doğru cevapların birleştirilmesiyle hesaplanan puan.

---

## 🛠 Derleme ve Çalıştırma (Kolay Yöntem)

### 1. **Bir C Derleyicisi Edinin**
- **Windows Kullanıcıları:** [Code::Blocks](https://www.codeblocks.org/downloads/) gibi bir program indirip kurun.
- **macOS ve Linux Kullanıcıları:** Genellikle sisteminizde GCC yüklüdür. Eğer yoksa aşağıdaki komutlarla yükleyebilirsiniz:
  - **Linux:** `sudo apt install gcc`
  - **macOS:** `brew install gcc`

### 2. **Proje Dosyasını Açın**
- İndirdiğiniz derleyiciyi açın.
- `main.c` dosyasını programda açın.

### 3. **Kodu Derleyip Çalıştırın**
- Derleyicinizde **"Run"** veya **"Build and Run"** butonuna tıklayın.
- Program otomatik olarak derlenecek ve çalıştırılacaktır.

### 4. **Programı Kullanma**
- Konsol ekranında sizden istenen bilgileri girin:
  1. Öğrenci sayısı (`max 100`).
  2. Soru sayısı (`max 100`).
  3. Boş bırakma ihtimali (`0.0 - 1.0` arası).
  4. Doğru cevap verme ihtimali (`0.0 - 1.0` arası).
- Çıktılar konsolda görüntülenecektir.

---

## 🌐 Alternatif Olarak Online Derleyici Kullanın
- **OnlineGDB:** [https://www.onlinegdb.com/](https://www.onlinegdb.com/)
  1. Web sitesine gidin.
  2. `main.c` dosyasının içeriğini kopyalayıp yapıştırın.
  3. "Run" butonuna tıklayarak programı çalıştırın.

---
