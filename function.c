#include "header.h"

struct Buku_Telepon {
	int  nim;
	char nama[50], 
		 no_hp[13];
} bukuTelp;

void back_to_menu() {
	char cek[2];
	
	printf("\nKembali Ke Menu ? (y/n) : ");
	scanf(" %[^\t\n]s", &cek);
	
	if(strcmp(cek, "y") == 0) {
		system("cls");
		main();
	}
}

void tambah_data() {
	FILE *fp;
	char tambah_lagi[2];
	int nim;
		
	
	
	do {
		printf("Inputkan nim      : ");
		scanf("%d", &nim);		
		
		fp = fopen("./data/buku_telepon.txt", "a+");
		while(fread(&bukuTelp, sizeof(bukuTelp), 1, fp)) {
			if(nim == bukuTelp.nim) {
				printf("\nNIM sudah terdaftar !\n\n");
				tambah_data();
			}
		}
		
		bukuTelp.nim = nim;
		
		printf("Inputkan nama     : ");
		scanf(" %[^\t\n]s", &bukuTelp.nama);
		
		printf("Inputkan nomer HP : ");
		scanf(" %[^\t\n]s", &bukuTelp.no_hp);
		
		fwrite(&bukuTelp, sizeof(bukuTelp), 1, fp);
		fclose(fp);
		
		printf("\nTambah Data Lagi ? (y/n) : ");
		scanf(" %[^\t\n]s", &tambah_lagi);
		
	} while (strcmp(tambah_lagi, "y") == 0); 
	
	if(strcmp(tambah_lagi, "n") == 0) {
		back_to_menu();
	}
	
}

void lihat_data() {

	FILE *fr;  		
  	fr = fopen("./data/buku_telepon.txt", "r");
  	int total_kontak = 0;
  	
  	printf("=============================== Data Kontak Mahasiswa ===============================\n\n");
  			
  	printf("-------------------------------------------------------------------------------------\n");
	printf("| %25s | %25s | %25s |\n", "NAMA", "NIM", "NO HP");
	printf("-------------------------------------------------------------------------------------\n");
		
  	while(fread(&bukuTelp, sizeof(bukuTelp), 1, fr))
  	{
  		total_kontak++;
    	printf("| %25s | %25d | %25s |\n", bukuTelp.nama, bukuTelp.nim, bukuTelp.no_hp);
    	printf("-------------------------------------------------------------------------------------\n");
  	}
  	
  	printf("\nTotal Keseluruhan Kontak : %d\n", total_kontak);
  	
	fclose(fr);
  	back_to_menu();
  	
}

void cari_data() {

	FILE *fs;  		
	int pil,
		cari_nim,
		found = 0;
	char cari_nama[50], cari_noHP[15];
	
  	fs = fopen("./data/buku_telepon.txt", "r");
  	
  	printf("=============================== Hasil Pencarian ===============================\n\n");
  	printf("Cari berdasarkan : \n\n");
  	
  	printf("1. Nama\n");
  	printf("2. NIM\n");
  	printf("3. NO HP\n\n");
  	
  	printf("Inputkan Pilihan Anda : ");
  	scanf("%d", &pil);
  	switch(pil) {
  		case 1:
  			printf("\nInputkan Nama yang ingin Anda Cari : ");
  			scanf(" %[^\t\n]s", &cari_nama);
  			break;
  		case 2:
  			printf("\nInputkan NIM yang ingin Anda Cari : ");
  			scanf("%d", &cari_nim);
  			break;	
  		case 3:
  			printf("\nInputkan NO HP yang ingin Anda Cari : ");
  			scanf(" %[^\t\n]s", &cari_noHP);
  			break;	
		default: 	  	
			printf("\nPilihan tidak ditemukan\n");
			back_to_menu(fs);
			return;
	}
  	
  	printf("-------------------------------------------------------------------------------------\n");
	printf("| %25s | %25s | %25s |\n", "NAMA", "NIM", "NO HP");
	printf("-------------------------------------------------------------------------------------\n");
	
  	while(fread(&bukuTelp, sizeof(bukuTelp), 1, fs))
  	{
  		
  		if (cari_nim == ("%d", bukuTelp.nim) || strcmp(cari_nama, (" %[^\t\n]s", bukuTelp.nama)) == 0 || strcmp(cari_noHP, (" %[^\t\n]s", bukuTelp.no_hp)) == 0) {
			printf("| %25s | %25d | %25s |\n", bukuTelp.nama, bukuTelp.nim, bukuTelp.no_hp);
			printf("-------------------------------------------------------------------------------------\n");
			found = 1;
		} 
		
  	}
  	 
	if(found == 0) {
		printf("%60s","Data yang Anda cari tidak ditemukan\n");
		printf("-------------------------------------------------------------------------------------\n");
	}
	
	fclose(fs);
  	back_to_menu();
  	
}

