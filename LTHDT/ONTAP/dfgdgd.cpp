#include <bits/stdc++.h>
using namespace std;
#define MAX 50

struct HANG {
    char maHang[10];
    char tenHang[30];
    char donViTinh[10];
    float donGia;
    int soLuong;
};

struct List {
    int count;
    HANG h[MAX];
};

void khoiTao(List &L) {
    L.count = 0; // gan gia tri 0 cho so phan tu cua danh sach
}

int Full(List L) {
    return L.count == MAX;
}

int Empty(List L){
    return L.count == 0;
}

int Add(List &L, HANG h) {
    if (Full(L)) return 0;
    else {
        L.h[L.count] = h;
        L.count++;
        return 1;
    }
}

void nhapHang(HANG &h) {
    cout << "Nhap ma hang: ";     fflush(stdin);   gets(h.maHang);
    cout << "Nhap ten hang: ";    fflush(stdin);   gets(h.tenHang);
    cout << "Don vi tinh: ";      fflush(stdin);   gets(h.donViTinh);
    cout << "Nhap don gia: ";     cin >> h.donGia;
    cout << "Nhap so luong: ";    cin >> h.soLuong;
}

void nhapDsHang(List &L, int &n) {
    cout << "Nhap so luong hang n = ";
    cin >> n;
    khoiTao(L);
    HANG h;
    for (int i = 0; i < n; i++) {
        cout << "\nNhap mat hang thu " << i + 1 << endl;
        nhapHang(h);
        Add(L, h); // khong can L.count++ o day
    }
}

void xuatDsHang(List &L) {
	cout << setw(5)  << "STT";
	cout << setw(10) << "Ma hang";
	cout << setw(20) << "Ten hang";
	cout << setw(10) << "Don vi";
	cout << setw(15) << "Don gia";
	cout << setw(15) << "So luong" << endl;
	for (int i = 0; i < L.count; i++) {
		cout << setw(5)  << i + 1;
		cout << setw(10) << L.h[i].maHang;
		cout << setw(20) << L.h[i].tenHang;
		cout << setw(10) << L.h[i].donViTinh;
		cout << setw(15) << L.h[i].donGia;
		cout << setw(15) << L.h[i].soLuong << endl;
	}
}

void dsHangSlt10(List &L) {
    bool coHangSlt10 = false;
    cout << "Danh sach mat hang co so luong nho hon 10:" << endl;
    cout << setw(5)  << "STT";
    cout << setw(10) << "Ma hang";
    cout << setw(20) << "Ten hang";
    cout << setw(10) << "Don vi";
    cout << setw(15) << "Don gia";
    cout << setw(15) << "So luong" << endl;

    for (int i = 0; i < L.count; i++) {
        if (L.h[i].soLuong < 10) {
            cout << setw(5)  << i + 1;
            cout << setw(10) << L.h[i].maHang;
            cout << setw(20) << L.h[i].tenHang;
            cout << setw(10) << L.h[i].donViTinh;
            cout << setw(15) << L.h[i].donGia;
            cout << setw(15) << L.h[i].soLuong << endl;
            coHangSlt10 = true;
        }
    }

    if (!coHangSlt10) {
        cout << "Khong co mat hang co so luong nho hon 10." << endl;
    }
}

void giamGiaButChi(List &L) {
    bool coButChi = false;
    for (int i = 0; i < L.count; i++) {
        if (strcmp(L.h[i].tenHang, "but chi") == 0) {
            L.h[i].donGia *= 0.9;
            coButChi = true;
            break;
        }
    }

    if (coButChi) {
        cout << "Da giam gia 10% cho mat hang but chi." << endl;
        cout << "\nDanh sach hang moi la: \n";
    	xuatDsHang(L);
    } else {
        cout << "Khong tim thay mat hang but chi trong danh sach." << endl;
    }
}


void sapXepSltGiam(List &L) {
	HANG temp;
	for (int i = 0; i < L.count - 1; i++) {
		for (int j = i + 1; j < L.count; j++) {
			if (L.h[i].soLuong < L.h[j].soLuong) {
				temp = L.h[i];
				L.h[i] = L.h[j];
				L.h[j] = temp;
			}
		}
	}
}

int main() {
    List L;
    int n;
    nhapDsHang(L, n);
    cout << "\n1. Danh sach hang vua nhap: \n";
    xuatDsHang(L);
    cout << "\n2. Danh sach hang co so luong nho hon 10: \n";
    dsHangSlt10(L);
    cout << "\n3. Kiem tra hang but chi: \n";
    giamGiaButChi(L);
    cout << "\n4. Danh sach sau khi sap xep: \n";
    sapXepSltGiam(L);
    xuatDsHang(L);
    return 0;
}
/*
5
001
Keo
chiec
1200
80
002
Banh
chiec
5000
100
003
Bot
tui
14000
99
004
Mi
goi
3000
100
005
but chi
chiec
5000
100
*/

