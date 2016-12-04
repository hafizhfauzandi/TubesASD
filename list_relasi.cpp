#include "list_relasi.h"

void createList(List_relasi &L) {
    /**
    * FS : first(L) diset Nil
    */
    first(L) = NULL;
}

address_relasi alokasi(address_child C) {
    /**
    * FS : mengembalikan elemen list baru dengan info = C, next elemen = Nil
    */
    address_relasi P = new elmlist_relasi;
    info(P) = C;
    next(P) = NULL;
    return P;
}

void insertFirst(List_relasi &L, address_relasi P) {
    next(P) = first(L);
    first(L) = P;
}

void insertLast(List_relasi &L, address_relasi P){
    if(L.first == NULL){
        L.first = P;
    }
    else{
        address_relasi q = L.first;
        while(q->next != NULL){
            q=q->next;
        }
        q->next = P;
    }
}

void insertAfter(address_relasi &Prec, address_relasi P) {
    next(P) = next(Prec);
    next(Prec) = P;
}

void deleteFirst(List_relasi &L, address_relasi &P){
    if(L.first == NULL){
    }
    else{
        P = L.first;
        L.first = P->next;
        P->next = NULL;
    }
}

void deleteLast(List_relasi &L, address_relasi &P){
    if(L.first == NULL){
    }
    else{
        P=L.first;
        if(P->next == NULL){
            L.first = NULL;
        }
        else{
            address_relasi q=P;
            while(q->next->next != NULL){
                q=q->next;
            }
            P = q->next;
            q->next = NULL;
        }
    }
}

void deleteAfter(address_relasi Prec, address_relasi &P){
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}

address_relasi findElm(List_relasi L, address_child C) {
    address_relasi P = first(L);
    while(P != NULL) {
        if(info(P)==C) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void printInfo(List_relasi L) {
    address_relasi P = first(L);
    while(P !=NULL) {
        cout<<"->"<<info(info(P)).name<<endl;
        P = next(P);
    }
}
