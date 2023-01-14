#include "Multiple_M_to_N.h"

void create_penulis(list_penulis &L_penulis){
    first_penulis(L_penulis) = nil;
}

void create_buku(list_buku &L_buku){
    first_buku(L_buku) = nil;
    last_buku(L_buku) = nil;
}

adr_penulis new_penulis(infotype_penulis x){
    adr_penulis p = new elm_penulis;
    info_penulis(p) = x;
    next_penulis(p) = nil;
    return p;
}

adr_buku new_buku(infotype_buku x){
    adr_buku p = new elm_buku;
    adr_relation r;
    info_buku(p) = x;
    next_buku(p) = nil;
    first_relation(p -> listRel) = nil;
    return p;

}

adr_relation new_relation(adr_penulis p){
    adr_relation r = new elm_relation;
    r->penulis = p;
    next_relation(r) = nil;
    return r;
}

void insert_first_penulis(list_penulis &L_penulis, adr_penulis p){
    next_penulis(p) = first_penulis(L_penulis);
    first_penulis(L_penulis) = p;
}

void insert_last_penulis(list_penulis &L_penulis, adr_penulis p){
    adr_penulis q;
    if (first_penulis(L_penulis) != nil) {
        q = first_penulis(L_penulis);
        while (next_penulis(q) != nil) {
            q = next_penulis(q);
        }
        next_penulis(q) = p;
    } else {
        first_penulis(L_penulis) = p;
    }
}

void insert_first_buku(list_buku &L_buku, adr_buku p){
    adr_buku q = first_buku(L_buku);
    if (q == nil){
        first_buku(L_buku) = p;
        last_buku(L_buku) = p;
        next_buku(first_buku(L_buku)) = last_buku(L_buku);
        last_buku(L_buku) = first_buku(L_buku);
    }
    else{
        next_buku(first_buku(L_buku)) = p;
        next_buku(last_buku(L_buku)) = p;
        last_buku(L_buku) = p;
    }
}

void insert_last_buku(list_buku &L_buku, adr_buku p){
    adr_buku q = first_buku(L_buku);

    if (q == nil){
        first_buku(L_buku) = p;
        last_buku(L_buku) = p;
        next_buku(first_buku(L_buku)) = last_buku(L_buku);
        last_buku(L_buku) = first_buku(L_buku);
    }
    else{
        next_buku(last_buku(L_buku)) = p;
        next_buku(p) = first_buku(L_buku);
        last_buku(L_buku) = p;
    }
}

void buat_relasi(list_buku &L_buku, list_penulis L_penulis, string nama_penulis, string judul_buku){
    adr_penulis p = search_penulis(L_penulis, nama_penulis);
    adr_buku b = search_buku(L_buku, judul_buku);

    if (p == nil){
        cout << "Nama penulis tidak ada" << endl;
    }
    else if (b == nil){
        cout << "Judul buku tidak ada" << endl;
    }
    else{
        adr_relation r = new_relation(p);
        next_relation(r) = first_relation(b->listRel);
        first_relation(b->listRel) = r;
    }
}

void delete_relasi( list_buku &L_buku, list_penulis L_penulis, string nama_penulis, string judul_buku){
    adr_penulis p = search_penulis(L_penulis, nama_penulis);
    adr_buku b = search_buku_dari_penulis(L_buku, L_penulis, nama_penulis, judul_buku);

    if (b == nil){
        cout << "Tidak ada relasi" << endl;
    }
    else{
        adr_relation r = first_relation(b->listRel);
        if (info_penulis(p).nama == nama_penulis){
            first_relation(b->listRel) = next_relation(first_relation(b->listRel));
        }
        else{
            while (next_relation(r) != nil){
                if (info_penulis(p).nama == nama_penulis){
                    next_relation(r) = next_relation(next_relation(r));
                    break;
                }
                r = next_relation(r);
            }
        }
    }
}

adr_penulis search_penulis(list_penulis L_penulis, string nama_penulis){
    adr_penulis P = first_penulis(L_penulis);
    while(P != nil){
        if (info_penulis(P).nama == nama_penulis){
            return P;
        }
        P = next_penulis(P);
    }
    return nil;
}

adr_buku search_buku(list_buku L_buku, string judul_buku){
    adr_buku b = first_buku(L_buku);
    if (b != nil){
        do{
            if (info_buku(b).judul == judul_buku){
                return b;
            }
            b = next_buku(b);
        } while (b != first_buku(L_buku));
    }
    return nil;
}
adr_buku search_buku_dari_penulis(list_buku L_buku, list_penulis L_penulis, string nama_penulis, string judul_buku){
    adr_penulis p = search_penulis(L_penulis, nama_penulis);
    adr_buku b = search_buku(L_buku, judul_buku);

    if (b != nil && p != nil){
        adr_relation r = first_relation(b->listRel);
        while (r != nil){
            if (info_penulis(p).nama == nama_penulis){
                return b;
            }
            r = next_relation(r);
        }
    }
    return nil;
}

void delete_penulis_dari_buku(list_buku L_buku, string nama_penulis){
    adr_buku b = first_buku(L_buku);
    do{
        adr_relation r = first_relation(b->listRel);
        if (r != nil){
            if (info_penulis(r->penulis).nama == nama_penulis){
                first_relation(b->listRel) = next_relation(first_relation(b->listRel));
            }
            else{
                while (next_relation(r) != nil){
                    if (info_penulis((next_relation(r)->penulis)).nama == nama_penulis){
                        next_relation(r) = next_relation(next_relation(r));
                        break;
                    }
                    r = next_relation(r);
                }
            }
        }
        b = next_buku(b);
    } while (b != first_buku(L_buku));
}

