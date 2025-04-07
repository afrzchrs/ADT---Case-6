#include "menuTmbhData.h"
void subMenuTmbhData(addressD** headKota, addressD** tailKota, int* jumlahKota) {
    int choice;

    while (1) {
        printf("\n====== Pilih Data Untuk Ditambah =======:\n");
        printf("1. Data Kota\n");
        printf("2. Data Nama\n");
        printf("3. Kembali\n");
        printf("Pilih: ");
        scanf("%d", &choice);
        
        getchar(); 

        switch (choice) {
            case 1:
                system("cls");
                tambahKota(headKota, tailKota, jumlahKota);
                break;

			case 2:
			    system("cls");
			    tambahNamaKeKota(*headKota);
			    break;
			    
            case 3:
                return; 

            default:
                printf("Pilihan tidak valid!\n");
        }
    }
}

