#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MEVCUT 10 //��renci say�s� burada sabit olarak tan�mland�

void MenuGosterimi(){ //Men�y� liste halinde g�steren fonksiyon.
	printf("MENU\n1-Kayit Ekle\n2-Kayitlari Listele\n3-Sinif basari notlarini hesapla\n4-Kayitlari basari notuna gore hesapla\n5-Istatistiki bilgiler\n6-Cikis\n\n");
}

int NotHesaplama(float vize1, float vize2, float final){//��rencinin not ortalamas�n� hesaplay�p geriye d�nd�ren fonksiyon
	int sonuc = 0; 
	sonuc = round((vize1*20)/100 + (vize2*30)/100 + (final*50)/100); //notlar� hesaplarken yuvarlama i�lemini round ile yapt�m
	
	return sonuc;
}

int EnYuksekNotuBulma(int notlar[]){ //parametre olarak ald��� dizideki en y�ksek say�y� geriye d�nd�ren fonksiyon
	int max = notlar[0];
	int i=0;
	for(i; i<MEVCUT; i++){
			if(max < notlar[i]){
				max = notlar[i];
			}
	}
	return max;
}

int EnDusukNotuBulma(int notlar[]){ //parametre olarak ald��� dizideki en d���k say�y� geriye d�nd�ren fonksiyon
	int min = notlar[0];
	int i=0;
	for(i; i<MEVCUT; i++){
			if(min > notlar[i]){
				min = notlar[i];
			}
	}
	return min;
}

const char* HarfNotu(int notu){ //��rencinin notunu parametre olarak al�p, hangi harf notuna sahip oldu�unu aral�klarla hesaplay�p ona g�re string de�er d�nd�ren fonksiyon.
		//notumuz bize parametre olarak geldi. notumuzun hangi harf notuna sahip olaca��n� ��renmemiz gerekiyor. 7 adet if yap�s� olu�turduk ve bu yap�lara parantez i�inde aral�klar verdik.
		//notumuz hangi aral��a dahilse o if blo�una girecek ve girdi�i blo�un harf notunu return ile d�nd�recek.
		if(notu >= 90 && notu<= 100){
			return "AA";
		}
		if(notu >= 85 && notu <= 89){
			return "BA";
		}
		if(notu >= 80 && notu <= 84){
			return "BB";
		}
		if(notu >= 75 && notu <= 79){
			return "CB";
		}
		if(notu >= 70 && notu <= 74){
			return "CC";
		}
		if(notu >= 65 && notu <= 69){
			return "DC";
		}
		if(notu >= 60 && notu <= 64){
			return "DD";
		}
		if(notu >= 50 && notu <= 59){
			return "FD";
		}
		
		return "FF";
}

const char* OgrenciDurumu(int notu){ //��renci durumunu, notunu parametre olarak alarak geriye d�nd�ren fonksiyon
	if(notu<=49){
		return "Kaldi";
	}
	else if(notu<=59 && notu>=50){
		return "Sartli Gecti";
	}
	
	return "Gecti";
}

void printName(char ad[][7], int i) {//isimleri table'a yazd�rd���m�z fonksiyon
	int j=0;
	for(j; ad[i][j]!= '\0'; j++){
		printf("%c", ad[i][j]);
	}
}

void CalculateNotes(int notu[], int vize1[], int vize2[], int final[]) { //Notlar� hesaplay�p notu array'ine att���m�z fonksiyon. Benzer isimle ba�ka bir fonksiyon oldu�u i�in ingilizce isim verdim.
    int i=0;
	for(i; i<MEVCUT; i++){ //��rencilerin notlar�n� depolayan notu[] array'ine, NotHesaplama fonksiyonu ile hesaplatarak teker teker for d�ng�s� ile g�nderiyoruz.
		notu[i] = NotHesaplama(vize1[i], vize2[i], final[i]);
	}
}

