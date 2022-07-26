#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

int toplam=0,sayac=0;
int Biletturu,filmSec,salonSec;
char islemDevam;
typedef enum {Yenilmezler,Dangal,Gokdelen}Film;
struct salonlar
{
   char SalonIsmi[20];
   int *koltuk[50];
   int matina;
   Film film;
   char filmler[50];
}Red,Green,Blue ;

void LoginEkrani();
void ToplamHasilat();
void BiletTuru();
void SalonSecMatinaSec();
void Bilgilendirme();

int main()
{
    Menu:  LoginEkrani();
           BiletTuru();
           SalonSecMatinaSec();
           printf("\n\n");
           Bilgilendirme();
           ToplamHasilat();
           printf("\n");
           printf("Isleminiz sonlanmistir.\n\n");
           printf("Tekrar bilet almak icin [e/E]'ye basiniz , islemi tamamen bitirmek icin [h/H]'a basiniz.");
           scanf(" %c",&islemDevam);
           if((islemDevam=='e')|| (islemDevam=='E'))
            goto Menu;
           else
             printf("\nIyi seyirler.\n");
    return 0;
}
void LoginEkrani()
{
   int sec;
   printf("----Hos Geldiniz----\n");
   printf("1-Kayit Ol\n");
   printf("2-Giris Yap\n");
   scanf("%d",&sec);
   if(sec==1)
   {
       KayitOl();
   }
   if(sec==2)
   {
       GirisYap();
   }
   printf("\n");
}
void KayitOl()
{
   char kullaniciAd[50];
   char sifre[20];
   FILE *fp;
   fp=fopen("sifre.txt","a");
   printf("Kullanici Ad :");
   scanf("%s",&kullaniciAd);
   printf("Sifre : ");
   scanf("%s",&sifre);
   fprintf(fp,"%s%s",kullaniciAd,sifre);
   fclose(fp);
   LoginEkrani();
}
void GirisYap()
{
   char kullanici[50];
   char karakter[50],sifre[50];
   FILE *fp;
   fp=fopen("sifre.txt","r");
   printf("Kullanici Adi :");
   scanf("%s",&kullanici);
   printf("\n");
   printf("Sifre :");
   scanf("%s",&sifre);
   fgets(karakter,25,fp);
   strcat(kullanici,sifre);

   if(strcmp(karakter,kullanici)==0 )
   {
      printf("Kullanici adini ve sifreyi dogru.!\n");
   }
   else
   {
      printf("\nKullanici adini veya sifreyi yanlis girdiniz.!\n");
      printf("Lutfen tekrar deneyiniz.\n\n");
      GirisYap();
   }
   fclose(fp);
}
void ToplamHasilat()
{
   printf("Toplam Ucret:%d TL\n",toplam);
   FILE *fp1;
   fp1=fopen("ToplamHasilat.txt","a");
   fprintf(fp1,"%s %d %s   \n","Toplam Ucret:",toplam,"TL");
}
void BiletTuru()
{
   printf("1-Ogrenci \n2-Tam\n");
    printf("Almak istediginiz bilet turunu giriniz.\n");
    scanf("%d",&Biletturu);

    if(Biletturu==1)
    {
       sayac++;
       toplam+=20;
    }
    if(Biletturu==2)
    {
       sayac++;
       toplam+=30;
    }
}
void SalonSecMatinaSec()
{
   printf("---Salonlar---\n");
      printf("1-Red\n");
      printf("2-Green\n");
      printf("3-Blue\n");

  Menu1:    printf("Lutfen salon seciniz?\n");
      scanf("%d",&salonSec);

      if(salonSec<4 && salonSec>0)
      {
         if( salonSec==1 )
      {
         strcpy(Red.SalonIsmi,"Red");
         printf("Sectiginiz Salon :%s\n",Red.SalonIsmi);
  Menu11: printf("Hanigi matina da bilet almak istersiniz.[1,2,3,4,5]\n");
         scanf("%d",&Red.matina);
         if(Red.matina>0 && Red.matina<6)
         {
            printf("Secilen Matina :%d\n",Red.matina);
         }
         else
         {
            printf("Lutfen 1 ile 5 arasinda bir deger giriniz.\n");
            goto Menu11;
         }
         printf("1-Yenilmezler\n");
         printf("2-Dangal\n");
         printf("3-Gokdelen\n");
         printf("Lutfen izlemek istediginiz filmi seciniz.\n");
         scanf("%d",&filmSec);
         if(filmSec==1)
         {
            strcpy(Red.filmler,"Yenilmezler");
            printf("Secilen film :%s\n",Red.filmler);
         }
         if(filmSec==2)
         {
            strcpy(Red.filmler,"Dangal");
            printf("Secilen film :%s\n",Red.filmler);
         }
         if(filmSec==3)
         {
            strcpy(Red.filmler,"Gokdelen");
            printf("Secilen film :%s\n",Red.filmler);
         }//pointer struct icinden alýnma
           srand(time(NULL));
           for(int i=1;i<2;i++)
           {
              if(Red.koltuk[i]==NULL)
              {
                 Red.koltuk[i]=rand()%49+1;
                printf("Secilen Koltuk No :%d\n",Red.koltuk[i]);
              }
              else
              {
                 printf("Sectiginiz koltuk doludur.Lutfen baska bir koltuk seciniz\n");
                 goto Menu1;
              }
           }
      }
      if(salonSec==2)
      {
         strcpy(Green.SalonIsmi,"Green");
         printf("Sectiginiz Salon :%s\n",Green.SalonIsmi);
 Menu12: printf("Hanigi matina da bilet almak istersiniz.(1,2,3,4,5)\n");
         scanf("%d",&Green.matina);
         if(Green.matina>0 && Green.matina<6)
         {
            printf("Secilen Matina :%d\n",Green.matina);
         }
         else
         {
            printf("Lutfen 1 ile 5 arasinda bir deger giriniz.\n");
            goto Menu12;
         }
         printf("1-Yenilmezler\n");
         printf("2-Dangal\n");
         printf("3-Gokdelen\n");
         printf("Lutfen izlemek istediginiz filmi seciniz.\n");
         scanf("%d",&filmSec);
         if(filmSec==1)
         {
            strcpy(Green.filmler,"Yenilmezler");
            printf("Secilen film :%s\n",Green.filmler);
         }
         if(filmSec==2)
         {
            strcpy(Green.filmler,"Dangal");
            printf("Secilen film :%s\n",Green.filmler);
         }
         if(filmSec==3)
         {
            strcpy(Green.filmler,"Gokdelen");
            printf("Secilen film :%s\n",Green.filmler);
         }
         srand(time(NULL));
           for(int i=1;i<2;i++)
           {
              if(Green.koltuk[i]==NULL)
              {
                  Green.koltuk[i]=rand()%49+1;
                printf("Secilen Koltuk No :%d\n",Green.koltuk[i]);
              }
              else
              {
                 printf("Sectiginiz koltuk doludur.Lutfen baska bir koltuk seciniz\n");
                 goto Menu1;
              }
           }
      }
      if(salonSec==3)
      {
         strcpy(Blue.SalonIsmi,"Green");
         printf("Sectiginiz Salon :%s\n",Blue.SalonIsmi);
 Menu13: printf("Hangi matina da bilet almak istersiniz.(1,2,3,4,5)\n");
         scanf("%d",&Blue.matina);
         if(Blue.matina>0 && Blue.matina<6)
         {
            printf("Secilen Matina :%d\n",Blue.matina);
         }
         else
         {
            printf("Lutfen 1 ile 5 arasinda bir deger giriniz.\n");
            goto Menu13;
         }
         printf("1-Yenilmezler\n");
         printf("2-Dangal\n");
         printf("3-Gokdelen\n");
         printf("Lutfen izlemek istediginiz filmi seciniz.\n");
         scanf("%d",&filmSec);
         if(filmSec==1)
         {
            strcpy(Blue.filmler,"Yenilmezler");
            printf("Secilen film :%s\n",Blue.filmler);
         }
         if(filmSec==2)
         {
            strcpy(Blue.filmler,"Dangal");
            printf("Secilen film :%s\n",Blue.filmler);
         }
         if(filmSec==3)
         {
            strcpy(Blue.filmler,"Gokdelen");
            printf("Secilen film :%s\n",Blue.filmler);
         }
        srand(time(NULL));
           for(int i=1;i<2;i++)
           {
              if(Blue.koltuk[i]==NULL)
              {
                 Blue.koltuk[i]=rand()%49+1;
                printf("Secilen Koltuk No :%d\n",Blue.koltuk[i]);
              }
              else
              {
                 printf("Sectiginiz koltuk doludur.Lutfen baska bir koltuk seciniz\n");
                 goto Menu1;
              }
           }
      }
   }
   else
   {
      printf("Lutfen 1 ile 3 degeri arasinda bir deger giriniz.\n");
      goto Menu1;
   }

}
void Bilgilendirme()
{
   int i=1;
   FILE *fp2;
   fp2=fopen("Bilgilendirme.txt","a");
   printf("-----BILGILENDIRME-----\n");
   if(salonSec==1)
   {
       printf("Secilen Salon :%s\n",Red.SalonIsmi);
       printf("Secilen Matina :%d\n",Red.matina);
       printf("Secilen Film :%s\n",Red.filmler);
       printf("Filme alinan bilet sayisi :%d\n",sayac);
       printf("Koltuk No:%d\n",*(Red.koltuk+1));
       fprintf(fp2,"%s %s    %s %d    %s %s    %s %d    %s %d    \n","Salon Adi:",Red.SalonIsmi,"Matina No:",Red.matina,"Secilen Film:",Red.filmler,"Alinan Bilet Sayisi:",sayac,"Koltuk No:",*(Red.koltuk+1));
   }
  if(salonSec==2)
   {
       printf("Secilen Salon :%s\n",Green.SalonIsmi);
       printf("Secilen Matina :%d\n",Green.matina);
       printf("Secilen Film :%s\n",Green.filmler);
       printf("Filme alinan bilet sayisi :%d\n",sayac);
       printf("Koltuk No:%d\n",*(Green.koltuk+1));
       fprintf(fp2,"%s %s    %s %d    %s %s    %s %d    %s %d    \n","Salon Adi:",Green.SalonIsmi,"Matina No:",Green.matina,"Secilen Film:",Green.filmler,"Alinan Bilet Sayisi:",sayac,"Koltuk No:",*(Green.koltuk+1));
   }
   if(salonSec==3)
   {
       printf("Secilen Salon :%s\n",Blue.SalonIsmi);
       printf("Secilen Matina :%d\n",Blue.matina);
       printf("Secilen Film :%s\n",Blue.filmler);
       printf("Filme alinan bilet sayisi :%d\n",sayac);
       printf("Koltuk No:%d\n",*(Blue.koltuk+1));
       fprintf(fp2,"%s %s    %s %d    %s %s    %s %d    %s %d    \n","Salon Adi:",Blue.SalonIsmi,"Matina No:",Blue.matina,"Secilen Film:",Blue.filmler,"Alinan Bilet Sayisi:",sayac,"Koltuk No:",*(Blue.koltuk+1));
   }
   fclose(fp2);
}
