#include <bits/stdc++.h>
using namespace std;

class NhaCC {
	private:
		char MaNCC[10];
		char TenNCC[30];
		char DiaChi[30];
		char SDT[10];
	public:
		void nhap();
		void xuat();
};

void NhaCC::nhap() {
	cout << "\nNhap MaNCC: ";    fflush(stdin);   gets(MaNCC);
	cout << "Nhap TenNCC: ";   fflush(stdin);   gets(TenNCC);
	cout << "Nhap Dia Chi: ";  fflush(stdin);   gets(DiaChi);
	cout << "Nhap SDT: ";      fflush(stdin);   gets(SDT);
}

void NhaCC::xuat() {
	cout << setw(20) << "Ma nha cung cap:" << setw(20) << MaNCC;
	cout << setw(20) << "Ten nha cung cap:" << setw(20) << TenNCC << endl;
	cout << setw(20) << "Dia chi:" << setw(20) << DiaChi;
	cout << setw(20) << "SDT:" << setw(20) << SDT << endl;
}

class Phieu;
class Hang {
	private:
		char MaSp[10];
		char TenSp[30];
		int SoLuong;
		float DonGia;
	public:
		void nhap();
		void xuat();
	friend class Phieu;
	friend void bonus1(Phieu a);
	friend void bonus2(Phieu &a);
};

void Hang::nhap() {
	cout << "Nhap Ma San Pham: ";   fflush(stdin);   gets(MaSp);
	cout << "Nhap Ten San Pham: ";  fflush(stdin);   gets(TenSp);
	cout << "Nhap So Luong: "; 						 cin >> SoLuong;
	cout << "Nhap Don Gia: ";      			         cin >> DonGia;
}

void Hang::xuat() {
	cout << setw(15) << MaSp;
	cout << setw(15) << TenSp;
	cout << setw(15) << SoLuong;
	cout << setw(15) << DonGia;
	cout << setw(15) << SoLuong * DonGia << endl;
}

class Phieu {
	private:
		char MaPhieu[10];
		char NgayLap[15];
		NhaCC x;
		Hang ds[88];
		int n;
	public:
		void nhap();
		void xuat();
	friend void bonus1(Phieu a);
	friend void bonus2(Phieu &a);
};

void Phieu::nhap() {
	// nhap thong tin co ban Phieu
	cout << "Nhap Ma Phieu: ";   fflush(stdin);    gets(MaPhieu);
	cout << "Nhap Ngay Lap: ";   fflush(stdin);    gets(NgayLap);
	// nhap thong tin NhaCC
	x.nhap();
	// nhap so luong hang
	cout << "\nNhap So Luong San Pham N = ";       cin >> n;
	// nhap ds hang
	for (int i = 0; i < n; i++) {
		cout << "\nNhap Mat Hang Thu " << i + 1 << endl;
		ds[i].nhap();
	}
}

void Phieu::xuat() {
	// xuat thong tin co ban phieu
	cout << "Dai hoc Victory\n";
	cout << setw(55) << "PHIEU VAN PHONG PHAM\n";
	cout << setw(20) << "Ma phieu:" << setw(20) << MaPhieu;
	cout << setw(20) << "Ngay lap:" << setw(20) << NgayLap << endl;
	// xuat thong tin nhacc
	x.xuat();
	// xuat tieu de danh sach sp
	cout << setw(15) << "Ma Sp";
	cout << setw(15) << "Ten san pham";
	cout << setw(15) << "So luong";
	cout << setw(15) << "Don gia";
	cout << setw(15) << "Thanh tien" << endl;
	// xuat da sach sp + tinh tong tien;
	float tongTien = 0;
	for (int i = 0; i < n; i++) {
		ds[i].xuat();
		tongTien += ds[i].SoLuong * ds[i].DonGia;
	}
	cout << setw(45) << "TONG" << setw(30) << tongTien << endl;
	cout << setw(25) << "Hieu truong" << setw(25) 
	<< "Phong tai chinh" << setw(25) << "Nguoi lap";
}

void bonus1(Phieu a) {
	// phieu co bao nhieu sp co sl < 80
	int dem = 0;
	for (int i = 0; i < a.n; i++)
		if (a.ds[i].SoLuong < 80)
			dem++;
	cout << "\n\n1. Phieu co " << dem << " san pham co so luong < 80!";	
}

void bonus2(Phieu &a) {
	// sap xep sp theo chieu tang dan cua don gia
	Hang temp;
	for (int i = 0; i < a.n - 1; i++)
		for (int j = i + 1; j < a.n; j++)
			if (a.ds[i].DonGia > a.ds[j].DonGia) {
				temp = a.ds[i];
				a.ds[i] = a.ds[j];
				a.ds[j] = temp;
			}
	cout << "\n\n2. Sap xep san pham thanh cong!\n";
	cout << "Phieu sau khi sap xep la: \n\n";
}

int main() {
	Phieu a;
	a.nhap();
	a.xuat();
	bonus1(a);
	bonus2(a);
	a.xuat();
	return 0;
}
/* test case
PH001
4/6/2018
NCC01
Cong ty Van Phu
Quan Ha Dong, Ha Noi
091212xxxx
3
SP01
Giay in A4
100
70
SP02
But da bang
50
10
SP03
Tui clear
60
5
*/
