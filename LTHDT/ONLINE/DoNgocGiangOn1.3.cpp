#include <bits/stdc++.h>
using namespace std;

class NhanVien {
	private:
		char TenNv[30];
		char ChucVu[30];
	public:
		void nhap();
		void xuat();
};

void NhanVien::nhap() {
	cout << endl << "Nhap Ten Nv: ";   fflush(stdin);   gets(TenNv);
	cout << "Nhap Chuc Vu: ";          fflush(stdin);   gets(ChucVu);
}

void NhanVien::xuat() {
	cout << setw(20) << "Nhan vien kiem ke:" << setw(20) << TenNv;
	cout << setw(20) << "Chuc vu:" << setw(20) << ChucVu << endl;
}

class Phong {
	private:
		char TenPhong[30];
		char MaPhong[10];
		char TruongPhong[30];
	public:
		void nhap();
		void xuat();
};

void Phong::nhap() {
	cout << endl << "Nhap ten phong: ";   fflush(stdin);   gets(TenPhong);
	cout << "Nhap ma phong: ";            fflush(stdin);   gets(MaPhong);
	cout << "Nhap truong phong: ";        fflush(stdin);   gets(TruongPhong);
}

void Phong::xuat() {
	cout << setw(20) << "Kiem ke tai phong:" << setw(20) << TenPhong;
	cout << setw(20) << "Ma phong:" << setw(20) << MaPhong << endl;
	cout << setw(20) << "Truong phong:" << setw(20) << TruongPhong << endl;
}
class Phieu;
class TaiSan {
	private:
		char TenTaiSan[30];
		int SoLuong;
		char TinhTrang[30];
	public:
		void nhap();
		void xuat();
	friend class Phieu;
	friend void bonus1(Phieu &a);
	friend void bonus2(Phieu &a);
};

void TaiSan::nhap() {
	cout << "Nhap Ten Tai San: ";   fflush(stdin);   gets(TenTaiSan);
	cout << "Nhap So Luong: ";   					 cin >> SoLuong;
	cout << "Nhap Tinh Trang: ";    fflush(stdin);   gets(TinhTrang);
}

void TaiSan::xuat() {
	cout << setw(20) << TenTaiSan;
	cout << setw(25) << SoLuong;
	cout << setw(25) << TinhTrang << endl;
}

class Phieu {
	private:
		char MaPhieu[10];
		char NgayKiemKe[15];
		NhanVien nv;
		Phong p;
		TaiSan ts[99];
		int n;
	public:
		void nhap();
		void xuat();
	friend void bonus1(Phieu &a);
	friend void bonus2(Phieu &a);
};

void Phieu::nhap() {
	// nhap thong tin co ban phieu
	cout << "Nhap Ma Phieu: ";       fflush(stdin);   gets(MaPhieu);
	cout << "Nhap Ngay Kiem Ke: ";   fflush(stdin);   gets(NgayKiemKe);
	// nhap thong tin Nhan vien
	nv.nhap();
	// nhap thong tin Phong
	p.nhap();
	cout << "\nNhap so loai tai san N = ";    cin >> n;
	// nhap thong tin cac tai san
	for (int i = 0; i < n; i++) {
		cout << "\nNhap thong tin tai san thu " << i + 1 << endl;
		ts[i].nhap();
	}
}

void Phieu::xuat() {
	cout << endl << setw(55) << "PHIEU KIEM KE TAI SAN" << endl;
	// xuat thong tin co ban phieu
	cout << setw(20) << "Ma phieu:" << setw(20) << MaPhieu;
	cout << setw(20) << "Ngay kiem ke:" << setw(20) << NgayKiemKe << endl;
	// xuat thong tin nhan vien
	nv.xuat();
	// xuat thong tin phong
	p.xuat();
	cout << setw(20) << "Ten Tai San";
	cout << setw(25) << "So Luong";
	cout << setw(25) << "Tinh Trang" << endl;
	int tongSL = 0;
	// xuat tai san + tinh tong so luong
	for (int i = 0; i < n; i++) {
		ts[i].xuat();
		tongSL += ts[i].SoLuong;
	}
	cout << "So luong tai san kiem ke: " << n;
	cout << setw(35) << "Tong so luong: " << tongSL;
}

void bonus1(Phieu &a) {
	// sua so luong cua tai san "May vi tinh" thanh 20
	bool flag = false;
	for (int i = 0; i < a.n; i++) {
		if (strcmp(a.ts[i].TenTaiSan, "May vi tinh") == 0) {
			a.ts[i].SoLuong = 20;
			flag = true;
		}
	}
	if (flag)
		cout << "\n\n1. Sua so luong thanh cong!\nPhieu sau khi sua la: \n";
	else
		cout << "\n\n1. Khong co tai san ten la 'May vi tinh'!\nPhieu khong duoc chinh sua: \n";
}

void bonus2(Phieu &a) {
	// sap xep tai san theo so luong tang dan (noi bot)
	TaiSan temp;
	for (int i = 0; i < a.n - 1; i++)
		for (int j = i + 1; j < a.n; j++)
			if (a.ts[i].SoLuong > a.ts[j].SoLuong) {
				temp = a.ts[i];
				a.ts[i] = a.ts[j];
				a.ts[j] = temp;
			}
	cout << "\n\n2. Sap xep thanh cong!\nPhieu sau khi sap xep la:\n";
}
	
int main() {
	Phieu a;
	a.nhap();
	a.xuat();
	bonus1(a);
	a.xuat();
	bonus2(a);
	a.xuat();
	return 0;
}
/* test case
PH01
1/1/2007
Kieu Thi Thanh
Ke toan vien
To chuc hanh chinh
PTC
Hoang Bic Hao
3
May vi tinh
5
Tot
May vi tinh
3
Het khau hao - hong
Ban lam viec
6
Tot
*/
