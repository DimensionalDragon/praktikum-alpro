#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char Nama[50], Alamat[50], Cat[50];
	int Tahun, Umur, ID;
	float Berat,Tinggi,IMT;
} Biodata;

FILE* PASIEN;
char txt[15]="DataIMT.txt";

//Function Clear Screen Cross-Platform.
void clear(){
    #ifdef _WIN32
        //Windows
        system("cls");
    #else
        //POSIX (Unix), etc
        system("clear");
    #endif
}

//Function Header Program (CLI)
void header(){
    clear();
    printf("-----------------------------------------\n");
    printf("|       Program Indeks Massa Tubuh      |\n");
    printf("|         Tinggi Potensi Genetik        |\n");
    printf("|         Tim 3 Praktikum Alpro         |\n");
    printf("-----------------------------------------\n");
}

void Create(){
	Biodata Pasien;
	PASIEN=fopen(txt, "a");
	header();
	printf("\nMasukkan Data dengan Benar\n\n");
	printf("ID Pasien\t: "); scanf("%d",&Pasien.ID);
	fflush(stdin);
	printf("Nama Pasien\t: "); scanf("%[^\n]",&Pasien.Nama);
	fflush(stdin);
	printf("Alamat Pasien\t: "); scanf("%[^\n]",&Pasien.Alamat);
	fflush(stdin);
	printf("Tahun Lahir\t: "); scanf("%i",&Pasien.Tahun);
	fflush(stdin);
	printf("Berat Badan\t: "); scanf("%f",&Pasien.Berat);
	fflush(stdin);
	printf("Tinggi Badan\t: "); scanf("%f",&Pasien.Tinggi);
	fflush(stdin);
	Pasien.Umur=2021-Pasien.Tahun;
	Pasien.Tinggi=Pasien.Tinggi/100;
	Pasien.IMT=Pasien.Berat/(Pasien.Tinggi*Pasien.Tinggi);

	if (Pasien.IMT <= 17.00){
		strcpy(Pasien.Cat, "Kekurangan Berat Badan Tingkat Tinggi");
	}
	else if (Pasien.IMT > 17.00 && Pasien.IMT <= 18.50){
		strcpy(Pasien.Cat, "Kekurangan Berat Badan Ringan");
	}
	else if (Pasien.IMT > 18.50 && Pasien.IMT <= 25.00){
		strcpy(Pasien.Cat, "Berat Badan Ideal");
	}
	else if (Pasien.IMT > 25.00 && Pasien.IMT <= 27.00){
		strcpy(Pasien.Cat, "Kelebihan Berat Badan Ringan");
	}
	else if (Pasien.IMT > 27.00){
		strcpy(Pasien.Cat, "Kelebihan Berat Badan Tingkat Tinggi");
	}

	fprintf(PASIEN,"%d_%s_%i_%i_%.2f_%s_%s\n",Pasien.ID ,Pasien.Nama,Pasien.Tahun,Pasien.Umur,Pasien.IMT,Pasien.Alamat, Pasien.Cat);
	fclose(PASIEN);
}

void Read(){
	Biodata Pasien;
	int id;
	header();
	printf("\nMasukan ID Pasien\t: ");scanf("%i",&id);fflush(stdin);
	PASIEN=fopen("DataIMT.txt","r");
	while (!feof(PASIEN)){
		fscanf(PASIEN,"%d_%[^_]_%i_%i_%f_%[^_]_%[^\n]\n",&Pasien.ID,&Pasien.Nama,&Pasien.Tahun,&Pasien.Umur,&Pasien.IMT,&Pasien.Alamat,&Pasien.Cat);
		fflush(stdin);
		if(id==Pasien.ID){
			header();
			printf("\nData Pasien\n\n");
			printf("ID Pasien\t : %d\n",Pasien.ID);
			printf("Nama Pasien\t : %s\n",Pasien.Nama);
			printf("Alamat Pasien\t : %s\n",Pasien.Alamat);
			printf("Tahun Lahir\t : %i\n",Pasien.Tahun);
			printf("Umur Pasien\t : %i\n",Pasien.Umur);
			printf("IMT Pasien\t : %.2f\n",Pasien.IMT);
			printf("Kategori\t : %s\n\n",Pasien.Cat);
            return;
		}
	}
}

