#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MEVCUT 10 //öðrenci sayýsý burada sabit olarak tanýmlandý

void MenuGosterimi(){ //Menüyü liste halinde gösteren fonksiyon.
	printf("MENU\n1-Kayit Ekle\n2-Kayitlari Listele\n3-Sinif basari notlarini hesapla\n4-Kayitlari basari notuna gore hesapla\n5-Istatistiki bilgiler\n6-Cikis\n\n");
}

int NotHesaplama(float vize1, float vize2, float final){//Öðrencinin not ortalamasýný hesaplayýp geriye döndüren fonksiyon
	int sonuc = 0; 
	sonuc = round((vize1*20)/100 + (vize2*30)/100 + (final*50)/100); //notlarý hesaplarken yuvarlama iþlemini round ile yaptým
	
	return sonuc;
}

int EnYuksekNotuBulma(int notlar[]){ //parametre olarak aldýðý dizideki en yüksek sayýyý geriye döndüren fonksiyon
	int max = notlar[0];
	int i=0;
	for(i; i<MEVCUT; i++){
			if(max < notlar[i]){
				max = notlar[i];
			}
	}
	return max;
}

int EnDusukNotuBulma(int notlar[]){ //parametre olarak aldýðý dizideki en düþük sayýyý geriye döndüren fonksiyon
	int min = notlar[0];
	int i=0;
	for(i; i<MEVCUT; i++){
			if(min > notlar[i]){
				min = notlar[i];
			}
	}
	return min;
}

