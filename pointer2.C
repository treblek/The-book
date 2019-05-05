#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "string.h"

#define PAZARLAMACI_SAYISI 2

const float satisOrtalama;

typedef struct
{
	char *isim_soyisim_;
	float yapilan_satis_;
	float maas_;
	float komisyon_;
}elemanlar_;

void girdileriAl(elemanlar_ *);
void analiz(elemanlar_ *);
void analizYazdir(elemanlar_ *);
int main()
{
	elemanlar_ *_elemanlar_;
	_elemanlar_ = (elemanlar_*)malloc(sizeof(elemanlar_)*PAZARLAMACI_SAYISI);
	girdileriAl(_elemanlar_);
	analizYazdir(_elemanlar_);
	return -1;
}

void analizYazdir(elemanlar_ *elemanlar)
{
	system("cls");
	uint8_t i;
	for(i=0;i<PAZARLAMACI_SAYISI;i++)
	{
		printf("SATIS ORTALAMASI: %f\n",satisOrtalama);
		printf("----------------------------\n");
		printf("%s isimli eleman %f maas ile %f satis yaparak\n %f komisyon aldi ve alacagi maas %f oldu.\n",elemanlar[i].isim_soyisim_,elemanlar[i].maas_,elemanlar[i].yapilan_satis_,elemanlar[i].komisyon_,elemanlar[i].maas_+elemanlar[i].komisyon_);
		printf("----------------------------\n");
	}
}

void girdileriAl(elemanlar_ *elemanlar)
{
	uint8_t i;
	char veri[30];
	for(i=0;i<PAZARLAMACI_SAYISI;i++)
	{
		printf("%d. eleman:\n",i+1);
		printf("adi soyadi: ");
		gets(veri);
		elemanlar[i].isim_soyisim_ = (char*)malloc(sizeof(char)*(sizeof(veri)+1));
		strcpy(elemanlar[i].isim_soyisim_,veri);
		printf("maas:");
		scanf("%f",&elemanlar[i].maas_);
		printf("yapilan satis: ");
		scanf("%f",&elemanlar[i].yapilan_satis_);
		getchar();
	}
	analiz(elemanlar);
}

void analiz(elemanlar_ *elemanlar)
{
	uint8_t i;
	float *ortalama;
	ortalama = &satisOrtalama;

	for(i=0;i<PAZARLAMACI_SAYISI;i++)
	{
		if(elemanlar[i].yapilan_satis_>=5000)
		elemanlar[i].komisyon_= elemanlar[i].maas_*0.06;	
		else
		elemanlar[i].komisyon_= elemanlar[i].maas_*0.04;
		
		*ortalama += elemanlar[i].yapilan_satis_;
	}
	*ortalama /= PAZARLAMACI_SAYISI;
	
	for(i=0;i<PAZARLAMACI_SAYISI;i++)
		if(elemanlar[i].yapilan_satis_>*ortalama)
			elemanlar[i].komisyon_+= 500;
			
}
