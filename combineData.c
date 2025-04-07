#include "combineData.h"
	
void tampilLinkedListKotaDanNama(addressD headKota) {
    if (headKota == NULL) {
        printf("Belum ada data kota.\n");
        return;
    }

    // Tampilkan urutan kota (linked list doubly)
    printf("KOTA: ");
    addressD pKota = headKota;
    while (pKota != NULL) {
        printf("%s", pKota->info);
        if (pKota->next != NULL) {
            printf(" -> ");
        }
        pKota = pKota->next;
    }
    printf(" -> NULL\n\n");

    // Tampilkan nama-nama di tiap kota
    pKota = headKota;
    while (pKota != NULL) {
        printf("  %s:\n", pKota->info);
        address pNama = pKota->listNama;
        if (pNama == NULL) {
            printf("    (tidak ada nama)\n");
        } else {
            printf("    ");
            while (pNama != NULL) {
                printf("[%s]", pNama->info);
                if (pNama->next != NULL) {
                    printf(" -> ");
                }
                pNama = pNama->next;
            }
            printf(" -> NULL\n");
        }
        pKota = pKota->next;
    }
}
