#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

static int i=0;
struct web
{
char name[30],pass[30];
}w[99];
int n;
char nama[50],asal,alamat,jenisKelamin;
int id,hp,menu;

void login();
void reg();
void dataDiri();
void menuMotor();
void menuMobil();
void motorHonda();
void motorYamaha();
void motorKawasaki();
void motorPrestige();

int main()
{
system("cls");
printf("\n\n\n\n\t\t\t  ==============================================");
printf("\n\t\t          |                 WELCOME!                   |");
printf("\n\t\t          ----------------------------------------------");
printf("\n\t\t          |          PRESS ENTER TO PROCEED            |");
printf("\n\t\t          ----------------------------------------------");
printf("\n\t\t                               |");
printf("\n\t\t                               |");
printf("\n\t\t                               |");
printf("\n\t\t                               |");
printf("\n\t\t                               |");
printf("\n\t\t                               v");
printf("\n\t\t      =======================================================");
printf("\n\t\t      |                                                     |");
printf("\n\t\t      |                      ENTER                          |");
printf("\n\t\t      |                                                     |");
printf("\n\t\t      =======================================================");
if(getch()==13)
  system("cls");
XY:
printf("\n\t\t          ==================================  ==================================");
printf("\n\t\t          | 1.|  LOGIN                     |  | 2.|  SIGN UP                   |");
printf("\n\t\t          ==================================  ==================================");
printf("\n\t\t                          |                                     |");
printf("\n\t\t                          |           ENTER YOUR CHOICE         |");
printf("\n\t\t                          |_______________|     |_______________|");
printf("\n\t\t                                             ");
scanf("%d",&n);
system("cls");
switch(n)
  {
    case 1:
        login();
        break;
    case 2:
        reg();
        break;
    default: printf("\n\n\t\t\t\tNO MATCH FOUND");
        printf("\n\n\t\t\tPress Enter to re-Enter the choice");
        if(getch()==13)
        system("cls");
        goto XY;
  }
  return 0;
}
void login()
{
      FILE *fp;
      char c,name[30],pass[30]; int z=0;
      int checku,checkp;
      fp=fopen("Web_reg.txt","rb");
      printf("\n\n\t\t\t\t      LOG IN");
      printf("\n\t\t\t\t------------------------");
      for(i=0;i<1000;i++)
      {
        printf("\n\n\t\t\t\t  ENTER USERNAME: ");
        scanf("%s",name);
        printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
        while((c=getch())!=13)
        {
          pass[z++]=c;
          printf("%c",'*');
        }
        pass[z]='\0';
      while(!feof(fp))
        {
        fread(&w[i],sizeof(w[i]),1,fp);
          checku=strcmp(name,w[i].name);
          checkp=strcmp(pass,w[i].pass);
          if(checku==0&&checkp==0)
          {
            system("cls");
            printf("\n\n\n\t\t\t~~~YOU HAVE LOGGED IN SUCCESSFULLY!~~~");
            printf("\n\n\n\t\t\t                WELCOME!");
            dataDiri();
           break;
          }
        else if(checku==0&&checkp!=0)
          {
            printf("\n\n\n\t\t\tWRONG PASSWORD!! Not %s??",name);
            printf("\n\n\t\t\t\t  (Press 'Y' to re-login)");
            if(getch()=='y'||getch()=='Y')
              login();
          }
        else if(checku!=0)
          {
            printf("\n\n\n\t\t\tYou are not a Registered User\n \t\t\tPress enter to register yourself");
            if(getch()==13)
            system("cls");
            reg();
          }
        }
        break;
      }
      getch();
    }
  void reg()
  {
    FILE *fp;
    char c,checker[30]; int z=0;
    fp=fopen("Web_reg.txt","ab+");
    printf("\n\n\t\t\t\t    REGISTER");
    printf("\n\t\t\t\t----------------------");
    for(i=0;i<100;i++)
    {
      printf("\n\n\t\t\t\t  ENTER USERNAME: ");
      scanf("%s",checker);
        while(!feof(fp))
        {
          fread(&w[i],sizeof(w[i]),1,fp);
          if(strcmp(checker,w[i].name)==0)
            {
            printf("\n\n\t\t\tUSERNAME ALREDY EXISTS");
            system("cls");
            reg();
            }
          else
          {
            strcpy(w[i].name,checker);
            break;
          }
        }
      printf("\n\n\t\t\t\t  DESIRED PASSWORD: ");
      while((c=getch())!=13)
        {
          w[i].pass[z++]=c;
          printf("%c",'*');
        }
      fwrite(&w[i],sizeof(w[i]),1,fp);
      fclose(fp);
      printf("\n\n\tPress enter if you agree with Username and Password");
      if((c=getch())==13)
        {
        system("cls");
        printf("\n\n\t\tYou are successfully registered");
        printf("\n\n\t\tTry login your account??\n\n\t\t  ");
        printf("> PRESS 1 FOR YES\n\n\t\t  > PRESS 2 FOR NO\n\n\t\t\t\t");
        scanf("%d",&n);
        switch(n)
          {
              case 1: system("cls");
                    login();
                    break;
              case 2: system("cls");
                    printf("\n\n\n\t\t\t\t\tTHANK YOU FOR REGISTERING");
                    break;
          }
        }
        break;
      }
    getch();
  }
