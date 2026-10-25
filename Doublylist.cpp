#include "Doublylist.h"

void CreateList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

void printInfo(List L) {
    address P = L.First;

    if (P == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    while (P != nullptr) {
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun Buat   : " << P->info.thnBuat << endl;
        cout << "------------------------" << endl;

        P = P->next;
    }
}

void insertLast(List &L, address P) {
    if (P == nullptr) {
        return;
    }

    P->next = nullptr;
    P->prev = nullptr;

    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}


address findElm(List L, infotype x) {
    address P = L.First;

    while (P != nullptr) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }

    return nullptr;
}

void deleteFirst(List &L, address &P) {
    P = L.First;

    if (P == nullptr) {
        return;
    }

    if (L.First == L.Last) {
        L.First = nullptr;
        L.Last = nullptr;
    } else {
        L.First = P->next;
        L.First->prev = nullptr;
    }

    P->next = nullptr;
    P->prev = nullptr;
}

void deleteLast(List &L, address &P) {
    P = L.Last;

    if (P == nullptr) {
        return;
    }

    if (L.First == L.Last) {
        L.First = nullptr;
        L.Last = nullptr;
    } else {
        L.Last = P->prev;
        L.Last->next = nullptr;
    }

    P->next = nullptr;
    P->prev = nullptr;
}

void deleteAfter(address Prec, address &P) {
    if (Prec == nullptr || Prec->next == nullptr) {
        P = nullptr;
        return;
    }

    P = Prec->next;
    Prec->next = P->next;

    if (P->next != nullptr) {
        P->next->prev = Prec;
    }

    P->next = nullptr;
    P->prev = nullptr;
}
