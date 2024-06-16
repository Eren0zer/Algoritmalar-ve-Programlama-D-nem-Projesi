#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define max_ogrenci 100


double ortalama1 = 0;
double std1 = 0;


void cevap_anahtari_uret(char cevap_anahtari[], int S)
{
     srand(time(0));
     char cevap_siklari[5]={'A','B','C','D','E'};
     printf("Cevap Anahtari: \n");
     for(int i=0; i<S; i++){
            int random = rand()%5;
            cevap_anahtari[i]=cevap_siklari[random];
     }
}


void cevap_anahtari_yazdir(char cevap_anahtari[], int S)
{
    for(int i=0; i<S; i++){
        printf("Soru %d: %c | ",i+1,cevap_anahtari[i]);

    }

}



void sinavi_uygula(char ogrenci_cevaplari[][100], char cevap_anahtari[], int N, int S, double B,
double D)
{
    char yanlis_cevap1[4] = {'B','C','D','E'};
    char yanlis_cevap2[4] = {'A','C','D','E'};
    char yanlis_cevap3[4] = {'A','B','D','E'};
    char yanlis_cevap4[4] = {'A','B','C','E'};
    char yanlis_cevap5[4] = {'A','B','C','D'};

    for(int i=0; i<N; i++){
        for(int j=0; j<S; j++){
            int kontrol = rand()%10+1;
            if(kontrol<=D*10) //doğru cevaplar
            ogrenci_cevaplari[i][j] = cevap_anahtari[j];
            else if(kontrol>D*10 && kontrol<=(1-B)*10){//yanlış cevaplar
                switch(cevap_anahtari[j])
                {
                    case 'A':
                    ogrenci_cevaplari[i][j]= yanlis_cevap1[rand()%4];
                    break;
                    case 'B':
                    ogrenci_cevaplari[i][j]= yanlis_cevap2[rand()%4];
                    break;
                    case 'C':
                    ogrenci_cevaplari[i][j]= yanlis_cevap3[rand()%4];
                    break;
                    case 'D':
                    ogrenci_cevaplari[i][j]= yanlis_cevap4[rand()%4];
                    break;
                    case 'E':
                    ogrenci_cevaplari[i][j] = yanlis_cevap5[rand()%4];
                    break;
                    default:
                        printf("HATALI!\n");
                }
            }
            else if(kontrol>(1-B)*10 && kontrol<=10) //boş cevaplar
            ogrenci_cevaplari[i][j] = 'X';

        }
    }
}



void ogrenci_cevabini_yazdir(char ogrenci_cevaplari[][100], int ogrenci_ID, int S)
{
    for(int i=0; i<ogrenci_ID; i++){
        printf("\n%d.ogrencinin cevaplari: \n",i+1);
        for(int j=0; j<S; j++){
            printf("Soru %d: %c | ",j+1,ogrenci_cevaplari[i][j]);
                              }
                                   }
}



void ogrencileri_puanla(char ogrenci_cevaplari[][100], char cevap_anahtari[], double HBN[], int N, int S)
{
    float dogru_sayisi=0;
    float yanlis_sayisi=0;
    for(int i=0; i<N; i++){
        dogru_sayisi=0;
        yanlis_sayisi=0;
        for(int j=0; j<S; j++){
            if(ogrenci_cevaplari[i][j]==cevap_anahtari[j])
                dogru_sayisi++;
            else if(ogrenci_cevaplari[i][j]=='X')
                ;
            else if(ogrenci_cevaplari[i][j]!=cevap_anahtari[j])
                yanlis_sayisi++;
        }
        HBN[i] = (dogru_sayisi-(yanlis_sayisi)/4)*(100/S);
        if(HBN[i]<0)
        HBN[i]=0;
    }
}


