#include <bits/stdc++.h>

using namespace std;

class HANGHOA {
	private:
		char MaHang[10];
		char TenHang[30];
		float DonGia;
		int SoLuong;
	public:
		void nhap();
		void xuat();
		float thanhTien();
};

void HANGHOA::nhap() {
	cout << "Nhap Ma Hang: ";		fflush(stdin); gets(MaHang);
	cout << "Nhap Ten Hang: ";		fflush(stdin); gets(TenHang);
	cout << "Nhap Don Gia: ";					   cin >> DonGia;
	cout << "Nhap So Luong: ";					   cin >> SoLuong;
}

void HANGHOA::xuat() {
	cout << setw(15) << MaHang << setw(15) << TenHang <<
			setw(15) << DonGia << setw(15) << SoLuong <<
			setw(15) << thanhTien() << endl;	
}

float HANGHOA::thanhTien() {
	return DonGia * SoLuong;
}

int main() {
	int n;
	cout << "Nhap so luong mat hang N = "; cin >> n;
	HANGHOA *ds = new HANGHOA[n];
	for (int i = 0; i < n; i++) {
		cout << "Nhap mat hang thu " << i + 1 << endl;
		ds[i].nhap();
	}
	cout << "=============================================" << endl;
	cout << setw(15) << "Ma Hang" << setw(15) << "Ten Hang" <<
			setw(15) << "Don Gia" << setw(15) << "So Luong" <<
			setw(15) << "Thanh Tien" << endl;
	for (int i = 0; i < n; i++) {
		ds[i].xuat();
	}
	cout << "=============================================";
	return 0;
}

