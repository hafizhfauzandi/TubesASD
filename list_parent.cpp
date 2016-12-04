#include "list_parent.h"

void createList(List_parent &L) {
    /**
    * FS : first(L) diset Nil
    */
    first(L) = NULL;
}

address_parent alokasi(infotype_parent x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x, next elemen = Nil
    */
    address_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    createList(child(P));
    return P;
}

void insertFirst(List_parent &L, address_parent P) {
    /**
    * IS : list_parent L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List_parent L
    *      next dari last elemen menunjuk ke first elemen
    */
    address_parent Q;
    if(first(L) == NULL) {
        first(L) = P;
    }
    else {
        Q = first(L);
        while(next(Q) != first(L)) {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void insertLast(List_parent &L, address_parent P){
    if(L.first == NULL){
        L.first = P;
    }
    else{
        address_parent q = L.first;
        while(q->next != NULL){
            q=q->next;
        }
        q->next = P;
    }
}

void insertAfter(address_parent Prec, address_parent P){
    P->next = Prec->next;
    Prec->next = P;
}

void deleteFirst(List_parent &L, address_parent &P){

    if (P->next == NULL){
        createList(L);
    }
    else{
        address_parent q = L.first;
        q = q->next;
        P->next = NULL;
        L.first = q;
        delete P;
    }
}

void deleteLast(List_parent &L, address_parent &P){
    if(L.first == NULL){
    }
    else{
        P=L.first;
        if(P->next == NULL){
            L.first = NULL;
        }
        else{
            address_parent q=P;
            while(q->next->next != NULL){
                q=q->next;
            }
            P = q->next;
            q->next = NULL;

        }
    }
}

void deleteAfter(List_parent &L, address_parent Prec, address_parent &P){
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}

address_parent findElm(List_parent L, infotype_parent x) {
    /**
    * IS : List_parent L mungkin kosong
    * FS : mengembalikan elemen dengan info nama = x.nama,
           mengembalikan elemen dengan info = x,
           mengembalikan Nil jika tidak ditemukan
    */
    address_parent P = first(L);
    do {
        if(info(P).Id == x.Id) {
            return P;
        }
        P = next(P);
    }
    while(P!=first(L));
    return NULL;
}

void printInfo(List_parent L) {
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    address_parent P = first(L);
    if(first(L)!=NULL) {
        do {
            cout<<info(P).Id<<endl;
            cout<<info(P).nama<<endl;
            cout<<info(P).cabang<<endl;
            cout<<info(P).Alamat<<endl;
            cout<<info(P).jenis<<endl;
            printInfo(child(P));
            P = next(P);
        } while((P)!=NULL);
    }

    else {
        cout << "Tidak ada supermarket" << endl;
    }
}
