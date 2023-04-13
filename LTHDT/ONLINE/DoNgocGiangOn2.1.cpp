#include <bits/stdc++.h>
using namespace std;

class HANG;
class NSX {
	private:
		char TenNSX[30];
		char DiaChi[30];
	public:
		void nhap();
		void xuat();
	friend class HANG;
};

void NSX::nhap() {
	cout << "Nhap TenNSX: ";  fflush(stdin);   gets(TenNSX);
	cout << "Dia Chi: ";      fflush(stdin);   gets(DiaChi);
}

void NSX::xuat() {
	cout << "TenNSX: " << TenNSX << endl;
	cout << "Dia Chi: " << DiaChi << endl;
}

class TIVI;
class DATE {
	private:
		int d, m, y;
	public:
		void nhap();
		void xuat();
	friend class TIVI;
};

void DATE::nhap() {
	cout << "Nhap Ngay: ";     cin >> d;
	cout << "Nhap Thang: ";    cin >> m;
	cout << "Nhap Nam: ";      cin >> y;
}

void DATE::xuat() {
	cout << "Ngay nhap: " << d << "/" << m << "/" << y << endl;
}

class HANG {
	protected:
		char TenHang[30];
		NSX x;
		int DonGia;
	public:
		void nhap();
		void xuat();
		HANG();
};

void HANG::nhap() {
	cout << "Nhap Ten Hang: ";  fflush(stdin);   gets(TenHang);
	x.nhap();
	cout << "Nhap Don Gia: ";                    cin >> DonGia;
}

void HANG::xuat() {
	cout << "Ten Hang: " << TenHang << endl;
	x.xuat();
	cout << "Don Gia: " << DonGia << endl;
}

HANG::HANG() {
	strcpy(TenHang, "Keo Mut");
	strcpy(x.TenNSX, "Chupa Chups");
	strcpy(x.DiaChi, "Viet Nam");
	DonGia = 2000;
}

class TIVI: public HANG {
	private:
		float KichThuoc;
		DATE NgayNhap;
	public:
		void nhap();
		void xuat();
		TIVI();
};

void TIVI::nhap() {
	HANG::nhap();
	cout << "Nhap Kich Thuoc: ";   cin >> KichThuoc;
	NgayNhap.nhap();
}

void TIVI::xuat() {
	cout << "\nThong tin san pham vua nhap:\n\n";
	HANG::xuat();
	cout << "Kich Thuoc: " << KichThuoc << endl;
	NgayNhap.xuat();
}

TIVI::TIVI() {
	HANG();
	KichThuoc = 55.5;
	NgayNhap.d = 12;
	NgayNhap.m = 5;
	NgayNhap.y = 2023;
}

int main() {
	TIVI z;
	z.nhap();
	z.xuat();
	return 0;
}

/* test case
TIVI XIAOMI EA75 2022 SERIES
XIAOMI
VIET NAM
14500000
55
12
5
2023
*/
