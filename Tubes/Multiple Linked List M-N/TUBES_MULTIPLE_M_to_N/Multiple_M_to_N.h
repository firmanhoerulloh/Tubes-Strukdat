#ifndef MULTIPLE_M_TO_N_H_INCLUDED
#define MULTIPLE_M_TO_N_H_INCLUDED

#include <iostream>
using namespace std;

#define nil NULL
// Definisi Penulis
#define info_penulis(P) (P) -> info_penulis
#define next_penulis(P) P -> next_penulis
#define first_penulis(L) L.first_penulis

// Definisi Buku
#define info_buku(P) (P) -> info_buku
#define next_buku(P) P -> next_buku
#define first_buku(L) L.first_buku
#define last_buku(L) L.last_buku


// Definisi relation
#define next_relation(P) (P) -> next_relation
#define first_relation(L) (L).first_relation
#define listRel(P) (P)->listRel

typedef struct penulis infotype_penulis;
typedef struct elm_penulis *adr_penulis;

typedef struct buku infotype_buku;
typedef struct elm_buku *adr_buku;

typedef struct elm_relation *adr_relation;

// L3 relations
struct elm_relation{
    adr_penulis penulis;
    adr_relation next_relation;
};
struct list_relation{
    adr_relation first_relation;
};

// L1 penulis
struct penulis{
    string nama;
    string jenis_kelamin;
    int umur;
};

struct elm_penulis{
    infotype_penulis info_penulis;
    adr_penulis next_penulis;
};

struct list_penulis{
    adr_penulis first_penulis;
};

// L2 buku
struct buku{
    string judul;
};

struct elm_buku{
    infotype_buku info_buku;
    adr_buku next_buku;
    list_relation listRel;
};

struct list_buku{
    adr_buku first_buku;
    adr_buku last_buku;
};

void create_penulis(list_penulis &L_penulis);
void create_buku(list_buku &L_buku);
adr_penulis new_penulis(infotype_penulis x);
adr_buku new_buku(infotype_buku x);
adr_relation new_relation(adr_penulis p);

void insert_first_penulis(list_penulis &L_penulis, adr_penulis p);
void insert_last_penulis(list_penulis &L_penulis, adr_penulis p);
void insert_first_buku(list_buku &L_buku, adr_buku p);
void insert_last_buku(list_buku &L_buku, adr_buku p);

void buat_relasi(list_buku &L_buku, list_penulis L_penulis, string nama_penulis, string judul_buku);
void delete_relasi( list_buku &L_buku, list_penulis L_penulis, string nama_penulis, string judul_buku);

adr_penulis search_penulis(list_penulis L_penulis, string nama_penulis);
adr_buku search_buku(list_buku L_buku, string judul_buku);
adr_buku search_buku_dari_penulis(list_buku L_buku, list_penulis L_penulis, string nama_penulis, string judul_buku);

void delete_penulis_dari_buku(list_buku L_buku, string nama_penulis);
void delete_penulis(list_penulis &L_penulis, list_buku &L_buku, string nama_penulis);
void delete_buku_dari_penulis(list_buku &L_buku, list_penulis L_penulis, string nama_penulis, string judul_buku);


void show_penulis_X(list_penulis L_penulis, string nama_penulis);
void show_all_buku_oleh_penulis(list_buku L_buku, list_penulis L_penulis, string nama_penulis);
int hitung_buku_penulis(list_buku L_buku, string nama_penulis);
void show_penulis_buku_terbanyak(list_penulis L_penulis, list_buku L_buku);
void show_buku_2_penulis(list_buku L_buku, list_penulis L_penulis);

#endif // MULTIPLE_M_TO_N_H_INCLUDED
