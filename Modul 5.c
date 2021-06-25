#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct data
{
    char nim[15];
    char nama[100];
    char kelas;
} Mahasiswa;

bool checkFile(char fileName[])
{
    FILE *file = fopen(fileName, "r");
    if(file == NULL)
    {
        fclose(file);
        return false;
    }
    else
    {
        fclose(file);
        return true;
    }
}

void createFile(char fileName[])
{
    FILE *file;
    char pilihan;
    if(!checkFile(fileName))
    {
        file = fopen(fileName, "w");
        fclose(file);
    }
}

void addData(char fileName[], Mahasiswa mahasiswa)
{
    FILE *file;
    if(checkFile(fileName))
    {
        file = fopen(fileName, "a");
        fprintf(file, "NIM: %s\nNama: %s\nKelas: %c\n\n", mahasiswa.nim, mahasiswa.nama, mahasiswa.kelas);
        fclose(file);
        printf("\nData mahasiswa berhasil ditambahkan!\n");
    }
    else
    {
        printf("\nFile tidak ditemukan!\n");
    }
}

void readData(char fileName[], char nim[])
{
    FILE *file = fopen(fileName, "r");
    Mahasiswa baca;
    if(checkFile(fileName))
    {
        while(!feof(file))
        {
            fscanf(file, "NIM: %s\nNama: %[^\n]\nKelas: %c\n\n", &baca.nim, &baca.nama, &baca.kelas);
            if(strcmp(baca.nim, nim) == 0)
            {
                printf("\nData mahasiswa ditemukan!\n");
                printf("NIM: %s\nNama: %s\nKelas: %c\n\n", baca.nim, baca.nama, baca.kelas);
                fclose(file);
                return;
            }
        }
        printf("\nData mahasiswa tidak ditemukan!\n");
        fclose(file);
    }
    else
    {
        printf("\nFile tidak ditemukan!\n");
    }
}

void ubah(Mahasiswa *data)
{
    int pilihan;
    printf("\nPilihan data:\n");
    printf("1. NIM\n");
    printf("2. Nama\n");
    printf("3. Kelas\n");
    ulang:
    printf("Pilih data yang ingin diubah: ");
    scanf("%d", &pilihan); fflush(stdin);
    switch (pilihan)
    {
    case 1:
        printf("Masukkan NIM baru: ");
        scanf("%s", &data->nim);
        break;
    case 2:
        printf("Masukkan Nama baru: ");
        scanf("%[^\n]", &data->nama); fflush(stdin);
        break;
    case 3:
        printf("Masukkan Kelas baru: ");
        scanf("%c", &data->kelas);
        break;
    default:
        printf("Pilihan invalid!\n");
        goto ulang;
    }
}

void updateData(char fileName[], char nim[])
{
    FILE *fileInput;
    FILE *fileTemp;
    Mahasiswa baca;
    bool update = false;
    if(checkFile(fileName))
    {
        fileInput = fopen(fileName, "r");
        fileTemp = fopen("temp_file.txt", "w");
        while(!feof(fileInput))
        {
            fscanf(fileInput, "NIM: %s\nNama: %[^\n]\nKelas: %c\n\n", &baca.nim, &baca.nama, &baca.kelas);
            if(strcmp(baca.nim, nim) == 0)
            {
                ubah(&baca);
                update = true;
            }
            fprintf(fileTemp, "NIM: %s\nNama: %s\nKelas: %c\n\n", baca.nim, baca.nama, baca.kelas);
        }
        fclose(fileInput);
        fclose(fileTemp);
        remove(fileName);
        rename("temp_file.txt", fileName);
        if(update)
        {
            printf("\nData mahasiswa berhasil diupdate!\n");
        }
        else
        {
            printf("\nData mahasiswa tidak ditemukan!\n");
        }
    }
    else
    {
        printf("\nFile tidak ditemukan!\n");
    }
}

