#include<stdio.h>

float luasSegitiga(float* alas, float* tinggi)
{
    return (*alas) * (*tinggi) / 2;
}

int luasSegiempat(int* panjang, int* lebar)
{
    return (*panjang) * (*lebar);
}

int main()
{
    int pilihan;
    printf("Menu:\n");
    printf("1. Luas Segitiga\n");
    printf("2. Luas Segiempat\n");
    ulang:
    printf("Masukkan pilihan anda: ");
    scanf("%d", &pilihan);
    printf("\n");
    switch(pilihan)
    {
        case 1:
        {
            float alas, tinggi;
            float* ptrAlas = &alas;
            float* ptrTinggi = &tinggi;
            printf("Masukkan alas segitiga: ");
            scanf("%f", &alas);
            printf("Masukkan tinggi segitiga: ");
            scanf("%f", &tinggi);
            printf("\nLuas segitiga dengan alas %.0f dan tinggi %.0f = %.1f", alas, tinggi, luasSegitiga(ptrAlas, ptrTinggi));
            break;
        }
        case 2:
        {
            int panjang, lebar;
            int* ptrPanjang = &panjang;
            int* ptrLebar = &lebar;
            printf("Masukkan panjang segiempat: ");
            scanf("%d", &panjang);
            printf("Masukkan lebar segiempat: ");
            scanf("%d", &lebar);
            printf("\nLuas segiempat dengan panjang %d dan lebar %d = %d", panjang, lebar, luasSegiempat(ptrPanjang, ptrLebar));
            break;
        }
        default:
        {
            printf("Pilihan Invalid!\n");
            goto ulang;
        }

    }
    return 0;
}