#ifndef DATAKOTA_H
#define DATAKOTA_H

#include "doublylinked.h"
#include "dataNama.h" 

void inputKota(char *nama);
void D_buatNode(addressD *p);
void tambahKota(addressD *head, addressD *tail, int *jmlhKota);
void hapusKota(addressD *head, addressD *tail, int *jmlhKota);

#endif