void deleteData(char fileName[], char nim[])
{
    FILE *fileInput;
    FILE *fileTemp;
    Mahasiswa baca;
    bool terhapus = false;
    if(checkFile(fileName) == true)
    {
        fileInput = fopen(fileName, "r");
        fileTemp = fopen("temp_file.txt", "w");
        while(!feof(fileInput))
        {
            fscanf(fileInput, "NIM: %s\nNama: %[^\n]\nKelas: %c\n\n", &baca.nim, &baca.nama, &baca.kelas);
            if(strcmp(baca.nim, nim) != 0)
            {
                fprintf(fileTemp, "NIM: %s\nNama: %s\nKelas: %c\n\n", baca.nim, baca.nama, baca.kelas);
                printf("NIM: %s\nNama: %s\nKelas: %c\n\n", baca.nim, baca.nama, baca.kelas);
            }
            else
            {
                terhapus = true;
            }
        }
        fclose(fileInput);
        fclose(fileTemp);
        remove(fileName);
        rename("temp_file.txt", fileName);
        if(terhapus)
        {
            printf("\nData mahasiswa berhasil dihapus!\n");
        }
        else
        {
            printf("\nData mahasiswa tidak ditemukan!\n");
        }
        
    }
    else
    {
        printf("\nFile tidak ditemukan!\n");
    }
}

void showMenu()
{
	printf("============================== DATABASE MAHASISWA =============================\n\n");
	printf("Menu:\n");
	printf("1. Masukkan data mahasiswa\n");
	printf("2. Tampilkan data mahasiswa\n");
	printf("3. Update data mahasiswa\n");
    printf("4. Hapus data mahasiswa\n");
	printf("5. Hapus file dan semua data mahasiswa\n");
    printf("6. Exit\n\n");
}

int main()
{
    Mahasiswa mahasiswa;
    FILE *file;
    int pilihan;
    char inputNIM[15];
    char yes_no_input;
    while(pilihan != 6)
    {
        showMenu();
        ulang:
        printf("Masukkan pilihan [1 - 6]: ");
        scanf("%d", &pilihan); fflush(stdin);
        switch (pilihan)
        {
        case 1:
            printf("Masukkan NIM: ");
            scanf("%s", &mahasiswa.nim); fflush(stdin);
            printf("Masukkan nama mahasiswa: ");
            scanf("%[^\n]", &mahasiswa.nama); fflush(stdin);
            printf("Masukkan kelas mahasiswa: ");
            scanf("%c", &mahasiswa.kelas); fflush(stdin);
            createFile("Database.txt");
            addData("Database.txt", mahasiswa);
            printf("Tekan enter untuk melanjutkan");
            getch();
            break;
        case 2:
            printf("Masukkan NIM: ");
            scanf("%s", &inputNIM); fflush(stdin);
            readData("Database.txt", inputNIM);
            printf("Tekan enter untuk melanjutkan");
            getch();
            break;
        case 3:
            printf("Masukkan NIM: ");
            scanf("%s", &inputNIM); fflush(stdin);
            updateData("Database.txt", inputNIM);
            printf("Tekan enter untuk melanjutkan");
            getch();
            break;
        case 4:
            printf("Masukkan NIM: ");
            scanf("%s", &inputNIM); fflush(stdin);
            deleteData("Database.txt", inputNIM);
            printf("Tekan enter untuk melanjutkan");
            getch();
            break;
        case 5:
            konfirmasi:
            printf("Apakah anda yakin ingin menghapus semua data? [y/n] ");
            scanf("%c", &yes_no_input); fflush(stdin);
            if(yes_no_input == 'y')
            {
                remove("Database.txt");
                printf("\nFile berhasil dihapus!\n");
                printf("Tekan enter untuk melanjutkan");
                getch();
            }
            else if(yes_no_input == 'n')
            {
                break;
            }
            else
            {
                printf("Pilihan Invalid!\n");
                goto konfirmasi;
            }
            break;
        case 6:
            break; 
        default:
            printf("Pilihan Invalid!\n");
            goto ulang;
        }
        system("cls");
    }
    printf("Berhasil keluar dari program!\n");
    return 0;
}