void Update(){
	FILE *temp;
	Biodata Pasien;
	int id;
	header();
	printf("\nMasukkan ID Pasien\t: "); scanf("%i",&id);
	fflush(stdin);
	temp = fopen("tempFile.txt", "w");
	PASIEN=fopen("DataIMT.txt","r");
	while(!feof(PASIEN)){
		fscanf(PASIEN,"%d_%[^_]_%i_%i_%f_%[^_]_%[^\n]\n",&Pasien.ID,&Pasien.Nama,&Pasien.Tahun,&Pasien.Umur,&Pasien.IMT,&Pasien.Alamat,&Pasien.Cat);
		if(id == Pasien.ID){
			header();
			printf("\nPerubahan Data Pasien\n\n");
			printf("Masukan Berat Badan Pasien \t: ");scanf("%f",&Pasien.Berat);fflush(stdin);
			printf("Masukan Tinggi Badan Pasien \t: ");scanf("%f",&Pasien.Tinggi);fflush(stdin);
			Pasien.Tinggi=Pasien.Tinggi/100;
			Pasien.IMT=Pasien.Berat/(Pasien.Tinggi*Pasien.Tinggi);
			if (Pasien.IMT <= 17.00){
				strcpy(Pasien.Cat, "Kekurangan Berat Badan Tingkat Tinggi");
			}
			else if (Pasien.IMT > 17.00 && Pasien.IMT <= 18.50){
				strcpy(Pasien.Cat, "Kekurangan Berat Badan Ringan");
			}
			else if (Pasien.IMT > 18.50 && Pasien.IMT <= 25.00){
				strcpy(Pasien.Cat, "Berat Badan Ideal");
			}
			else if (Pasien.IMT > 25.00 && Pasien.IMT <= 27.00){
				strcpy(Pasien.Cat, "Kelebihan Berat Badan Ringan");
			}
			else if (Pasien.IMT > 27.00){
				strcpy(Pasien.Cat, "Kelebihan Berat Badan Tingkat Tinggi");
			}
		}
		fprintf(temp,"%d_%s_%i_%i_%.2f_%s_%s\n",Pasien.ID ,Pasien.Nama,Pasien.Tahun,Pasien.Umur,Pasien.IMT,Pasien.Alamat, Pasien.Cat);
	}
	fclose(PASIEN);
    fclose(temp);
    remove("DataIMT.txt");
    rename("tempFile.txt", "DataIMT.txt");
}

void Delete(){
	FILE *temp;
	Biodata Pasien;
	int id;
	header();
	printf("\nMasukan ID Pasien Yang Akan Dihapus\t: "); scanf("%i",&id); fflush(stdin);
	fflush(stdin);
	temp = fopen("tempFile.txt", "w");
	PASIEN=fopen("DataIMT.txt","r");
	while(!feof(PASIEN)){
		fscanf(PASIEN,"%d_%[^_]_%i_%i_%f_%[^_]_%[^\n]\n",&Pasien.ID,&Pasien.Nama,&Pasien.Tahun,&Pasien.Umur,&Pasien.IMT,&Pasien.Alamat,&Pasien.Cat);
		if(id != Pasien.ID){
			fprintf(temp,"%d_%s_%i_%i_%.2f_%s_%s\n",Pasien.ID ,Pasien.Nama,Pasien.Tahun,Pasien.Umur,Pasien.IMT,Pasien.Alamat, Pasien.Cat);
		}
	}
	fclose(PASIEN);
    fclose(temp);
    remove("DataIMT.txt");
    rename("tempFile.txt", "DataIMT.txt");
	printf("\nID %d Berhasil Dihapus", id);	
}

int main(){
	char Lanjut[2];
	int menu;
	do{
		header();
		printf("\nMenu\n");
		printf("1. Buat Data\n2. Tampilkan Data\n3. Ubah Data\n4. Hapus Data\n5. Keluar\n\nMasukkan Pilihan: ");
		scanf("%i",&menu);
		fflush(stdin);
		switch(menu){
			case 1:
				Create();
			break;
			case 2:
				Read();
			break;
			case 3:
				Update();
			break;
			case 4:
				Delete();
			break;
			case 5:
				header();
				printf("\nTerima Kasih!\n\n");
				return 0;
			break;
			default:
				printf("Menu yang anda pilih tidak tersedia.\n");
		}
		printf("\nKembali Ke Menu Utama? (y/n) > "); scanf("%s",&Lanjut);
		fflush(stdin);
		clear();
	} while(strcmp(Lanjut,"y")==0);
}

/*
Input Data
id
nama
alamat
tahun lahir
berat badan
tinggi badan

Update Data
berat badan
tinggi badan
tanggal bulan tahun	*/