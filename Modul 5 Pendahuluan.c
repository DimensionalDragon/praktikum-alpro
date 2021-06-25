#include<stdio.h>
#include<string.h>

void readFile(char fileName[])
{
    FILE *file = fopen(fileName, "r");
    char read[100] = "";
    while(!feof(file))
    {
        char scanned;
        fscanf(file, "%c", &scanned);
        strncat(read, &scanned, 1);
    }
    fclose(file);
    printf("Data terbaca:\n%s\n", read);
}

void writeFile(char fileName[], char *input)
{
    FILE *file = fopen(fileName, "w");
    fprintf(file, "%s", input);
    fclose(file);
}

void appendFile(char fileNameA[], char fileNameB[])
{
    FILE *fileA = fopen(fileNameA, "a");
    FILE *fileB = fopen(fileNameB, "r");
    rewind(fileB);
    while(!feof(fileB))
    {
        char scanned;
        fscanf(fileB, "%c", &scanned);
        fprintf(fileA, "%c", scanned);
    }
    fclose(fileA);
    fclose(fileB);
}

int main()
{
    writeFile("Test.txt", "Hello, World");
    appendFile("Test.txt", "Test2.txt");
    readFile("Test.txt");
    return 0;
}