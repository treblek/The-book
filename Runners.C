#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"


/*-----------------------------------------------------------------*/
#define KOSUCUSAYISI 3

/*-----------------------------------------------------------------*/
typedef enum{
turkiye,
fransa,
azerbaycan,
lubnan,
kenya}ulkeler;

typedef enum
{
	erkek,
	kadin
}cinsiyetler;

/*-----------------------------------------------------------------*/
typedef struct
{
	uint8_t saat_;
	uint8_t dakika_;
	uint8_t saniye_;
	uint8_t salise_;
}zaman_;

typedef struct
{
	char *isim_soyisim_;
	ulkeler ulke_;
	cinsiyetler cinsiyet_;
	zaman_ bitis_zamani_;
	
}kosucu_;
/*-----------------------------------------------------------------*/
void bilgileriAl(kosucu_ *);
void yazdir(kosucu_ *);
/*-----------------------------------------------------------------*/
int main()
{
	kosucu_ *_kosucu_;
	_kosucu_ = (kosucu_*)malloc(sizeof(kosucu_)*KOSUCUSAYISI);
	bilgileriAl(_kosucu_);
	yazdir(_kosucu_);
	return -1;
}
/*-----------------------------------------------------------------*/
void yazdir(kosucu_ *kosucular)
{
	uint32_t erkekAltinMadalya,kadinAltinMadalya,enIyiZamanTurk=86400,erkekEnIyiZaman=86400,kadinEnIyiZaman=86400,enIyiTurk;
	uint8_t i;
	for(i=0;i<KOSUCUSAYISI;i++)
	{
		if(kosucular[i].cinsiyet_==0)
		{
			if(kosucular[i].bitis_zamani_.saat_*3600+kosucular[i].bitis_zamani_.dakika_*60+kosucular[i].bitis_zamani_.saniye_<erkekEnIyiZaman)
		{
			erkekEnIyiZaman = kosucular[i].bitis_zamani_.saat_*3600+kosucular[i].bitis_zamani_.dakika_*60+kosucular[i].bitis_zamani_.saniye_;
			erkekAltinMadalya = i;
		}
		}
		else
		{
			if(kosucular[i].bitis_zamani_.saat_*3600+kosucular[i].bitis_zamani_.dakika_*60+kosucular[i].bitis_zamani_.saniye_<kadinEnIyiZaman)
		{
			kadinEnIyiZaman = kosucular[i].bitis_zamani_.saat_*3600+kosucular[i].bitis_zamani_.dakika_*60+kosucular[i].bitis_zamani_.saniye_;
			kadinAltinMadalya = i;
		}
		}
		
		if(kosucular[i].ulke_ == 0)
		{
			if(kosucular[i].bitis_zamani_.saat_*3600+kosucular[i].bitis_zamani_.dakika_*60+kosucular[i].bitis_zamani_.saniye_<enIyiZamanTurk)
			{
				enIyiZamanTurk = kosucular[i].bitis_zamani_.saat_*3600+kosucular[i].bitis_zamani_.dakika_*60+kosucular[i].bitis_zamani_.saniye_;
				enIyiTurk = i;
			}
		}
			
	}
	system("cls");
	printf("Altin madalya kazanan erkek :%s\n",kosucular[erkekAltinMadalya].isim_soyisim_);
	printf("Altin madalya kazanan kadin :%s\n",kosucular[kadinAltinMadalya].isim_soyisim_);
	printf("En iyi Turk: %s",kosucular[enIyiTurk].isim_soyisim_);
}
void bilgileriAl(kosucu_ *kosucular)
{
	uint16_t i;
	char veri[30];
	uint8_t veri2;
	for(i=0;i<KOSUCUSAYISI;i++)
	{
		printf("%d. kosucunun: \n",i+1);
		printf("isim soyisim: ");
		gets(veri);
		kosucular[i].isim_soyisim_ = (char*)malloc(sizeof(char)*(sizeof(veri)+1));
		strcpy(kosucular[i].isim_soyisim_,veri);
		printf("ulke: 0-turkiye 1-fransa 2-azerbaycan 3-lubnan 4-kenya");
		scanf("%d",&veri2);
		kosucular[i].ulke_ = veri2;
		printf("cinsiyet: 0-erkek 1- bayan");
		scanf("%d",&veri2);
		kosucular[i].cinsiyet_ = veri2;
	    printf("yaris bitim saat: ");
	    scanf("%d",&kosucular[i].bitis_zamani_.saat_);
	    printf("yaris bitim dakika: ");
	    scanf("%d",&kosucular[i].bitis_zamani_.dakika_);
	    printf("yaris bitim saniye");
	    scanf("%d",&kosucular[i].bitis_zamani_.saniye_);
	     printf("yaris bitim salise");
	    scanf("%d",&kosucular[i].bitis_zamani_.salise_);
	    getchar();
	}
}