//Önce bütün öğrencilerin HBN'sini bir yerde toplayabilmek için bir toplam tanımlayıp 0a eşitliyoruz.
//Ardından döngüyle bütün HBNleri topladıktan sonra döngüden çıkıp toplamımızı öğrenic sayısına bölüp ortalamayı elde ediyoruz.
//Ortalamanın değerini alıp if ile hangi düzeyde olduğuna bakıyoruz.
double sinif_ortalamasi_hesapla(double HBN[], int N)
{
    double toplam=0;
    for(int i=0; i<N; i++){
        toplam = toplam + HBN[i];
    }
    ortalama1=toplam/N;
    printf("Sinif Ortalamasi: %.2lf\n",ortalama1);
    if(ortalama1>80.0 && ortalama1<=100)
    printf("Sinif Duzeyi: Ustun Basari\n");
    else if(ortalama1>70.0 && ortalama1<=80)
    printf("Sinif Duzeyi: Mukemmel\n");
    else if(ortalama1>62.5 && ortalama1<=70)
    printf("Sinif Duzeyi: Cok iyi\n");
    else if(ortalama1>57.5 && ortalama1<=62.5)
    printf("Sinif Duzeyi: iyi\n");
    else if(ortalama1>52.5 && ortalama1<=57.5)
    printf("Sinif Duzeyi: Ortanın Ustu\n");
    else if(ortalama1>47.5 && ortalama1<=52.5)
    printf("SinifDuzeyi: Orta\n");
    else if(ortalama1>42.5 && ortalama1<=47.5)
    printf("Sinif Duzeyi: Zayıf\n");
    else if(ortalama1<=42.5)
    printf("Sinif Duzeyi: Kotu\n");
    return ortalama1;
}


//Öncelikle bir hesap tanımlıyoruz. Ardından bütün öğrenicler için işlemleri yapıp sonuçları hesapta topluyoruz.
//Döngüden çıktıktan sonra öğrenci sayısına bölüp karakökten çıkartıp standart sapmayı elde ediyoruz.
double standart_sapma_hesapla(double ortalama, double HBN[], int N)
{
    double hesap=0;
    for(int i=0; i<N; i++){
        hesap = hesap + pow((HBN[i]-ortalama),2);
    }
    std1 = sqrt(hesap/N);
    printf("Standart Sapma: %.2lf\n",std1);
    return std1;
}


//standart sapma 0 ve 0dan küçük iste T skor hesaplanmıyor. Diğer ihtimalde verilen matematik işlemini koda döküyoruz
void T_skoru_hesapla(double ortalama, double HBN[], int N, double std, double T_skoru[])
{
     if(std<=0)
        printf("T_skoru hesaplanamaz hata\n");
    else
        for(int i=0; i<N; i++){
            T_skoru[i]=60+10*((HBN[i]-ortalama)/std);
        }
 }


