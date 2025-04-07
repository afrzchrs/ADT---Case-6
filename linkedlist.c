#include "linkedlist.h"

boolean isEmpty(address p) {
    return (p == NULL);
}

void Create_Node(address *p) {
    *p = (address) malloc(sizeof(tElmtList));
}

void Isi_Node(address *p, infotype nilai) {
    if (*p != NULL) {
        strcpy((*p)->info, nilai);
        (*p)->next = NULL;
    }
}

void Tampil_List(address p) {
    while (p != NULL) {
        printf("\"%s\" -> ", p->info);
        p = p->next;
    }
    printf("NULL\n");
}


void Ins_Awal(address *p, address PNew) {
    if (PNew != NULL) {
        PNew->next = *p;
        *p = PNew;
    }
}


void Ins_Akhir(address *p, address PNew) {
    if (*p == NULL) {
        *p = PNew;
    } else {
        address last = *p;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = PNew;
    }
}

void InsertAfter(address pBef, address PNew) {
    if (pBef != NULL && PNew != NULL) {
        PNew->next = pBef->next;
        pBef->next = PNew;
    }
}

void Del_Awal(address *p, infotype *X) {
    if (*p != NULL) {
        address temp = *p;
        strcpy(*X, temp->info);
        *p = temp->next;
        free(temp);
    }
}
void Del_Akhir(address *p, infotype *X) {
    if (*p != NULL) {
        address temp = *p, prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        strcpy(*X, temp->info);
        if (prev != NULL) {
            prev->next = NULL;
        } else {
            *p = NULL;
        }
        free(temp);
    }
}

void Del_After(address pBef, infotype *X) {
    if (pBef != NULL && pBef->next != NULL) {
        address temp = pBef->next;
        strcpy(*X, temp->info);
        pBef->next = temp->next;
        free(temp);
    }
}

void DelByValue(address *p, infotype X) {
    if (*p == NULL) return;
    if (strcmp((*p)->info, X) == 0) {
        address temp = *p;
        *p = (*p)->next;
        free(temp);
        return;
    }
    address temp = *p, prev = NULL;
    while (temp != NULL && strcmp(temp->info, X) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
}

void DeAlokasi(address *p) {
    free(*p);
    *p = NULL;
}

address Search(address p, infotype nilai) {
    while (p != NULL) {
        if (strcmp(p->info, nilai) == 0) return p;
        p = p->next;
    }
    return NULL;
}

int NbElmt(address p) {
    if (p == NULL) return 0;
    return 1 + NbElmt(p->next);
}

/*infotype Min(address p) {
    if (p == NULL) return -1; 
    infotype min = p->info;
    while (p != NULL) {
        if (p->info < min) min = p->info;
        p = p->next;
    }
    return min;
}

infotype Rerata(address p) {
    if (p == NULL) return 0;
    int sum = 0, count = 0;
    while (p != NULL) {
        sum += p->info;
        count++;
        p = p->next;
    }
    return sum / count;
}*/  

address BalikList(address p) {
    address prev = NULL, current = p, next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

/*void Ins_SortedByName(address *head, char *nama, int nilai) {
    address newNode = (address)malloc(sizeof(ElmtList));
    strcpy(newNode->nama, nama);
    newNode->nilai = nilai;
    newNode->next = NULL;
    
    if (*head == NULL || strcmp((*head)->nama, nama) > 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
address temp = *head;
    while (temp->next != NULL && strcmp(temp->next->nama, nama) < 0) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}*/

/*void TampilListDescending(address head) {
    if (!head) return;
    address sorted = NULL;
    while (head) {
        address newNode = (address)malloc(sizeof(Mahasiswa));
        strcpy(newNode->nama, head->nama);
        newNode->nilai = head->nilai;
        newNode->next = NULL;
        if (!sorted || newNode->nilai > sorted->nilai) {
            newNode->next = sorted;
            sorted = newNode;
        } else {
            address temp = sorted;
            while (temp->next && temp->next->nilai > newNode->nilai) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        head = head->next;
    }
    Tampil_List(sorted);
}*/

