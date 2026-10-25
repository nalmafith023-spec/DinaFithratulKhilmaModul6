#include "Doublylist.h"

int main() {
    List L;
    infotype kendaraan;
    address P, hasil, Prec, hapus;

    // Membuat list
    CreateList(L);

    // Menambahkan kendaraan pertama
    kendaraan.nopol = "D001";
    kendaraan.warna = "Hitam";
    kendaraan.thnBuat = 2020;
    P = alokasi(kendaraan);
    insertLast(L, P);

    // Menambahkan kendaraan kedua
    kendaraan.nopol = "D002";
    kendaraan.warna = "Putih";
    kendaraan.thnBuat = 2021;
    P = alokasi(kendaraan);
    insertLast(L, P);

    // Menambahkan kendaraan ketiga
    kendaraan.nopol = "D003";
    kendaraan.warna = "Biru";
    kendaraan.thnBuat = 2022;
    P = alokasi(kendaraan);
    insertLast(L, P);

    // Menambahkan kendaraan keempat
    kendaraan.nopol = "D004";
    kendaraan.warna = "Merah";
    kendaraan.thnBuat = 2023;
    P = alokasi(kendaraan);
    insertLast(L, P);

    // Menampilkan seluruh kendaraan
    cout << "DATA KENDARAAN AWAL" << endl;
    printInfo(L);

    // Mencari kendaraan D001
    infotype cari;
    cari.nopol = "D001";

    hasil = findElm(L, cari);

    cout << "\nPENCARIAN KENDARAAN D001" << endl;

    if (hasil != nullptr) {
        cout << "Nomor Polisi : " << hasil->info.nopol << endl;
        cout << "Warna        : " << hasil->info.warna << endl;
        cout << "Tahun Buat   : " << hasil->info.thnBuat << endl;
    } else {
        cout << "Kendaraan tidak ditemukan." << endl;
    }

    // Mencari kendaraan D003 untuk dihapus
    P = L.First;
    Prec = nullptr;
    hapus = nullptr;

    while (P != nullptr && P->info.nopol != "D003") {
        Prec = P;
        P = P->next;
    }

    cout << "\nPENGHAPUSAN KENDARAAN D003" << endl;

    if (P == nullptr) {
        cout << "Kendaraan D003 tidak ditemukan." << endl;
    } else {
        if (P == L.First) {
            deleteFirst(L, hapus);
        } else if (P == L.Last) {
            deleteLast(L, hapus);
        } else {
            deleteAfter(Prec, hapus);
        }

        dealokasi(hapus);

        cout << "Kendaraan D003 berhasil dihapus." << endl;
    }

    // Menampilkan list setelah penghapusan
    cout << "\nDATA KENDARAAN SETELAH PENGHAPUSAN" << endl;
    printInfo(L);

    return 0;
}
