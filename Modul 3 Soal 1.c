#include<stdio.h>
#define MAX 100

void jumlahMatrix(int matrix_A[MAX][MAX], int matrix_B[MAX][MAX], int matrix_hasil[MAX][MAX], int size)
{
    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrix_hasil[i][j] = matrix_A[i][j] + matrix_B[i][j];
        }
    }
}

void kaliMatrix(int matrix_A[MAX][MAX], int matrix_B[MAX][MAX], int matrix_hasil[MAX][MAX], int size)
{
    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrix_hasil[i][j] = 0;
            for(int k = 0; k < size; k++)
            {
                matrix_hasil[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int size)
{
    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int matrix_A[MAX][MAX];
    int matrix_B[MAX][MAX];
    int hasil[MAX][MAX];
    int ukuran, pilihan;
    printf("Masukkan ukuran matriks (n x n): ");
    scanf("%d", &ukuran);

    printf("Masukkan elemen-elemen matriks A:\n");
    for (int i = 0; i < ukuran; i++)
    {
        for(int j = 0; j < ukuran; j++)
        {
            scanf("%d", &matrix_A[i][j]);
        }
    }
    
    printf("Masukkan elemen-elemen matriks B:\n");
    for (int i = 0; i < ukuran; i++)
    {
        for(int j = 0; j < ukuran; j++)
        {
            scanf("%d", &matrix_B[i][j]);
        }
    }

    printf("\nMenu operasi matriks:\n");
    printf("1. Penjumlahan\n");
    printf("2. Perkalian\n");
    ulang:
    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan);
    switch(pilihan)
    {
        case 1:
            jumlahMatrix(matrix_A, matrix_B, hasil, ukuran);
            printf("\nMatriks hasil penjumlahan:\n");
            printMatrix(hasil, ukuran);
            break;
        case 2:
            kaliMatrix(matrix_A, matrix_B, hasil, ukuran);
            printf("\nMatriks hasil perkalian:\n");
            printMatrix(hasil, ukuran);
            break;
        default:
            printf("Pilihan invalid!\n");
            goto ulang;
    }
    return 0;
}