//çektiğimiz ortalama bilgisiyle öğrencilerin hangi aralıktaki if'e gireceğini bulup ona göre hangi harf notunu aldığını gösteriyoruz.
void ogrenci_notlari_yazdir(double HBN[],double T_skoru[],int N)
{
    printf("Ogrenci Notlari: \n");
    for(int i=0; i<N; i++){
        if(ortalama1>80.0 && ortalama1<=100.0){
            if(T_skoru[i]<32.0)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: FF\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=32.0 && T_skoru[i]<=36.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: FD\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=37.0 && T_skoru[i]<=41.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: DD\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=42.0 && T_skoru[i]<=46.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: DC\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=470 && T_skoru[i]<=51.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: CC\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=52.0 && T_skoru[i]<=56.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: CB\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=52.0 && T_skoru[i]<=61.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: BB\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=62.0 && T_skoru[i]<=66.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: BA\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=67.0)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: AA\n",i+1,HBN[i],T_skoru[i]);
            }
        else if(ortalama1>70.0 && ortalama1<=80.0){
            if(T_skoru[i]<34)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: FF\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=34.0 && T_skoru[i]<=38.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: FD\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=39.0 && T_skoru[i]<=43.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: DD\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=44.0 && T_skoru[i]<=48.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: DC\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=49.0 && T_skoru[i]<=53.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: CC\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=54.0 && T_skoru[i]<=58.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: CB\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=59.0 && T_skoru[i]<=63.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: BB\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=64.0 && T_skoru[i]<=68.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: BA\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=69.0)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: AA\n",i+1,HBN[i],T_skoru[i]);
            }
        else if(ortalama1>62.5 && ortalama1<=70.0){
            if(T_skoru[i]<36.0)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: FF\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=36.0 && T_skoru[i]<=40.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: FD\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=41.0 && T_skoru[i]<=45.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: DD\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=46.0 && T_skoru[i]<=50.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: DC\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=51.0 && T_skoru[i]<=55.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: CC\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=56.0 && T_skoru[i]<=60.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: CB\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=61.0 && T_skoru[i]<=65.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: BB\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=66.0 && T_skoru[i]<=70.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: BA\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=71.0)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: AA\n",i+1,HBN[i],T_skoru[i]);
            }
        else if(ortalama1>57.5 && ortalama1<=62.5){
            if(T_skoru[i]<38.0)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: FF\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=38.0 && T_skoru[i]<=42.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: FD\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=43.0 && T_skoru[i]<=47.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: DD\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=48.0 && T_skoru[i]<=52.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: DC\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=53.0 && T_skoru[i]<=57.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: CC\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=58.0 && T_skoru[i]<=62.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: CB\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=63.0 && T_skoru[i]<=67.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: BB\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=68.0 && T_skoru[i]<=72.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: BA\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=73.0)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: AA\n",i+1,HBN[i],T_skoru[i]);
            }
       else if(ortalama1>52.5 && ortalama1<=57.5){
            if(T_skoru[i]<40.0)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: FF\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=40.0 && T_skoru[i]<=44.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: FD\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=45.0 && T_skoru[i]<=49.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: DD\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=50.0 && T_skoru[i]<=54.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: DC\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=55.0 && T_skoru[i]<=59.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: CC\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=60.0 && T_skoru[i]<=64.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: CB\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=65.0 && T_skoru[i]<=69.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: BB\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=70.0 && T_skoru[i]<=74.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: BA\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=75.0)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: AA\n",i+1,HBN[i],T_skoru[i]);
            }
       else  if(ortalama1>47.5 && ortalama1<=52.5){
            if(T_skoru[i]<42.0)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: FF\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=42.0 && T_skoru[i]<=46.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: FD\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=47.0 && T_skoru[i]<=51.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: DD\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=52.0 && T_skoru[i]<=56.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: DC\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=57.0 && T_skoru[i]<=61.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: CC\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=62.0 && T_skoru[i]<=66.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: CB\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=67.0 && T_skoru[i]<=71.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: BB\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=72.0 && T_skoru[i]<=76.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: BA\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=77.0)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: AA\n",i+1,HBN[i],T_skoru[i]);
            }
       else if(ortalama1>42.5 && ortalama1<=47.5){
            if(T_skoru[i]<44.0)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: FF\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=44.0 && T_skoru[i]<=48.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: FD\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=49.0 && T_skoru[i]<=53.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: DD\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=54.0 && T_skoru[i]<=58.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: DC\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=59.0 && T_skoru[i]<=63.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: CC\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=64.0 && T_skoru[i]<=68.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: CB\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=69.0 && T_skoru[i]<=73.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: BB\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=74.0 && T_skoru[i]<=78.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: BA\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=79.0)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: AA\n",i+1,HBN[i],T_skoru[i]);
            }
      else  if(ortalama1<=42.5){
            if(T_skoru[i]<46.0)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: FF\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=46.0 && T_skoru[i]<=50.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: FD\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=51.0 && T_skoru[i]<=55.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: DD\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=56.0 && T_skoru[i]<=60.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: DC\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=61.0 && T_skoru[i]<=65.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: CC\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=66.0 && T_skoru[i]<=70.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: CB\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=71.0 && T_skoru[i]<=75.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: BB\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=76.0 && T_skoru[i]<=80.99)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: BA\n",i+1,HBN[i],T_skoru[i]);
            else if (T_skoru[i]>=81.0)
                printf("%d. ogrencinin HBN: %.2lf , T_skoru: %.2lf ,harf notu: AA\n",i+1,HBN[i],T_skoru[i]);
            }

    }
}




int main()
{

    int N,S;
    double B,D;

    printf("Ogrenci sayisini giriniz (max 100): ");
    scanf("%d",&N);

    printf("Soru sayisini giriniz (max 100): ");
    scanf("%d",&S);

    printf("Bos birakma ihtimalini giriniz (0.0 - 1.0): ");
    scanf("%lf",&B);

    printf("Dogru cevap verme ihtimalini giriniz (0.0 - 1.0): ");
    scanf("%lf",&D);
    printf("\n");

    char ogrenci_cevaplari[100][100];
    char cevap_anahtari[100];
    int ogrenci_ID = N;
    double HBN[100]={0};
    double T_skoru[100] = {0};




    cevap_anahtari_uret(cevap_anahtari,S);
    cevap_anahtari_yazdir(cevap_anahtari,S);
    printf("\n");
    sinavi_uygula(ogrenci_cevaplari,cevap_anahtari,N,S,B,D);
    ogrenci_cevabini_yazdir(ogrenci_cevaplari,ogrenci_ID,S);
    printf("\n");
    ogrencileri_puanla(ogrenci_cevaplari,cevap_anahtari,HBN,N,S);
    printf("\n");
    sinif_ortalamasi_hesapla(HBN,N);
    standart_sapma_hesapla(ortalama1,HBN,N);
    printf("\n");
    T_skoru_hesapla(ortalama1,HBN,N,std1,T_skoru);
    ogrenci_notlari_yazdir(HBN,T_skoru,N);



  return 0;
}

