#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;
#include "list_child.h"
#include "list_parent.h"

int main()
{
    List_child lc;
    createList(lc);
    List_parent lp;
    createList(lp);
    infotype_parent infop;
    infotype_child infoc;
    int pilihan;
    string Id,nama,cabang,Alamat,jenis;

    do{
        system("cls");
        cout<<"Menu : "<<endl;
        cout<<"1. Input Nama Supermarket"<<endl;
        cout<<"2. Input Pelanggan"<<endl;
        cout<<"3. Input Pelanggan Lainnya"<<endl;
        cout<<"4. Cari Supermarket"<<endl;
        cout<<"5. Cari Pelanggan"<<endl;
        cout<<"6. Delete Supermarket"<<endl;
        cout<<"7. Delete Pelanggan"<<endl;
        cout<<"8. Lihat Data Keseluruhan"<<endl;
        cout<<"Pilihan : ";
        cin>>pilihan;

        if(pilihan==1){
            cout<<"Input Supermarket"<<endl;
            cout<<"ID Supermarket : ";
            cin>> infop.Id;
            cout<<"Nama Supermarket : ";
            cin>> infop.nama;
            cout<<"Cabang : ";
            cin>> infop.cabang;
            cout<<"Alamat : ";
            cin>>infop.Alamat;
            cout<<"Jenis Supermarket : ";
            cin>>infop.jenis;
            address_parent p = alokasi(infop);
            insertFirst(lp,p);
            getch();
        }
        else if(pilihan==2){
            cout<<"Input Pelanggan"<<endl;
            cout<<"ID Pelanggan :";
            cin>>infoc.id;
            cout<<"Nama Pelanggan :";
            cin>>infoc.name;
            cout<<"Tanggal Berlangganan:";
            cin>>infoc.tgl;
            cout<<"Umur :";
            cin>>infoc.umur;
            cout<<"Alamat :";
            cin>>infoc.alamat;
            address_child c = alokasi(infoc);
            insertFirst(lc,c);
            getch();
        }

        else if(pilihan==3){
            cout<<"Input Pelanggan Lainnya"<<endl;
            cout<<"ID Pelanggan : ";
            cin>>infoc.id;
            cout<<"Nama Pelanggan : ";
            cin>> infoc.name;
            cout<<"Tanggal Berlangganan : ";
            cin>> infoc.tgl;
            cout<<"Umur : ";
            cin>>infoc.umur;
            cout<<"Alamat : ";
            cin>>infoc.alamat;
            ;
            address_parent p= findElm(lp, infop);
            address_child c=findElm(lc,infoc);
            if(p!=NULL && c!=NULL){
                address_relasi r = alokasi(c);
                insertFirst(p->child,r);
            }
            else{
                cout<<"tidak ditemukan"<<endl;
            }
            getch();
        }
        else if(pilihan==4){
            cout<<"Cari Supermarket"<<endl;
            cout<<"ID Supermarket : ";
            cin>> infop.nama;
            address_parent p= findElm(lp, infop);
            if(p!=NULL ){
                cout<<p->info.Id<<endl;
                cout<<p->info.nama<<endl;
                cout<<p->info.cabang<<endl;
                cout<<p->info.Alamat<<endl;
                cout<<p->info.jenis<<endl;
            }
                else{
                        cout<<"data error"<<endl;
            }
            getch();
        }

        else if(pilihan==5){
            cout<<"Cari Pelanggan"<<endl;
            cout<<"ID Pelanggan : ";
            cin>> infoc.name;
            address_child c= findElm(lc, infoc);
            if(c!=NULL ){
                cout<<c->info.name<<endl;
                cout<<c->info.tgl<<endl;
                cout<<c->info.umur<<endl;
                cout<<c->info.alamat<<endl;
            }
                else{
                        cout<<"data error"<<endl;
            }

            getch();
        }

        else if(pilihan==6){

            cout<<"delete data"<<endl;

            infotype_parent x;
            cin >> x.Id;
            address_parent p;
            p = findElm(lp,x);
            if (p != NULL){
                if (p == lp.first){
                    deleteFirst(lp,p);
                    cout<<"data berhasil dihapus"<<endl;
                }
            }
            else {
                cout << "data tidak ditemukan" << endl;
            }
            getch();
        }

        else if(pilihan==7){

            cout<<"delete data"<<endl;
//                createList(lp);
//                createList(lc);
            infotype_child x;
            cin >> x.id;
            address_child p;
            p = findElm(lc,x);
            if (p != NULL){
                if (p == lc.first){
                    deleteFirst(lc,p);
                    cout<<"data berhasil dihapus"<<endl;
                }
            }
            else {
                cout << "data tidak ditemukan" << endl;
            }

//                cout<<"data kosong"<<endl;
            getch();
        }
        else if(pilihan==8){

            cout<<"Liat Semua Data"<<endl;
            if (lp.first == NULL){
                cout << "Tidak ada supermarket" << endl;
            }
            else {
                printInfo(lp);
                printInfo(lc);
            }

//            cout<<"data kosong"<<endl;
            getch();
        }
        else {
            cout<<"Menu tidak tersedia"<<endl;
            getch();
        }
    }while(pilihan!=9);
}
