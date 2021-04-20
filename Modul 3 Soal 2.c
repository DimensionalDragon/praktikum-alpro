#include<stdio.h>
#define MAX 100

void urut(int array[MAX], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int hapus(int array[MAX], int size)
{
    int newSize = size;
    for(int i = 1; i <= size; i++)
    {
        for(int j = 0; j < size - 1; j++)
        {
            if(array[j] == array[j+1] && j < newSize - 1)
            {
                for(int k = j + 1; k < size - 1; k++)
                {
                    array[k] = array[k + 1];
                }
                newSize--;
            }
        }
    }
    return newSize;
}

void printArray(int array[MAX], int size)
{
    printf("{");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("%d}\n", array[size - 1]);
}

int main()
{
    int data[MAX];
    int jumlahData;
    printf("Masukkan jumlah data: ");
    scanf("%d", &jumlahData);
    printf("Masukkan data-data array:\n");
    for(int i = 0; i < jumlahData; i++)
    {
        scanf("%d", &data[i]);
    }
    urut(data, jumlahData);
    jumlahData = hapus(data, jumlahData);
    printf("Array setelah diurutkan dan data yang sama dihapus:\n");
    printArray(data, jumlahData);
    return 0;
}