void dataDiri()
{
    datadiri:

        printf("\n===============================\n");
        printf("    Masukkan Data Diri Anda    \n");
        printf("===============================\n");
        printf("Nama            : ");
        scanf("%s", &nama);
        printf("Asal            : ");
        scanf("%s", &asal);
        printf("Alamat          : ");
        scanf("%s", &alamat);
        printf("Jenis Kelamin   : ");
        scanf("%s", &jenisKelamin);
        printf("KTP/Passport    : ");
        scanf("%d", &id);
        printf("No. HP          : ");
        scanf("%d", &hp);

    pilihan:

        printf("Menu            :\n");
        printf("===============================\n");
        printf("  01. Motor\n");
        printf("  02. Mobil\n");
        printf("===============================\n");
        printf("Pilih Menu      : ");
        scanf("%d", &menu);
        printf("===============================\n");
        system("cls");
        switch(menu)
        {
        case 1:
            menuMotor();
            break;
        case 2:
            menuMobil();
            break;
        default:
            printf("Menu yang Anda Input Salah\n");
            printf("Masukkan Menu Kembali\n");
            goto pilihan;
        }

}

void menuMotor()
{
    menumotor:

        printf("===============================\n");
        printf("        DAFTAR MERK MOTOR      \n");
        printf("===============================\n");
        printf("1. Honda");
        printf("2. Yamaha");
        printf("3. Kawasaki");
        printf("4. Prestige");
        printf("===============================\n");
        printf("Pilih Menu : ");
        scanf("%d", &menu);
        printf("===============================\n");
        system("cls");
        switch(menu)
        {
        case 1:
            motorHonda();
            break;
        case 2:
            motorYamaha();
            break;
        case 3:
            motorKawasaki();
            break;
        case 4:
            motorPrestige();
            break;
        }
}

void motorHonda()
{
    motorhonda:

        printf("=============================================\n");
        printf("              DAFTAR MOTOR HONDA             \n");
        printf("=============================================\n");
        printf("|-------------------------------------------|\n");
        printf("|Nama Motor : Honda Scoopy                  |\n");
        printf("|-------------------------------------------|\n");
        printf("|Tahun                  : 2017              |\n");
        printf("|Warna                  : Hitam             |\n");
        printf("|Odometer               : 3098 KM           |\n");
        printf("|Tgl Service Terakhir   : 12/2/2020         |\n");
        printf("|Kelayakan              : 95%               |\n");
        printf("|Harga Sewa             : Rp.40.000/day     |\n");
        printf("|-------------------------------------------|\n");

}

void motorYamaha()
{
    motoryamaha:

        printf("=============================================\n");
        printf("            DAFTAR MOTOR YAMAHA              \n");
        printf("=============================================\n");
        printf("|-------------------------------------------|\n");
        printf("|Nama Motor :                               |\n");
        printf("|-------------------------------------------|\n");
        printf("|Tahun                  :                   |\n");
        printf("|Warna                  :                   |\n");
        printf("|Odometer               :                   |\n");
        printf("|Tgl Service Terakhir   :                   |\n");
        printf("|Kelayakan              :                   |\n");
        printf("|Harga Sewa             :                   |\n");
        printf("|-------------------------------------------|\n");

}

void motorKawasaki()
{
    motorkawasaki:

        printf("=============================================\n");
        printf("            DAFTAR MOTOR KAWASAKI            \n");
        printf("=============================================\n");
        printf("|-------------------------------------------|\n");
        printf("|Nama Motor :                               |\n");
        printf("|-------------------------------------------|\n");
        printf("|Tahun                  :                   |\n");
        printf("|Warna                  :                   |\n");
        printf("|Odometer               :                   |\n");
        printf("|Tgl Service Terakhir   :                   |\n");
        printf("|Kelayakan              :                   |\n");
        printf("|Harga Sewa             :                   |\n");
        printf("|-------------------------------------------|\n");
}

void motorPrestige()
{
    motorPrestige:

        printf("=============================================\n");
        printf("            DAFTAR MOTOR PRESTIGE            \n");
        printf("=============================================\n");
        printf("|-------------------------------------------|\n");
        printf("|Nama Motor :                               |\n");
        printf("|-------------------------------------------|\n");
        printf("|Tahun                  :                   |\n");
        printf("|Warna                  :                   |\n");
        printf("|Odometer               :                   |\n");
        printf("|Tgl Service Terakhir   :                   |\n");
        printf("|Kelayakan              :                   |\n");
        printf("|Harga Sewa             :                   |\n");
        printf("|-------------------------------------------|\n");
}
void menuMobil()
{
    menumobil:

        printf("===============================\n");
        printf("         DAFTAR MOBIL          \n");
        printf("===============================\n");
}
