#include <bits/stdc++.h>
using namespace std;

class NhaCC {
	private:
		char maNCC[10];
		char tenNCC[20];
		char diaChi[30];
	public:
		void nhap();
		void xuat();
};

void NhaCC::nhap() {
	cout << "Nhap maNCC: ";     fflush(stdin);    gets(maNCC);
	cout << "Nhap tenNCC: ";    fflush(stdin);    gets(tenNCC);
	cout << "Nhap dia chi: ";   fflush(stdin);    gets(diaChi);
}

void NhaCC::xuat() {
	cout << setw(15) << "MaNCC: " << setw(15) << maNCC;
	cout << setw(15) << "TenNCC: " << setw(15) << tenNCC << endl;
	cout << setw(15) << "Dia chi: " << setw(20) << diaChi << endl;
}

class PHIEU;
class HANG {
	private:
		char maHang[10];
		char tenHang[20];
		float donGia;
		int soLuong;
	public:
		void nhap();
		void xuat();
		friend class PHIEU;
		friend void sapXepHang(PHIEU &a);
};

void HANG::nhap() {
	cout << "Nhap maHang: ";    fflush(stdin);    gets(maHang);
	cout << "Nhap tenHang: ";   fflush(stdin);    gets(tenHang);
	cout << "Nhap donGia: ";    cin >> donGia;
	cout << "Nhap so luong: ";  cin >> soLuong;
}

void HANG::xuat() {
	cout << setw(10) << maHang;
	cout << setw(20) << tenHang;
	cout << setw(15) << donGia;
	cout << setw(15) << soLuong;
	cout << setw(20) << donGia * soLuong << endl;
}

class PHIEU {
	private:
		char maPhieu[10];
		char ngayLap[15];
		NhaCC x;
		HANG ds[100];
		int n;
	public:
		void nhap();
		void xuat();
		friend void sapXepHang(PHIEU &a);
		friend void chenHang(PHIEU &a);
		friend void xoaHang(PHIEU &a);
};

void PHIEU::nhap() {
	cout << "Nhap maPhieu: ";    fflush(stdin);   gets(maPhieu);
	cout << "Nhap ngayLap: ";    fflush(stdin);   gets(ngayLap);
	cout << endl;
	x.nhap();
	cout << "\nNhap so luong hang n = ";          cin >> n;
	for (int i = 0; i < n; i ++) {
		cout << "\nNhap mat hang thu " << i + 1 << endl;
		ds[i].nhap();
	}
}

void PHIEU::xuat() {
	cout << setw(15) << "Ma phieu: " << setw(15) << maPhieu;
	cout << setw(15) << "Ngay lap: " << setw(15) << ngayLap << endl;
	x.xuat();
	cout << setw(10) << "Ma hang";
	cout << setw(20) << "Ten hang";
	cout << setw(15) << "Don gia";
	cout << setw(15) << "So luong";
	cout << setw(20) << "Thanh tien" << endl;
	for (int i = 0; i < n; i++)
		ds[i].xuat();
}

void sapXepHang(PHIEU &a) {
	HANG temp;
	for (int i = 0; i < a.n - 1; i++) {
		for (int j = i + 1; j < a.n; j++) {
			if (a.ds[i].soLuong * a.ds[i].donGia > a.ds[j].soLuong * a.ds[j].donGia) {
				temp = a.ds[i];
				a.ds[i] = a.ds[j];
				a.ds[j] = temp;
			}
		}
	}
}

void chenHang(PHIEU &a) {
	int k;
	cout << "\n3. Nhap vi tri can chen k = ";   cin >> k;
	if (k <= 0 || k > a.n) {
		cout << "Vi tri khong chinh xac!";
		return;
	}
	HANG h;
	cout << "\nNhap thong tin hang can chen: \n";
	h.nhap();
	for (int i = a.n - 1; i >= k - 1; i--) {
		a.ds[i + 1] = a.ds[i]; 
	}
	a.ds[k - 1] = h;
	a.n += 1;
	cout << "\nPhieu sau khi chen la: \n";
	a.xuat();
}

void xoaHang(PHIEU &a) {
	int k;
	cout << "\n4. Nhap vi tri can xoa k = ";   cin >> k;
	if (k <= 0 || k > a.n) {
		cout << "Vi tri khong chinh xac!";
		return;
	}
	for (int i = k - 1; i < a.n; i++)
		a.ds[i] = a.ds[i + 1];
	a.n -= 1;
	cout << "\nPhieu sau khi xoa la: \n";
	a.xuat();
}

int main() {
	PHIEU a;
	a.nhap();
	cout << "\n1. Phieu sau khi nhap: \n";
	a.xuat();
	sapXepHang(a);
	cout << "\n2. Phieu sau khi sap xep theo thanh tien: \n";
	a.xuat();
	chenHang(a);
	xoaHang(a);
	return 0;
}


/*
P0001
12/5/2023
NCC005
Thu Phuong
Viet Nam
5
H001
Keo
2000
100
H002
Banh
5000
50
H003
Bot
8000
55
H004
Mi
3500
100
H005
Kem
6500
20
*/











