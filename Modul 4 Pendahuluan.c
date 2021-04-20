#include<stdio.h>

int faktorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return (n * faktorial(n - 1));
    }
}

void tukar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int pangkat(int a, int b)
{
    int hasil = 1;
    for(int i = 1; i <= b; i++)
    {
        hasil *= a;
    }
    return hasil;
}

int main()
{
    int array[] = {1, 2, 3};
    printf("%d\n", faktorial(1));
    printf("%d\n", pangkat(0, 0));
    printf("%d, %d, %d\n", array[0], array[1], array[2]);
    tukar(&array[0], &array[1]);
    printf("%d, %d, %d\n", array[0], array[1], array[2]);
    return 0;
}