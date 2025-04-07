#include "dataKota.h"

void inputKota(char *nama) {
    printf("Masukkan nama kota: ");
    scanf("%49s", nama);
}

void D_buatNode(addressD *p) {
    D_Create_Node(p);
    (*p)->listNama = NULL; 
}


void tambahKota(addressD *head, addressD *tail, int *jmlhKota) {
    char namaKota[50];
    inputKota(namaKota);

    addressD pNew;
    D_buatNode(&pNew);
    D_Isi_Node(&pNew, namaKota);
    
    D_Ins_Akhir(head, tail, pNew);
    (*jmlhKota)++;
}

void hapusKota(addressD *head, addressD *tail, int *jmlhKota) {
    if (*head == NULL) {
        printf("Daftar kota kosong!\n");
        return;
    }

    char namaKota[50];
    inputKota(namaKota);

    addressD found = D_Search(*head, namaKota);
    if (found == NULL) {
        printf("Kota '%s' tidak ditemukan!\n", namaKota);
        return;
    }

    // Hapus semua nama yang terkait dengan kota
    hapusSemuaNama(&(found->listNama));

    D_DelByValue(head, tail, namaKota);
    (*jmlhKota)--;
    printf("Kota '%s' dan seluruh nama di dalamnya berhasil dihapus!\n", namaKota);
}




