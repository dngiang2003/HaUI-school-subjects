#include <bits/stdc++.h>
using namespace std;

struct SINHVIEN {
	char maSv[10];
	char hoTen[30];
	float diem;
};

struct Node {
	SINHVIEN info;
	Node *next;
};

typedef Node *TRO;

SINHVIEN nhapSv() {
	SINHVIEN sv;
	cout << "Nhap ma: ";       fflush(stdin);   gets(sv.maSv);
	cout << "Nhap ho ten: ";   fflush(stdin);   gets(sv.hoTen);
	cout << "Nhap diem: ";     cin >> sv.diem;
	return sv;
}

void xuatSv(SINHVIEN sv) {
	cout << setw(10) << sv.maSv;
	cout << setw(15) << sv.hoTen;
	cout << setw(10) << sv.diem << endl;
}

void nhapDsSv(TRO &L, int &n) {
	TRO P, Q;
	L = NULL;
	cout << "Nhap so sinh vien: ";   cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "\nNhap thong tin sinh vien thu " <<  i + 1 << endl;
		P = new Node;
		P->info = nhapSv();
		P->next = NULL;
		if (L == NULL) {
			L = P;
		} else {
			Q->next = P;
		}
		Q = P;
	}	
}

TRO timViTri(TRO L, int vt) {
	int count = 1;
	TRO Q;
	while (Q->next != NULL && count < vt - 1) {
		Q = Q->next;
		count += 1;
	}
	return Q;
}

void chen(TRO &L, TRO Q, SINHVIEN x) {
	TRO P;
	P = new Node;
	P->info = x;
	P->next = Q->next;
	Q->next = P;
}



void chenBatKy(TRO &L) {
	int vt;
	TRO Q;
	SINHVIEN x = nhapSv();
	cout << "Vi tri can chen: ";   cin >> vt;
	
}

void xuatDsSv(TRO &L) {
	// kiem tra danh sach
	if (L == NULL) {
		cout << "Danh sach sinh vien rong!";
		return;
	}
	// truong hop danh sach co sinh vien
	cout << endl;
	cout << setw(5)  << "STT";
	cout << setw(10) << "MaSV";
	cout << setw(15) << "Ho ten";
	cout << setw(10) << "Diem" << endl;
	TRO Q = L;
	int i = 0;
	while (Q != NULL) {
		SINHVIEN x = Q->info;
		cout << setw(5)  << i + 1;
		cout << setw(10) << x.maSv;
		cout << setw(15) << x.hoTen;
		cout << setw(10) << x.diem << endl;
		Q = Q->next;
		i += 1;
	}
}

int main() {
	TRO L;
	int n;
	nhapDsSv(L, n);
	xuatDsSv(L);
	return 0;
}

