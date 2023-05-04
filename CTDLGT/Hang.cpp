#include <bits/stdc++.h>
using namespace std;

struct HANG {
	char maHang[10];
	char tenHang[30];
	float soLuong;
};

struct Node {
	HANG info;
	Node *next;
};

typedef Node *TRO;

HANG nhapHang() {
	HANG x;
	cout << "Nhap ma hang: ";    fflush(stdin);   gets(x.maHang);
	cout << "Nhap ten hang: ";   fflush(stdin);   gets(x.tenHang);
	cout << "Nhap so luong hang: ";    cin >> x.soLuong;
	return x;
}

void nhapDsHang(TRO &L, int &n) {
	TRO P, Q;
	L = NULL;
	cout << "Nhap so luong mat hang n = ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "\nNhap thong tin hang thu " << i + 1 << endl;
		P = new Node;
		P->info = nhapHang();
		P->next = NULL;
		if (L == NULL)
			L = P;
		else 
			Q->next = P;
		Q = P;
	}
}

void xuatHang(HANG x) {
	cout << setw(10) << x.maHang;
	cout << setw(20) << x.tenHang;
	cout << setw(15) << x.soLuong << endl;
}

void xuatDsHang(TRO &L) {
	if (L == NULL) {
		cout << "Danh sach rong!";
		return;
	}
	TRO Q = L;
	int d = 0;
	cout << setw(5) << "STT";
	cout << setw(10) << "Ma hang";
	cout << setw(20) << "Ten hang";
	cout << setw(15) << "So luong" << endl;
	while (Q != NULL) {
		cout << setw(5) << ++d;
		xuatHang(Q->info);
		Q = Q->next;
	}
}

// tim hang co sol lon nhat 
void timHang(TRO &L) {
	if (L == NULL) {
		cout << "Danh sach rong!";
		return;
	}
	TRO Q = L;
	int soLuongMax = 0;
	// tim soLuongMax
	while (Q != NULL) {
		if (Q->info.soLuong > soLuongMax)
			soLuongMax = Q->info.soLuong;
		Q = Q->next;
	}
	Q = L;
	int d = 0;
	// xuat ket qua
	while (Q != NULL) {
		if (Q->info.soLuong == soLuongMax) {
			cout << setw(5) << "STT";
			cout << setw(10) << "Ma hang";
			cout << setw(20) << "Ten hang";
			cout << setw(15) << "So luong" << endl;
			cout << setw(5) << d + 1;
			xuatHang(Q->info);
			break;
		}
		Q = Q->next;
		d++;
	}
}

TRO timViTri(TRO &L, int vt) {
	int d = 1;
	TRO Q = L;
	while (Q->next != NULL && d < vt - 1) {
		Q = Q->next;
		d++;
	}
	return Q;
}

void xoaViTri(TRO &L, int vt) {
	TRO Q, M;
	if (vt == 1) {
		Q = L;
		L = L->next;
		delete(Q);
	} else {
		Q = timViTri(L, vt);
		M = Q->next;
		Q->next = M->next;
	}
	delete(M);
}

void chen(TRO &L, TRO Q, HANG x) {
	TRO P = new Node;
	P->info = x;
	P->next = Q->next;
	Q->next = P;
}

void boSung(TRO &L, int vt) {
	HANG x = nhapHang();
	TRO Q = timViTri(L, vt);
	chen(L, Q, x);
}

int main() {
	TRO L;
	int n;
	nhapDsHang(L, n);
	xuatDsHang(L);
	cout << endl;
	timHang(L);
	xoaViTri(L, 3);
	cout << endl;
	xuatDsHang(L);
	boSung(L, 1);
	cout << endl;
	xuatDsHang(L);
	return 0;
}
/*
3
001
Keo
12
002
Banh
56
003
Mi tom
90
*/


