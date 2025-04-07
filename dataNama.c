#include "dataNama.h"

address pilihKota(addressD headKota) {
    if (headKota == NULL) {
        printf("Belum ada kota.\n");
        return NULL;
    }

    int i = 1;
    addressD p = headKota;
    while (p != NULL) {
        printf("%d. %s\n", i++, p->info);
        p = p->next;
    }

    int pilih;
    printf("Pilih kota (nomor): ");
    scanf("%d", &pilih);
    getchar(); 

    if (pilih < 1) {
        printf("Pilihan tidak valid.\n");
        return NULL;
    }

    p = headKota;
    for (int j = 1; j < pilih && p != NULL; j++) {
        p = p->next;
    }

    return p;
}

void tambahNamaKeKota(addressD headKota) {
    addressD kota = pilihKota(headKota);
    if (kota != NULL) {
        tambahNama(&(kota->listNama));
    }
}

void hapusNamaDariKota(addressD headKota) {
    addressD kota = pilihKota(headKota);
    if (kota != NULL) {
        hapusNama(&(kota->listNama));
    }
}

void inputNama(char *nama) {
    printf("Masukkan nama: ");
    scanf("%49s", nama); 
}

void buatNodeNama(address *p) {
    Create_Node(p); 
}

void tambahNama(address *listNama) {
    char nama[50];
    inputNama(nama);

    address PNew;
    buatNodeNama(&PNew);
    Isi_Node(&PNew, nama);
    Ins_Akhir(listNama, PNew);
}

void hapusNama(address *listNama) {
	char nama[50];
    inputNama(nama);

    DelByValue(listNama, nama);
}

void hapusSemuaNama(address *listNama) {
    address temp;
    while (*listNama != NULL) {
        temp = *listNama;
        *listNama = (*listNama)->next;
        free(temp);
    }
}