void delete_penulis(list_penulis &L_penulis, list_buku &L_buku, string nama_penulis){
    adr_penulis p = first_penulis(L_penulis);
    bool ketemu = false;
    if (p == nil){
        cout << "penulis tidak ditemukan" << endl;
    }
    else{
        if (first_buku(L_buku) == nil){
            cout << "buku tidak ditemukan" << endl;
        }
        else{
            if (info_penulis(p).nama == nama_penulis){
                delete_penulis_dari_buku(L_buku, nama_penulis);
                first_penulis(L_penulis) = next_penulis(first_penulis(L_penulis));
                ketemu = true;
            }
            else{
                while (next_penulis(p) != nil){
                    if (info_penulis(next_penulis(p)).nama == nama_penulis){
                        delete_penulis_dari_buku(L_buku, nama_penulis);
                        next_penulis(p) = next_penulis(next_penulis(p));
                        ketemu = true;
                        break;
                    }
                    p = next_penulis(p);
                }
            }
            if (!ketemu){
                cout << "penulis tidak ditemukan" << endl;
            }
        }
    }
}

void delete_buku_dari_penulis(list_buku &L_buku, list_penulis L_penulis, string nama_penulis, string judul_buku){
    adr_penulis p = search_penulis(L_penulis, nama_penulis);
    adr_buku b = search_buku_dari_penulis(L_buku, L_penulis, nama_penulis, judul_buku);

    if (b == nil) {
        cout << "Buku tidak ada" << endl;
    }
    else{
        adr_relation r = first_relation(b->listRel);
        if (info_penulis(p).nama == nama_penulis){
            first_relation(b->listRel) = next_relation(first_relation(b->listRel));
        }
        else{
            while (next_relation(r) != nil){
                if (info_penulis(p).nama == nama_penulis){
                    next_relation(r) = next_relation(next_relation(r));
                    break;
                }
                r = next_relation(r);
            }
        }
    }
}

void show_penulis_X(list_penulis L_penulis, string nama_penulis){
    adr_penulis P = search_penulis(L_penulis, nama_penulis);
    if(P != nil){
        cout << "Nama penulis: " << info_penulis(P).nama << endl;
        cout << "Jenis Kelamin: " << info_penulis(P).jenis_kelamin << endl;
        cout << "Umur: " << info_penulis(P).umur << endl;
    }else{
        cout << "Penulis tidak ditemukan" << endl;
    }
}

void show_all_buku_oleh_penulis(list_buku L_buku, list_penulis L_penulis, string nama_penulis){
    adr_penulis penulis = search_penulis(L_penulis, nama_penulis);
    if (penulis == nil){
        cout << "Nama penulis tidak ditemukan" << endl;
    }else if (penulis != nil){
        cout << "Buku yang ditulis: " << endl;
        adr_buku b = first_buku(L_buku);
        do {
            adr_relation r = first_relation(b->listRel);
            while (r != nil){
                if (r->penulis == penulis){
                    cout << info_buku(b).judul << endl;
                    break;
                }
                r = next_relation(r);
            }
            b = next_buku(b);
        } while ( b != first_buku(L_buku));
    }
}
int hitung_buku_penulis(list_buku L_buku, string nama_penulis){
    int jumlah = 0;
    adr_buku b = first_buku(L_buku);
    if (b != nil){
        do{
            adr_relation r = first_relation(b->listRel);
            while (r != nil){
                if (info_penulis(r->penulis).nama == nama_penulis){
                    jumlah++;
                }
                r = next_relation(r);
            }
            b = next_buku(b);
        } while (b != first_buku(L_buku));
    }
    return jumlah;
}

void show_penulis_buku_terbanyak(list_penulis L_penulis, list_buku L_buku){
    adr_penulis p = first_penulis(L_penulis);
    if (p == nil){
        cout << "Tidak ada penulis" << endl;
    }
    else{
        adr_penulis p_terbanyak = p;
        int terbanyak_sementara = hitung_buku_penulis(L_buku,info_penulis(p).nama);
        p = next_penulis(p);
        while (p != nil){
            int jumlah_buku = hitung_buku_penulis(L_buku, info_penulis(p).nama);
            if (jumlah_buku > terbanyak_sementara){
                terbanyak_sementara = jumlah_buku;
                p_terbanyak = p;
            }
            p = next_penulis(p);
        }
        cout << "Nama Penulis: " << info_penulis(p_terbanyak).nama << endl;
        show_all_buku_oleh_penulis(L_buku, L_penulis, info_penulis(p_terbanyak).nama);
    }
}

void show_buku_2_penulis(list_buku L_buku, list_penulis L_penulis){
    adr_buku P_buku = first_buku(L_buku);
    adr_relation P_rel;
    int count;

    while(P_buku != nil){
        count = 0;
        P_rel = first_relation(listRel(P_buku));
        while(P_rel != nil){
            count++;
            P_rel = next_relation(P_rel);
        }
        if(count == 2){
            cout << "Judul buku: " << info_buku(P_buku).judul << endl;
            P_rel = first_relation(listRel(P_buku));
            while(P_rel != nil){
                cout << "Penulis: " << info_penulis(P_rel->penulis).nama << endl;
                P_rel = next_relation(P_rel);
            }
        }
        P_buku = next_buku(P_buku);
    }
}

