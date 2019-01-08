#include "header.h"

int main() {
	int pilih;
	
	printf("========= Sistem Manajemen Buku Telepon =========\n\n");
	
	printf("1. Tambah Kontak Mahasiswa\n");	
	printf("2. Lihat Semua Kontak Mahasiswa\n");
	printf("3. Cari Kontak Mahasiswa\n");
	printf("4. Edit Kontak Mahasiswa\n");
	printf("5. Hapus Kontak Mahasiswa\n\n");
	
	printf("Inputkan pilihan Anda : ");
	scanf("%d", &pilih);
	
	switch(pilih) {
		case 1:
			system("cls");
			printf("========= Tambah Kontak Mahasiswa =========\n\n");
			tambah_data();
			break;
		case 2:
			system("cls");
			lihat_data();
			break;	
		case 3:
			system("cls");
			cari_data();
			break;
		case 4:
			system("cls");
			update_data();
			break;
		case 5:
			system("cls");
			delete_data();
			break;			
	}
	
	return 0;
}