const char* HarfNotu(int notu){ //Öðrencinin notunu parametre olarak alýp, hangi harf notuna sahip olduðunu aralýklarla hesaplayýp ona göre string deðer döndüren fonksiyon.
		//notumuz bize parametre olarak geldi. notumuzun hangi harf notuna sahip olacaðýný öðrenmemiz gerekiyor. 7 adet if yapýsý oluþturduk ve bu yapýlara parantez içinde aralýklar verdik.
		//notumuz hangi aralýða dahilse o if bloðuna girecek ve girdiði bloðun harf notunu return ile döndürecek.
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

const char* OgrenciDurumu(int notu){ //Öðrenci durumunu, notunu parametre olarak alarak geriye döndüren fonksiyon
	if(notu<=49){
		return "Kaldi";
	}
	else if(notu<=59 && notu>=50){
		return "Sartli Gecti";
	}
	
	return "Gecti";
}

void printName(char ad[][7], int i) {//isimleri table'a yazdýrdýðýmýz fonksiyon
	int j=0;
	for(j; ad[i][j]!= '\0'; j++){
		printf("%c", ad[i][j]);
	}
}

void CalculateNotes(int notu[], int vize1[], int vize2[], int final[]) { //Notlarý hesaplayýp notu array'ine attýðýmýz fonksiyon. Benzer isimle baþka bir fonksiyon olduðu için ingilizce isim verdim.
    int i=0;
	for(i; i<MEVCUT; i++){ //Öðrencilerin notlarýný depolayan notu[] array'ine, NotHesaplama fonksiyonu ile hesaplatarak teker teker for döngüsü ile gönderiyoruz.
		notu[i] = NotHesaplama(vize1[i], vize2[i], final[i]);
	}
}

void KayitGerceklestirUyarisi(){ //Kayýt iþlemi gerçekleþtir uyarýsýný printf'le yazdýrdýðýmýz fonksiyon
	printf("Kisi eklemeden basari notu hesaplanamaz! Sinif kayit ekranindan kayit ekleme islemi gerceklestiriniz.\n\n");
}


int main(int argc, char *argv[]) {
	
	int secim;
	
	//öðrencilerin isim, soyisim ve notlarýný depolayan array tanýmlamalarý:
	char ad[MEVCUT][7];
	char soyad[MEVCUT];
	
	int vize1[MEVCUT];
	int vize2[MEVCUT];
	int final[MEVCUT];
	
	int notu[MEVCUT];
	char harfNotu[MEVCUT];
	
	int ogrenciSayisi = 0; //öðrenci her girdiðinde deðiþkenimiz 1 artacak. Bu deðiþkenin amacý; eðer öðrenci hiç girilmemiþse ve kullanýcý menü 2,3,4,5'ten birine basmaya çalýþýyorsa 
	//ona uyarý verilmesi için kontrol amacýyla oluþturuldu
	
	int a = 1;//a deðiþkeni çýkýþ iþlemi için tanýmlandý ve döngüye parantez içinde koþul olarak verildi. kullanýcý 6.menüyü iþaretlediðinde a deðiþkeni 0 oluyor ve döngüye bir daha girilemiyor.

	
	int geciciSayi = 0;
	char geciciString;
	
	int max = 0; //en büyük sayý deðiþkeni
	int min = 0; //en küçük sayý deðiþkeni
	int sinifOrtalamasi = 0; //sýnýf ortalamasý
	int ortalamaUstu = 0; //ortalamanýn üstünde olan öðrenciler kadar büyüklüðü olan deðiþken
	int basariOrani = 0; //baþarý oraný/10 kadar büyüklüðü olan deðiþken
	float standartSapma = 0.00;
	
	while(a){
		
		MenuGosterimi();
		
		printf("Bir islem seciniz: ");
		scanf("%d", &secim);
		printf("\n");
		
		switch(secim){
			
		case 1://Kullanýcý seçimde 1'e bastýðýnda case 1'deki kayýt ekle iþlemleri yapýlacak
			
			printf("---Kayit Ekle---\n");
			int i=0;
			for(i; i<MEVCUT; i++){ //kullanýcýdan; isim, soyisim ve sýnav notlarýný for döngüsü içinde alarak array'lere yerleþtiriyoruz
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
			for(j; j<MEVCUT; j++){ //kullanýcý kayýtlarý listeledikten sonra table halinde gösteren for döngüsü
				printName(ad, j);
				printf("\t%c.\t%d\t%d\t%d\n", soyad[j], vize1[j], vize2[j], final[j]);
			}
			printf("\n");
			CalculateNotes(notu, vize1, vize2, final);
			break;
			
		
		case 2://Kullanýcý seçimde 2'ye bastýðýnda case 2'deki kayýt listeleme iþlemleri yapýlacak
		
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

		case 3://Kullanýcý seçimde 3'e bastýðýnda case 3'teki kayýt listeleme iþlemleri yapýlacak
		
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
		
		case 4://Kayýtlarý baþarý notuna göre hesapla
		
		if(ogrenciSayisi != 0){
			printf("---Kayitlari Basari Notuna Gore Sirala---\n");
		
		//tam aþaðýdaki for döngüsünün içinde asýl yapmak istediðimiz þey notlarý büyükten küçüðe doðru sýralamak. Bunu da þu þekil yapýyoruz; örneðin 1. indeks 2.indeksten küçük. 
		//1.indeksi geciciSayi olarak tanýmladýðýmýz deðiþkene tutumasý için atýyoruz. Sonrasýnda 2.indeksin deðerini 1.indeksin yerine atýyoruz çünkü 2. indeksin deðeri 1.'sinden büyük bu yüzden array'in içinde daha
		//ön sýralarda olmalý. Sonrasýnda da 1.indeksteki deðeri de 2.indekse yerleþtiriyoruz. Bu iþlemi her notu[j]<notu[j+1] iþlemi için teker teker yapýyoruz.
		//eðer sýralama iþlemini sadece notlar için yaparsak geri kalan öðrenci bilgileri(isim, soyisim, vize1, final vb.) olduðu gibi kalmýþ olur ve sadece notlarý sýralar.
		//bunun olmasýný istemediðimiz için bütün array'lere, notu array'ine uyguladýðýmýz indeks deðiþimlerini uygularýz.
			
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
						
						char t[6]; //t array'ini yukarýda kullandýðýmýz geciciSayi ya da geciciString gibi düþünebiliriz.
						strcpy(t,ad[j]); //strcpy bir string'i baþa bir string'e kopyalamak için kullanýlarn bir metottur. buradaki t array'ine ad array'imi kopyalýyorum.
						strcpy(ad[j],ad[i]);//sonrasýnda asýl büyük deðere sahip olan array'i öz array'ime atýyorum.
						strcpy(ad[i], t);//sonra ise geçici olarak deðerleri tutmasýný istediðim array'imi daha büyük indeksteki array'ime atýyorum
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
		
		case 5://Ýstatistiki bilgiler
			if(ogrenciSayisi != 0){
				printf("---Istatistiki bilgiler---\n");
			
				max = EnYuksekNotuBulma(notu); //EnYuksekNotuBulma fonksiyonuna notlarýmýzýn array'ini gönderdik ve bize en yüksek notu döndürdü bunu da max deðiþkenine atadýk.
				min = EnDusukNotuBulma(notu); //Ayný þekilde EnDusukNotuBulma fonksiyonuna notlarýmýzýn array'ini yolladýk ve bize en düþük notu döndürdü biz de onu min deðiþkenine atadýk.
				
				//Alttaki iþlem: sýnýf ortalamasý deðiþkenine öncelikle tüm notlarý atýyoruz. Döngünün sonunda sýnýfOrtalamasý deðiþkeni bütün öðrenci notlarýnýn toplamý oluyor.
				//Sonrasýnda bu deðiþkeni sýnýf mevcuduna bölüp eþitliyoruz.
				
				int i=0;
				for(i;i<MEVCUT; i++){
					sinifOrtalamasi = sinifOrtalamasi + notu[i];
				}
				sinifOrtalamasi /= MEVCUT;
				
				//Alttaki for döngüsünde yukarýda hesapladýðýmýz sýnýfOrtalamasý deðiþkeninden büyük olan notlar var ise eðer ortalamaUstu deðiþkenini bir arttýrýyoruz ve
				//toplam kaç kiþinin sýnýf ortalamasýnýn üstünde olduðunu buluyoruz
				int j=0;
				for(j; j<MEVCUT; j++){
					if(notu[j] > sinifOrtalamasi){
						ortalamaUstu++;
					}
				}
				
				//Alttaki for döngüsünde HarfNotu() fonksiyonuna notlarýmýzý parametre olarak gönderiyoruz ve eðer bu notlar FF deðillerse basariOrani deðiþkenini 1 arttýrýyoruz
				//böylelikle basariOrani deðiþkeni dersi geçen kiþilerin sayýsý kadar olmuþ oluyor
				int k=0;
				for(k; k<MEVCUT; k++){
					if(HarfNotu(notu[k]) == "AA" || "BA" || "BB" || "CB" || "CC" || "DC" || "DD" || "FD"){
						basariOrani++;
					}
				}
				
				//Standart Sapma iþlemleri
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

		case 6: //programdan çýkmak için kullanýcý -1'e basar ve program sonlanýr
			printf("Programi sonlandirdiniz... Hoscakalin!");
			a = 0;
			break;
		
		default://menüdeki sayýlar haricinde baþka bir sayý seçmeye çalýþýrsa eðer kullanýcý, hata verecek
			printf("Lutfen menudeki 6 secenekten birini seciniz.\n\n");
			break;
	}
}
	return 0;
}
