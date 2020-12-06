#include <stdio.h>
#include <stdlib.h>

//Program Rental Kendaraan Bermotor
//Variabel
char nama[50];
char asal;
char alamatSekarang;
char jenisKelamin;
int ktpPass;
int hp;

int main ()
{
    printf("\t\t\t=====================================\n");
    printf("\t\t\t-------------------------------------\n");
    printf("\t\t\t\tCV. WISMA KARYA MOTOR\n");
    printf("\t\t\t\t   SELAMAT DATANG\n");
    printf("\t\t\t-------------------------------------\n");
    printf("\t\t\t=====================================\n");
    printf("\nMasukkan Data Diri Anda\n");
    printf("-------------------------\n");
    printf("Nama\t\t: ");
    scanf("%s", &nama);
    printf("Asal\t\t: ");
    scanf("%s", &asal);
    printf("Alamat\t\t: ");
    scanf("%s", &alamatSekarang);
    printf("Jenis Kelamin\t: ");
    scanf("%s", &jenisKelamin);
    printf("KTP/Passport\t: ");
    scanf("%d", &ktpPass);
    printf("No. HP\t\t: ");
    scanf("%d", &hp);


    return(0);
}
