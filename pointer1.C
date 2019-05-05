#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"

#define OGRENCISAYISI 3
#define SINAVSAYISI 4

typedef struct{
	char *isim_soyisim_;
	float s[4];//sondaki final
}ogrenci_;

void girdileriAl(ogrenci_ *);
void analiz(ogrenci_ *);
int main()
{
	ogrenci_ *_ogrenci_;
	_ogrenci_ = (ogrenci_*)malloc(sizeof(ogrenci_)*OGRENCISAYISI);
	girdileriAl(_ogrenci_);
	analiz(_ogrenci_);
	
	return -1;
}
void analiz(ogrenci_ *ogrenciler)
{
	uint8_t j;
	uint16_t i;
	float ortalama;
	system("cls");
	for(i=0;i<OGRENCISAYISI;i++)
	{
		ortalama = 0;
		printf("-----------%s isimli ogrenci-----------\n",ogrenciler[i].isim_soyisim_);
		for(j=0;j<SINAVSAYISI;j++)
		{
			printf("%d. sinav: %.2f\n",j+1,ogrenciler[i].s[j]);
			(j!=(OGRENCISAYISI-1))?ortalama+=ogrenciler[i].s[j]*0.2:(ortalama+=ogrenciler[i].s[j]*0.4);
	}
		printf("-----Ortalama: %.2f-----\n\n\n\n",ortalama);
	}
}
void girdileriAl(ogrenci_ *ogrenciler)
{
	char veri[30];
	
	uint8_t j;
	uint16_t i;
	for(i=0;i<OGRENCISAYISI;i++)
	{
		printf("isim soyisim:");
		gets(veri);
		ogrenciler[i].isim_soyisim_ = (char*)malloc(sizeof(char)*(sizeof(veri)+1));
		strcpy(ogrenciler[i].isim_soyisim_,veri);
		for(j=0;j<SINAVSAYISI;j++)
		{
			printf("%d. sinav:",j+1);
			scanf("%f",&ogrenciler[i].s[j]);
		}
		getchar();
	}
}
