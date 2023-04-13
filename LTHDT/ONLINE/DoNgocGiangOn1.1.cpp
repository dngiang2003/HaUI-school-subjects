#include <bits/stdc++.h>
using namespace std;

class NhaCC {
	private:
		char MaNCC[10];
		char TenNCC[30];
		char DiaChi[50];
	public:
		void nhap();
		void xuat();
};

void NhaCC::nhap() {
	cout << "\nNhap Ma Nha CC: ";       fflush(stdin);   gets(MaNCC);
	cout << "Nhap Ten Nha CC: ";      fflush(stdin);   gets(TenNCC);
	cout << "Nhap Dia Chi Nha CC: ";  fflush(stdin);   gets(DiaChi);
}

void NhaCC::xuat() {
	cout << setw(15) << "Ma NCC:"  << setw(15) << MaNCC;
	cout << setw(15) << "Ten NCC:" << setw(15) << TenNCC << endl;
	cout << setw(15) << "Dia Chi:" << setw(35) << DiaChi << endl;
}

class Phieu;
class Hang {
	private:
		char TenHang[30];
		float DonGia;
		int SoLuong;
	public:
		void nhap();
		void xuat();
	friend class Phieu;
};

void Hang::nhap() {
	cout << "Nhap Ten Hang: ";  fflush(stdin);  gets(TenHang);
	cout << "Nhap Don Gia: ";     				cin >> DonGia;
	cout << "Nhap So Luong: ";    			    cin >> SoLuong;
}

void Hang::xuat() {
	cout << setw(15) << TenHang;
	cout << setw(15) << DonGia;
	cout << setw(15) << SoLuong;
	cout << setw(15) << DonGia * SoLuong << endl;
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
};

void Phieu::nhap() {
	cout << "Nhap Ma Phieu: ";  fflush(stdin);   gets(MaPhieu);
	cout << "Nhap Ngay Lap: ";  fflush(stdin);   gets(NgayLap);
	x.nhap();
	cout << "\nSo luong mat hang: "; 	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "\nNhap mat hang thu " << i + 1 << endl;
		ds[i].nhap();
	}
}

void Phieu::xuat() {
	// xuat thong tin co ban phieu
	cout << setw(40) << "PHIEU NHAP HANG" << endl;
	cout << setw(15) << "Ma Phieu:" << setw(15) << MaPhieu;
	cout << setw(15) << "Ngay Lap:" << setw(15) << NgayLap << endl;
	// xuat nha cung cap
	x.xuat();
	// xuat tieu de ds hang
	cout << setw(15) << "Ten Hang";
	cout << setw(15) << "Don Gia";
	cout << setw(15) << "So Luong";
	cout << setw(15) << "Thanh Tien" << endl;
	// xuat ds hang + tinh tong tien
	float tongTien = 0;
	for (int i = 0; i < n; i++) {
		ds[i].xuat();
		tongTien += ds[i].DonGia * ds[i].SoLuong;
	}
	// xuat tong tien
	cout << setw(45) << "Cong Thanh Tien";
	cout << setw(15) << tongTien;
}

int main() {
	Phieu a;
	a.nhap();
	a.xuat();
	return 0;
}

/* test case
PH001
1/1/2007
NCC1
LG-Electronic
Khu cong nghe Nhu Quynh A
3
TiVi
30
2
Quat
1.2
3
Mobi
5
10
*/
