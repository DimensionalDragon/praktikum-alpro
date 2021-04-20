#include<stdio.h>

void cetakGanjil(int awal, int akhir)
{
    for(int i = awal; i <= akhir; i++)
    {
        if(i % 2 == 1)
        {
            if(i == akhir || i == akhir - 1)
            {
                printf("%d\n", i);
            }
            else
            {
                printf("%d, ", i);
            }
        }
    }
}

void cetakGenap(int awal, int akhir)
{
    for(int i = awal; i <= akhir; i++)
    {
        if(i % 2 == 0)
        {
            if(i == akhir || i == akhir - 1)
            {
                printf("%d\n", i);
            }
            else
            {
                printf("%d, ", i);
            }
        }
    }
}

int main()
{
    int awal, akhir, input;
    printf("Program Deret Bilangan\n");
    printf("======================\n");
    printf("Ketik bilangan awal : ");
    scanf("%d", &awal);
    printf("Ketik bilangan akhir : ");
    scanf("%d", &akhir);
    printf("Ketik jenis bilangan :\n");
    printf("1. Ganjil\n");
    printf("2. Genap\n");
    ulangi:
    printf("Ketik pilihan : ");
    scanf("%d", &input);
    switch (input)
    {
    case 1:
        cetakGanjil(awal, akhir);
        break;
    case 2:
        cetakGenap(awal, akhir);
        break;
    default:
        printf("[ERROR] Pilihan Invalid\n");
        goto ulangi;
        break;
    }
    return 0;
}

