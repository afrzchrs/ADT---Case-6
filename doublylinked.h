#ifndef DOUBLELINKED_H
#define DOUBLELINKED_H

#include "linkedlist.h" 

typedef char infotypeD[50];

typedef struct tElmt *addressD;
typedef struct tElmt {
    infotypeD info;
    address listNama;
    addressD next;
    addressD prev;
} tElmt;

// Function prototypes:
int D_isEmpty(addressD p);
void D_Create_Node(addressD *p);
void D_Isi_Node(addressD *p, infotypeD nilai);
void D_Ins_Awal(addressD *head, addressD *tail, addressD PNew);
void D_Ins_Akhir(addressD *head, addressD *tail, addressD PNew);
void D_InsertAfter(addressD pBef, addressD PNew);
void D_Del_Awal(addressD *head, addressD *tail, infotypeD *X);
void D_Del_After(addressD pBef, infotypeD *X);
void D_DelByValue(addressD *head, addressD *tail, infotypeD X);
void D_DeAlokasi(addressD *p);
addressD D_Search(addressD p, infotypeD nilai);
void D_Tampil_ListD(addressD p);
void D_TampilListDescending(addressD tail);
int D_CountElmt(addressD p);
addressD D_BalikList(addressD head, addressD *tail);

#endif

