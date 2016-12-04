#include "list_child.h"

void createList(List_child &L) {
    /**
    * FS : first(L) diset Nil
           last(L) diset Nil
    */
    first(L) = NULL;
    last(L) = NULL;
}

address_child alokasi(infotype_child X) {
    /**
    * FS : mengembalikan elemen list baru dengan info = X, next, prev elemen = Nil
    */
    address_child P = new elmlist_child;
    info(P) = X;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertFirst(List_child &L, address_child P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    }
    else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List_child &L, address_child P){
    if(first(L) == NULL){
        first(L) = P;
        last(L) = P;
    }
    else{
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

void insertAfter(address_child &Prec, address_child P) {
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}

void deleteFirst(List_child &L ,address_child &P){
    if(first(L)!=NULL){
        P = first(L);
        if(first(L) == L.last){
            L.last = NULL;
            L.first = NULL;
        }
        else{
            L.first = P->next;
            L.first->prev = NULL;
            P->next = NULL;
        }
    }
}

void deleteLast(List_child &L, address_child &P){
    if(L.first!=NULL){
        P = L.last;
        if(L.first == L.last){
            L.first = NULL;
            L.last = NULL;
        }
        else{
            L.last = P->prev;
            L.last->next = NULL;
            P->prev = NULL;
        }
    }
}

void deleteAfter(address_child Prec, address_child &P){
    P= Prec->next;
    Prec->next = P->next;
    Prec->next->prev = P->prev;
    P->next = NULL;
    P->prev = NULL;
}

address_child findElm(List_child L, infotype_child X) {
    address_child P = first(L);
    while(P != NULL) {
        if(info(P).id==X.id) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void printInfo(List_child L) {
    address_child P = first(L);
    if (L.first != NULL){
        while(P !=NULL) {
            cout<<">"<<info(P).id<<endl;
            cout<<">"<<info(P).name<<endl;
            cout<<">"<<info(P).tgl<<endl;
            cout<<">"<<info(P).umur<<endl;
            cout<<">"<<info(P).alamat<<endl;
            P = next(P);
        }
    }
    else {
        cout << "Tidak ada pelanggan" << endl;
    }
}
