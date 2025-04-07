#include "doublylinked.h"

int D_isEmpty(addressD p) {
    return (p == NULL);
}

void D_Create_Node(addressD *p) {
    *p = (addressD)malloc(sizeof(tElmt));
    if (*p != NULL) {
        (*p)->next = NULL;
        (*p)->prev = NULL;
        (*p)->listNama = NULL;
        strcpy((*p)->info, ""); 
    }
}

void D_Isi_Node(addressD *p, infotypeD nilai) {
    strcpy((*p)->info, nilai);
}

void D_Tampil_ListD(addressD p) {
    while (p != NULL) {
        printf("%s -> ", p->info);
        p = p->next;
    }
    printf("NULL\n");
}

void D_TampilListDescending(addressD tail) {
    while (tail != NULL) {
        printf("%s -> ", tail->info);
        tail = tail->prev;
    }
    printf("NULL\n");
}

void D_Ins_Awal(addressD *head, addressD *tail, addressD PNew) {
    if (D_isEmpty(*head)) {
        *head = *tail = PNew;
    } else {
        PNew->next = *head;
        (*head)->prev = PNew;
        *head = PNew;
    }
}

void D_Ins_Akhir(addressD *head, addressD *tail, addressD PNew) {
    if (*head == NULL) {
        *head = *tail = PNew;
    } else {
        (*tail)->next = PNew;
        PNew->prev = *tail;
        *tail = PNew;
    }
    printf("Node '%s' ditambahkan ke list.\n", PNew->info);
}

void D_InsertAfter(addressD pBef, addressD PNew) {
    if (pBef->next != NULL) {
        PNew->next = pBef->next;
        pBef->next->prev = PNew;
    }
    PNew->prev = pBef;
    pBef->next = PNew;
}

void D_Del_Awal(addressD *head, addressD *tail, infotypeD *X) {
    addressD pDel = *head;
    if (*head == *tail) {
        *head = *tail = NULL;
    } else {
        *head = (*head)->next;
        (*head)->prev = NULL;
    }
    strcpy(*X, pDel->info);
    free(pDel);
}

void D_Del_After(addressD pBef, infotypeD *X) {
    addressD pDel = pBef->next;
    if (pDel != NULL) {
        pBef->next = pDel->next;
        if (pDel->next != NULL) {
            pDel->next->prev = pBef;
        }
        strcpy(*X, pDel->info);
        free(pDel);
    }
}

void D_DelByValue(addressD *head, addressD *tail, infotypeD X) {
    addressD pDel = *head;
    while (pDel != NULL && strcmp(pDel->info, X) != 0) {
        pDel = pDel->next;
    }
    if (pDel != NULL) {
        if (pDel == *head) {
            *head = pDel->next;
            if (*head != NULL) (*head)->prev = NULL;
        } else if (pDel == *tail) {
            *tail = pDel->prev;
            if (*tail != NULL) (*tail)->next = NULL;
        } else {
            pDel->prev->next = pDel->next;
            pDel->next->prev = pDel->prev;
        }
        free(pDel);
    }
}

void D_DeAlokasi(addressD *p) {
    free(*p);
    *p = NULL;
}

addressD D_Search(addressD p, infotypeD nilai) {
    while (p != NULL) {
        if (strcmp(p->info, nilai) == 0) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

int D_CountElmt(addressD p) {
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

addressD D_BalikList(addressD head, addressD *tail) {
    addressD curr = head;
    addressD prev = NULL;
    *tail = head;

    while (curr != NULL) {
        addressD nextNode = curr->next;
        curr->next = prev;
        curr->prev = nextNode;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

