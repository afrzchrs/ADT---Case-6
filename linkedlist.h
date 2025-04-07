#include "boolean.h"
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef char infotype[50];  

typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype info;
    address next;
} tElmtList;

// Deklarasi fungsi
boolean isEmpty(address p);
void Create_Node(address *p);
void Isi_Node(address *p, infotype info);
void Tampil_List(address p);
void Ins_Awal(address *p, address PNew);
void Ins_Akhir(address *p, address PNew);
void InsertAfter(address pBef, address PNew);
void Del_Awal(address *p, infotype *X);
void Del_Akhir(address *p, infotype *X);
void Del_After(address pBef, infotype *X);
void DelByValue(address *p, infotype X);
void DeAlokasi(address *p);
address Search(address p, infotype info);
int CountElmt(address p);
//infotype Min(address p); Tidak digunakan
//infotype Rerata(address p); Tidak digunakan
address BalikList(address p);
//void TampilListDescending(address head);
//void Ins_SortedByName(address *head, char *nama, int nilai)

#endif