void KayitGerceklestirUyarisi(){ //Kay�t i�lemi ger�ekle�tir uyar�s�n� printf'le yazd�rd���m�z fonksiyon
	printf("Kisi eklemeden basari notu hesaplanamaz! Sinif kayit ekranindan kayit ekleme islemi gerceklestiriniz.\n\n");
}


int main(int argc, char *argv[]) {
	
	int secim;
	
	//��rencilerin isim, soyisim ve notlar�n� depolayan array tan�mlamalar�:
	char ad[MEVCUT][7];
	char soyad[MEVCUT];
	
	int vize1[MEVCUT];
	int vize2[MEVCUT];
	int final[MEVCUT];
	
	int notu[MEVCUT];
	char harfNotu[MEVCUT];
	
	int ogrenciSayisi = 0; //��renci her girdi�inde de�i�kenimiz 1 artacak. Bu de�i�kenin amac�; e�er ��renci hi� girilmemi�se ve kullan�c� men� 2,3,4,5'ten birine basmaya �al���yorsa 
	//ona uyar� verilmesi i�in kontrol amac�yla olu�turuldu
	
	int a = 1;//a de�i�keni ��k�� i�lemi i�in tan�mland� ve d�ng�ye parantez i�inde ko�ul olarak verildi. kullan�c� 6.men�y� i�aretledi�inde a de�i�keni 0 oluyor ve d�ng�ye bir daha girilemiyor.

	
	int geciciSayi = 0;
	char geciciString;
	
	int max = 0; //en b�y�k say� de�i�keni
	int min = 0; //en k���k say� de�i�keni
	int sinifOrtalamasi = 0; //s�n�f ortalamas�
	int ortalamaUstu = 0; //ortalaman�n �st�nde olan ��renciler kadar b�y�kl��� olan de�i�ken
	int basariOrani = 0; //ba�ar� oran�/10 kadar b�y�kl��� olan de�i�ken
	float standartSapma = 0.00;
	
	while(a){
		
		MenuGosterimi();
		
		printf("Bir islem seciniz: ");
		scanf("%d", &secim);
		printf("\n");
		
		switch(secim){
			
		case 1://Kullan�c� se�imde 1'e bast���nda case 1'deki kay�t ekle i�lemleri yap�lacak
			
			printf("---Kayit Ekle---\n");
			int i=0;
			for(i; i<MEVCUT; i++){ //kullan�c�dan; isim, soyisim ve s�nav notlar�n� for d�ng�s� i�inde alarak array'lere yerle�tiriyoruz
				printf("Adi: ");
				scanf("%s", &ad[i]);
				printf("Soyadi: ");
				scanf("%s", &soyad[i]);
				printf("1.Ara Sinav, 2.Ara Sinav, Final: ");
				scanf("%d %d %d", &vize1[i], &vize2[i], &final[i]);
				ogrenciSayisi++;
				printf("\n");
				if(ogrenciSayisi == MEVCUT){
					printf("Sinif mevcudu dolu!\n\n");
				}
			}
			
			printf("Ad\tSoyad\tVize1\tVize2\tFinal\n");
			
			int j=0;
			for(j; j<MEVCUT; j++){ //kullan�c� kay�tlar� listeledikten sonra table halinde g�steren for d�ng�s�
				printName(ad, j);
				printf("\t%c.\t%d\t%d\t%d\n", soyad[j], vize1[j], vize2[j], final[j]);
			}
			printf("\n");
			CalculateNotes(notu, vize1, vize2, final);
			break;
			
		
		case 2://Kullan�c� se�imde 2'ye bast���nda case 2'deki kay�t listeleme i�lemleri yap�lacak
		
		if(ogrenciSayisi != 0){
			printf("---Kayitlari Listele---\n");
		
			printf("Ad\tSoyad\tVize1\tVize2\tFinal\tNotu\tHarf\tDurumu\n");
			
			int i=0;
			for(i; i<MEVCUT; i++){
				printName(ad, i);
				printf("\t%c.\t%d\t%d\t%d\t%d\t%s\t%s\n", soyad[i], vize1[i], vize2[i], final[i], notu[i], HarfNotu(notu[i]), OgrenciDurumu(notu[i]));
			}
			printf("\n");
		
			break;
		}
		
		else{
			KayitGerceklestirUyarisi();
			break;
		}

		case 3://Kullan�c� se�imde 3'e bast���nda case 3'teki kay�t listeleme i�lemleri yap�lacak
		
		if(ogrenciSayisi != 0){
			printf("---Sinif Basari Notlarini Hesapla---\n");
			
			printf("Ad\tSoyad\tNotu\n");
			
			int i=0;
			for(i ;i<MEVCUT; i++){ 
				printName(ad, i);
				printf("\t%c.\t%d\n", soyad[i], notu[i]);
			}
			printf("\n");
			
			break;
		}
		
		else{
			KayitGerceklestirUyarisi();
			break;
		}
		
		case 4://Kay�tlar� ba�ar� notuna g�re hesapla
		
		if(ogrenciSayisi != 0){
			printf("---Kayitlari Basari Notuna Gore Sirala---\n");
		
		//tam a�a��daki for d�ng�s�n�n i�inde as�l yapmak istedi�imiz �ey notlar� b�y�kten k����e do�ru s�ralamak. Bunu da �u �ekil yap�yoruz; �rne�in 1. indeks 2.indeksten k���k. 
		//1.indeksi geciciSayi olarak tan�mlad���m�z de�i�kene tutumas� i�in at�yoruz. Sonras�nda 2.indeksin de�erini 1.indeksin yerine at�yoruz ��nk� 2. indeksin de�eri 1.'sinden b�y�k bu y�zden array'in i�inde daha
		//�n s�ralarda olmal�. Sonras�nda da 1.indeksteki de�eri de 2.indekse yerle�tiriyoruz. Bu i�lemi her notu[j]<notu[j+1] i�lemi i�in teker teker yap�yoruz.
		//e�er s�ralama i�lemini sadece notlar i�in yaparsak geri kalan ��renci bilgileri(isim, soyisim, vize1, final vb.) oldu�u gibi kalm�� olur ve sadece notlar� s�ralar.
		//bunun olmas�n� istemedi�imiz i�in b�t�n array'lere, notu array'ine uygulad���m�z indeks de�i�imlerini uygular�z.
			
			int i;
			int j;
			for(i=0; i<MEVCUT; i++){
				for(j=i+1; j<MEVCUT; j++){
					if(notu[j]>notu[i]){
						geciciSayi = notu[j];
						notu[j] = notu[i];
						notu[i] = geciciSayi;
						
						geciciSayi = vize1[j];
						vize1[j] = vize1[i];
						vize1[i] = geciciSayi;
						
						geciciSayi = vize2[j];
						vize2[j] = vize2[i];
						vize2[i] = geciciSayi;
						
						geciciSayi = final[j];
						final[j] = final[i];
						final[i] = geciciSayi;
						
						geciciString = soyad[j];
						soyad[j] = soyad[i];
						soyad[i] = geciciString;
						
						char t[6]; //t array'ini yukar�da kulland���m�z geciciSayi ya da geciciString gibi d���nebiliriz.
						strcpy(t,ad[j]); //strcpy bir string'i ba�a bir string'e kopyalamak i�in kullan�larn bir metottur. buradaki t array'ine ad array'imi kopyal�yorum.
						strcpy(ad[j],ad[i]);//sonras�nda as�l b�y�k de�ere sahip olan array'i �z array'ime at�yorum.
						strcpy(ad[i], t);//sonra ise ge�ici olarak de�erleri tutmas�n� istedi�im array'imi daha b�y�k indeksteki array'ime at�yorum
					}
				}
			}
			printf("Ad\tSoyad\tVize1\tVize2\tFinal\tNotu\tHarf\tDurumu\n");
			
			int k;
			for(k=0; k<MEVCUT; k++){ 
				printName(ad, k);
				printf("\t%c.\t%d\t%d\t%d\t%d\t%s\t%s\n", soyad[k], vize1[k], vize2[k], final[k], notu[k], HarfNotu(notu[k]), OgrenciDurumu(notu[k]));
			}
			printf("\n");
			break;
			}
		
			else{
				KayitGerceklestirUyarisi();
				break;
			}
		
		case 5://�statistiki bilgiler
			if(ogrenciSayisi != 0){
				printf("---Istatistiki bilgiler---\n");
			
				max = EnYuksekNotuBulma(notu); //EnYuksekNotuBulma fonksiyonuna notlar�m�z�n array'ini g�nderdik ve bize en y�ksek notu d�nd�rd� bunu da max de�i�kenine atad�k.
				min = EnDusukNotuBulma(notu); //Ayn� �ekilde EnDusukNotuBulma fonksiyonuna notlar�m�z�n array'ini yollad�k ve bize en d���k notu d�nd�rd� biz de onu min de�i�kenine atad�k.
				
				//Alttaki i�lem: s�n�f ortalamas� de�i�kenine �ncelikle t�m notlar� at�yoruz. D�ng�n�n sonunda s�n�fOrtalamas� de�i�keni b�t�n ��renci notlar�n�n toplam� oluyor.
				//Sonras�nda bu de�i�keni s�n�f mevcuduna b�l�p e�itliyoruz.
				
				int i=0;
				for(i;i<MEVCUT; i++){
					sinifOrtalamasi = sinifOrtalamasi + notu[i];
				}
				sinifOrtalamasi /= MEVCUT;
				
				//Alttaki for d�ng�s�nde yukar�da hesaplad���m�z s�n�fOrtalamas� de�i�keninden b�y�k olan notlar var ise e�er ortalamaUstu de�i�kenini bir artt�r�yoruz ve
				//toplam ka� ki�inin s�n�f ortalamas�n�n �st�nde oldu�unu buluyoruz
				int j=0;
				for(j; j<MEVCUT; j++){
					if(notu[j] > sinifOrtalamasi){
						ortalamaUstu++;
					}
				}
				
				//Alttaki for d�ng�s�nde HarfNotu() fonksiyonuna notlar�m�z� parametre olarak g�nderiyoruz ve e�er bu notlar FF de�illerse basariOrani de�i�kenini 1 artt�r�yoruz
				//b�ylelikle basariOrani de�i�keni dersi ge�en ki�ilerin say�s� kadar olmu� oluyor
				int k=0;
				for(k; k<MEVCUT; k++){
					if(HarfNotu(notu[k]) == "AA" || "BA" || "BB" || "CB" || "CC" || "DC" || "DD" || "FD"){
						basariOrani++;
					}
				}
				
				//Standart Sapma i�lemleri
				int b=0;
				for(b ;b<MEVCUT; b++){
					standartSapma += pow((sinifOrtalamasi - notu[b]) , 2);
				}
				
				standartSapma = sqrt(standartSapma/(MEVCUT-1));
				
				printf("En Yuksek Not : %d\n", max);
				printf("En Dusuk Not : %d\n", min);
				printf("Sinif Ortalamasi : %d\n", sinifOrtalamasi);
				printf("Ortalama Ustu Kisi Sayisi : %d - Basari Orani %%%d\n", ortalamaUstu, basariOrani*10);
				printf("Standart Sapma : %f", (float)standartSapma);
				printf("\n\n");
				
				break;
			}
			
			else{
				KayitGerceklestirUyarisi();
				break;
			}

		case 6: //programdan ��kmak i�in kullan�c� -1'e basar ve program sonlan�r
			printf("Programi sonlandirdiniz... Hoscakalin!");
			a = 0;
			break;
		
		default://men�deki say�lar haricinde ba�ka bir say� se�meye �al���rsa e�er kullan�c�, hata verecek
			printf("Lutfen menudeki 6 secenekten birini seciniz.\n\n");
			break;
	}
}
	return 0;
}
