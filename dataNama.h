#include "linkedlist.h"
#include "dataKota.h"

#ifndef DATANAMA_H
#define DATANAMA_H

typedef address dataNama;

void tambahNama(address *listNama);
void hapusNama(address *listNama);
void hapusSemuaNama(address *listNama);
void tambahNamaKeKota(addressD headKota);
void hapusNamaDariKota(addressD headKota);
address pilihKota(addressD headKota);
void buatNodeNama(address *p);
void inputNama(char *nama);

#endif

