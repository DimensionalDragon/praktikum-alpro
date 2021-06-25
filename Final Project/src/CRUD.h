#include<stdio.h>
#define MAX 100
#define UNDEFINED -100000000

void initArray(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
    for(int j = size; j < MAX; j++)
    {
        array[j] = UNDEFINED;
    }
}

int sizeOfArray(int array[])
{
    int index = MAX;
    for(int i = 0; i < MAX; i++)
    {
        if(array[i] == UNDEFINED)
        {
            index = i;
            break;
        }
    }
    return index;
}

void printArray(int array[])
{
    int size = sizeOfArray(array);
    printf("{");
    if(size > 0)
    {
        for(int i = 0; i < size - 1; i++)
        {
            printf("%d, ", array[i]);
        }
        printf("%d}\n", array[size - 1]);
    }
    else
    {
        printf("}\n");
    }
}

void swapInt(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int arraySearch(int x)
{
    return 0;
}

void sortArray(int array[])
{
    int size = sizeOfArray(array);
    if(size != 0)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size - i - 1; j++)
            {
                if(array[j] > array[j+1])
                {
                    swapInt(&array[j], &array[j+1]);
                }
            }
        }
    }
}