void update_data() {
	FILE *fpo;
	FILE *fpt;
	int nim, not_found = 1;
	char coba_lagi[2];
	
	fpo = fopen("./data/buku_telepon.txt", "r");
	fpt = fopen("./data/buku_teleponTmp.txt", "w");
	
	printf("=============================== Edit Kontak Mahasiswa ===============================\n\n");
	
	printf("Inputkan NIM dari data yang ingin anda ubah : ");
	scanf("%d", &nim);
	
	while(fread(&bukuTelp, sizeof(bukuTelp), 1, fpo)) {
		if(bukuTelp.nim != nim) {
			
			fwrite(&bukuTelp, sizeof(bukuTelp), 1, fpt);
		} else {
			not_found = 0;
			
			printf("\n-------------------------------------------------------------------------------------\n");
			printf("| %25s | %25s | %25s |\n", "NAMA", "NIM", "NO HP");
			printf("-------------------------------------------------------------------------------------\n");
			printf("| %25s | %25d | %25s |\n", bukuTelp.nama, bukuTelp.nim, bukuTelp.no_hp);	
			printf("-------------------------------------------------------------------------------------\n\n");
			printf("Inputkan No HP yang baru : ");
			scanf(" %[^\t\n]s", &bukuTelp.no_hp);
			
			fwrite(&bukuTelp, sizeof(bukuTelp), 1, fpt);
		}
	}
	
	fclose(fpo);
	fclose(fpt);
	
	fpo = fopen("./data/buku_telepon.txt", "w");
	fpt = fopen("./data/buku_teleponTmp.txt", "r");
	while(fread(&bukuTelp, sizeof(bukuTelp), 1, fpt)) {
	
			fwrite(&bukuTelp, sizeof(bukuTelp), 1, fpo);
	}
	
	fclose(fpo);
	fclose(fpt);
	
	if(not_found == 0) {
		printf("\nData berhasil diperbarui !\n\n");
	} else {
		printf("\n-------------------------------------------------------------------------------------\n");
		printf("| %25s | %25s | %25s |\n", "NAMA", "NIM", "NO HP");
		printf("-------------------------------------------------------------------------------------\n");
		printf("%60s","Data yang Anda cari tidak ditemukan\n");	
		printf("-------------------------------------------------------------------------------------\n\n");
	}
	
	
	printf("coba_lagi ? (y/n) : ");
	scanf(" %[^\t\n]s", &coba_lagi);
	
	if(strcmp(coba_lagi, "y") == 0) {
		system("cls");
		update_data();
	}
	
	back_to_menu();
}

void delete_data() {
	FILE *fpo;
	FILE *fpt;
	int nim, not_found = 1;
	char coba_lagi[2];
		
	fpo = fopen("./data/buku_telepon.txt", "r");
	fpt = fopen("./data/buku_teleponTmp.txt", "w");
	
	printf("=============================== Hapus Kontak Mahasiswa ===============================\n\n");
	
	printf("Inputkan NIM dari data yang ingin anda hapus : ");
	scanf("%d", &nim);
	
	while(fread(&bukuTelp, sizeof(bukuTelp), 1, fpo)) {
		if(bukuTelp.nim != nim) {
			fwrite(&bukuTelp, sizeof(bukuTelp), 1, fpt);
		} else {
			not_found = 0;
		}
	}
	
	fclose(fpo);
	fclose(fpt);
	
	fpo = fopen("./data/buku_telepon.txt", "w");
	fpt = fopen("./data/buku_teleponTmp.txt", "r");
	while(fread(&bukuTelp, sizeof(bukuTelp), 1, fpt)) {
		
			fwrite(&bukuTelp, sizeof(bukuTelp), 1, fpo);
	}
	
	fclose(fpo);
	fclose(fpt);
	
	if(not_found == 0) {
		printf("\nData berhasil dihapus !\n\n");
	} else {
		printf("\n-------------------------------------------------------------------------------------\n");
		printf("| %25s | %25s | %25s |\n", "NAMA", "NIM", "NO HP");
		printf("-------------------------------------------------------------------------------------\n");
		printf("%60s","Data yang Anda cari tidak ditemukan\n");	
		printf("-------------------------------------------------------------------------------------\n\n");
	}
	
	
	printf("coba_lagi ? (y/n) : ");
	scanf(" %[^\t\n]s", &coba_lagi);
	
	if(strcmp(coba_lagi, "y") == 0) {
		system("cls");
		delete_data();
	}
	
	back_to_menu();
}
