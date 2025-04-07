#include "menuHpsData.h"

// Update the function definition to match the declaration
void subMenuHpsData(addressD** headKota, addressD** tailKota, int* jumlahKota) {
    int choice;

    while (1) {
        printf("\n====== Pilih Data Untuk Dihapus =======:\n");
        printf("1. Hapus Data Kota\n");
        printf("2. Hapus Data Nama\n");
        printf("3. Kembali\n");
        printf("Pilih: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                system("cls");
                hapusKota(headKota, tailKota, jumlahKota); 
                break;
            case 2:
                system("cls");
                hapusNamaDariKota(*headKota);
                break;
            case 3:
                return; 
            default:
                printf("Pilihan tidak valid!\n");
        }
    }
}
