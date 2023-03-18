#include <bits/stdc++.h>

using namespace std;

class NHANVIEN {
	private:
		char HOTEN[30];
		char CHUCVU[50];
	public:
		void nhap();
		void xuat();
};

void NHANVIEN::nhap() {
	cout << "HO TEN: "; cin.getline(HOTEN, 30);
	cout << "CHUC VU: "; cin.getline(CHUCVU, 50);
}

void NHANVIEN::xuat() {
	cout << setw(15) << "Nhan vien: " << setw(15) << HOTEN
	<< setw(15) << "Chuc vu: " << setw(15) << CHUCVU << endl;
}

// lop phong
class PHONG {
	char MAPH[10];
	char TENPH[30];
	char TENTP[30];
public:
	void nhap();
	void xuat();
};

void PHONG::nhap() {
	cout << "Ma phong: "; cin.getline(MAPH, 10);
	cout << "Ten phong: "; cin.getline(TENPH, 30);
	cout << "Truong phong: "; cin.getline(TENPH, 30);
}

void PHONG::xuat() {
	cout << setw(15) << "Ten phong: " << setw(15) << TENPH
	<< setw(15) << "Ma phong: " << setw(15) << MAPH << endl;
	cout << setw(15) << "Truong phong: " << setw(15) << TENTP << endl;
}

// lops tai san
class TAISAN {
	char TENTS[10];
	int SL;
	char TINHTRANG[50];
public:
	void nhap();
	void xuat();
	friend class PHIEU;
};

void TAISAN::nhap() {
	cout << "Ten tai san: "; fflush(stdin); cin.getline(TENTS, 30);
	cout << "So luong: "; cin >> SL;
	cout << "Tinh trang: "; fflush(stdin); cin.getline(TINHTRANG, 50);
}

void TAISAN::xuat() {
	cout << setw(15) << TENTS << setw(15) << SL
	<< setw(15) << TINHTRANG << setw(15) << endl;
}

class PHIEU {
	char MAPH[10];
	char NGAY[12];
	NHANVIEN X;
	PHONG Y;
	TAISAN* Z;
	int n;
public:
	void nhap();
	void xuat();
};

void PHIEU::nhap() {
	cout << "MA PHIEU: "; cin.getline(MAPH, 10);
	cout << "NGAY: "": "; cin.getline(NGAY, 12);
	X.nhap();
	Y.nhap();
	cout << "Nhap so tai san N = "; cin >> n;
	Z = new TAISAN[n];
	for (int i=0; i<n; i++) {
		Z[i].nhap();
	}
}

void PHIEU::xuat() {
	cout << setw(40) << "PHIEU KIEM KE TAI SAN" << endl;
	cout << setw(15) << "Ma phieu: " << setw(15) << MAPH;
	cout << setw(15) << "Ngay lap: " << setw(15) << NGAY << endl;
	X.xuat();
	Y.xuat();
	cout << setw(15) << "Ten tai san" << setw(15) << "So luong" << setw(15) << "Tinh trang" << endl;
	for (int i=0; i<n; i++)
		Z[i].xuat();
	int T = 0;
	for (int i=0; i<n; i++) {
		T += Z[i].SL;
	}
	cout << setw(15) << "So tai san: " << n << setw(15) << "Tong so luong: " << T <<  endl;
	
}

int main() {
	PHIEU K;
	K.nhap();
	K.xuat();
	return 0;
}

