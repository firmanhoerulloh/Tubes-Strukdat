#include <iostream>
#include "Multiple_M_to_N.h"

using namespace std;

int main()
{
    list_penulis PENULIS;
    list_relation RELATION;
    list_buku BUKU;
    adr_penulis p;
    adr_relation r;
    adr_buku b;
    infotype_penulis info_penulis;
    infotype_buku info_buku;

    create_penulis(PENULIS);
    create_buku(BUKU);

    int pilihan = -1;
    string nama_penulis, judul_buku;
    while (pilihan != 0) {
        cout << "================ MENU ================" << endl;
        cout << "1. Menambahkan Penulis" << endl;
        cout << "2. Menambahkan Buku" << endl;
        cout << "3. Buat Relasi" << endl;
        cout << "4. Delete Penulis" << endl;
        cout << "5. Delete Buku dari Penulis" << endl;
        cout << "6. Cari Penulis" << endl;
        cout << "7. Cari Buku" << endl;
        cout << "8. Show Penulis" << endl;
        cout << "9. Show All Buku dari Penulis" << endl;
        cout << "10. Show Penulis dengan Buku terbanyak" << endl;
        cout << "11. Delete Relasi" << endl;
        cout << "12. Show Buku 2 Penulis" << endl;
        cout << "0. Keluar" << endl;
        cout << "Plih menu: "; cin >> pilihan;
        cout << "=======================================" << endl;

        if (pilihan == 1) {
            cout << "Menambahkan Penulis" << endl;
            cout << "=======================================" << endl;
            cout << "Nama: "; cin >> info_penulis.nama;
            cout << "Jenis Kelamin: "; cin >> info_penulis.jenis_kelamin;
            cout << "Umur: "; cin >> info_penulis.umur;
            p = new_penulis(info_penulis);
            insert_first_penulis(PENULIS,p);
            cout << "Berhasil ditambahkan" << endl;
            cout << "=======================================" << endl;
            cout << endl;
        } else if (pilihan == 2) {
            cout << "Menambahkan Buku" << endl;
            cout << "=======================================" << endl;
            cout << "Judul Buku: "; cin >> info_buku.judul;
            b = new_buku(info_buku);
            insert_last_buku(BUKU,b);
            cout << "Berhasil ditambahkan" << endl;
            cout << "=======================================" << endl;
            cout << endl;
        } else if (pilihan == 3) {
            cout << "Buat Relasi" << endl;
            cout << "=======================================" << endl;
            cout << "Nama Penulis: "; cin >> nama_penulis;
            cout << "Judul Buku: "; cin >> judul_buku;
            buat_relasi(BUKU,PENULIS,nama_penulis,judul_buku);
            cout << "Berhasil buat relasi" << endl;
            cout << "=======================================" << endl;
            cout << endl;
        } else if (pilihan == 4) {
            cout << "Delete Penulis" << endl;
            cout << "=======================================" << endl;
            cout << "Nama Penulis: "; cin >> nama_penulis;
            delete_penulis(PENULIS,BUKU,nama_penulis);
            cout << "Berhasil Delete penulis" << endl;
            cout << "=======================================" << endl;
            cout << endl;
        } else if (pilihan == 5) {
            cout << "Delete Buku dari Penulis" << endl;
            cout << "=======================================" << endl;
            cout << "Nama Penulis: "; cin >> nama_penulis;
            cout << "Judul Buku: "; cin >> judul_buku;
            delete_buku_dari_penulis(BUKU,PENULIS,nama_penulis, judul_buku);
            cout << "Berhasil delete buku dari penulis" << endl;
            cout << "=======================================" << endl;
            cout << endl;
        } else if (pilihan == 6) {
            cout << "Cari Penulis" << endl;
            cout << "=======================================" << endl;
            cout << "Nama Penulis: "; cin >> nama_penulis;
            p = search_penulis(PENULIS,nama_penulis);
            show_penulis_X(PENULIS,nama_penulis);
            cout << "Berhasil cari penulis" << endl;
            cout << "=======================================" << endl;
            cout << endl;
        } else if (pilihan == 7) {
            cout << "Cari Buku" << endl;
            cout << "=======================================" << endl;
            cout << "nama_penulis: "; cin >> nama_penulis;
            cout << "judul buku: "; cin >> judul_buku;
            b = search_buku_dari_penulis(BUKU,PENULIS,nama_penulis,judul_buku);
            if (b == nil) {
                cout << "Buku tidak ditemukan" << endl;
            } else {
                cout << "Buku Ditemukan"<< endl;
            }
            cout << "=======================================" << endl;
            cout << endl;
        } else if (pilihan == 8) {
            cout << "Show Penulis" << endl;
            cout << "=======================================" << endl;
            cout << "Nama Penulis: "; cin >> nama_penulis;
            cout << "============ Data Penulis =============" << endl;
            show_penulis_X(PENULIS,nama_penulis);
            cout << "Berhasil Show Penulis" << endl;
            cout << "=======================================" << endl;
            cout << endl;
        } else if (pilihan == 9) {
            cout << "Show all buku dari penulis" << endl;
            cout << "=======================================" << endl;
            cout << "Nama Penulis: "; cin >> nama_penulis;
            show_all_buku_oleh_penulis(BUKU,PENULIS,nama_penulis);
            cout << "berhasil show all buku dari penulis" << endl;
            cout << "=======================================" << endl;
            cout << endl;
        } else if (pilihan == 10) {
            cout << "show penulis dengan buku terbanyak" << endl;
            cout << "=======================================" << endl;
            show_penulis_buku_terbanyak(PENULIS,BUKU);
            cout << "Berhasil show penulis dengan buku terbanyak" << endl;
            cout << "=======================================" << endl;
            cout << endl;
        } else if (pilihan == 11){
            cout << "Delete Relasi" << endl;
            cout << "=======================================" << endl;
            cout << "Nama Penulis: "; cin >> nama_penulis;
            cout << "Judul Buku: "; cin >> judul_buku;
            delete_relasi(BUKU,PENULIS,nama_penulis,judul_buku);
            cout << "Berhasil delete relasi" << endl;
            cout << "=======================================" << endl;
            cout << endl;
        } else if (pilihan == 12) {
            cout << "show Buku 2 Penulis" << endl;
            cout << "=======================================" << endl;
            show_buku_2_penulis(BUKU,PENULIS);
            cout << "Berhasil show penulis dengan buku terbanyak" << endl;
            cout << "=======================================" << endl;
            cout << endl;
        } else {
            cout << "Sekian dan Terima Kasih" << endl;
        }
    }
    return 0;
}
