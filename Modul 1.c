#include<stdio.h>
#include<string.h>
#include<time.h>

int main()
{
    time_t current;
    time(&current);
    ctime(&current);
    struct tm *currentTime = localtime(&current);

    char bulan[12][20] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni",
                          "Juli", "Agustus", "September", "Oktober", "November", "Desember"};
    char nama[100], nim[20], kelas[5], alamat[100], nomor_hp[20], bulan_lahir[20];
    int umur, tanggal_lahir, tahun_lahir, nomor_bulan_lahir, usia_hari, hari_sekarang;

    printf("Nama: ");
    fgets(nama, 100, stdin);
    printf("NIM: ");
    fgets(nim, 20, stdin);
    printf("Kelas: ");
    fgets(kelas, 5, stdin);
    printf("Alamat: ");
    fgets(alamat, 100, stdin);
    printf("Nomor HP: ");
    fgets(nomor_hp, 20, stdin);
    ulang:
    printf("Tanggal Lahir: ");
    scanf("%d %s %d", &tanggal_lahir, &bulan_lahir, &tahun_lahir);

    for(int i = 0; i < 12; i++)
    {
        if(!strcmp(bulan_lahir, bulan[i]))
        {
            nomor_bulan_lahir = i + 1;
            break;
        }
    }
    if(nomor_bulan_lahir == -1)
    {
        printf("[ERROR] Input Bulan Invalid\n");
        goto ulang;
    }
    hari_sekarang = currentTime->tm_mday + 30 * (currentTime->tm_mon + 1) + 365 * (currentTime->tm_year + 1900);
    usia_hari = tanggal_lahir + 30 * nomor_bulan_lahir + 365 * tahun_lahir;
    umur = (hari_sekarang - usia_hari) / 365;

    printf("\n==================Terima Kasih Sudah Mendaftar==================\n");
    printf("Nama: %s", nama);
    printf("NIM: %s", nim);
    printf("Kelas: %s", kelas);
    printf("Alamat: %s", alamat);
    printf("Nomor HP: %s", nomor_hp);
    printf("Tanggal Lahir: %d %s %d\n", tanggal_lahir, bulan_lahir, tahun_lahir);
    printf("Umur: %d tahun\n", umur);
    return 0;
}
