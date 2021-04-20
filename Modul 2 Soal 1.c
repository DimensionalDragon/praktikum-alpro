#include<stdio.h>

int main()
{
    int tinggi;
    printf("----------------Program Bintang----------------\n");
    printf("===============================================\n");
    printf("Masukkan tinggi bintang: ");
    scanf("%d", &tinggi);
    for(int i = 1; i <= tinggi; i++)
    {
        for(int j = 1; j <= tinggi - i; j++)
        {
            printf(" ");
        }
        for(int k = 1; k <= 2*i - 1; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}