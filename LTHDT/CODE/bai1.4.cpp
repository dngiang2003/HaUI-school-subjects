#include <bits/stdc++.h>

using namespace std;

class SACH {
	private:
		char MaSach[10];
		char TenSach[30];
		char NhaXuatBan[30];
		int SoTrang;
		float GiaTien;
	public:
		void nhap();
		void xuat();
};

void SACH::nhap() {
	cout << "Nhap Ma Sach: "; 		fflush(stdin); gets(MaSach);
	cout << "Nhap Ten Sach: "; 		fflush(stdin); gets(TenSach);
	cout << "Nhap Nha Xuat Ban: ";  fflush(stdin); gets(NhaXuatBan);
	cout << "Nhap So Trang: ";       cin >> SoTrang;
	cout << "Nhap Gia Tien: ";       cin >> GiaTien;
}

void SACH::xuat() {
	cout << setw(15) << MaSach << setw(15) << TenSach << setw(15) 
	<< NhaXuatBan << setw(15) << SoTrang << setw(15) << GiaTien << endl;
}

int main() {
	int n;
	cout << "Nhap so luong cuon sach N = "; cin >> n;
	SACH *s = new SACH[n];
	for (int i = 0; i < n; i++) {
		cout << "Nhap cuon sach thu " << i + 1 << endl;
		s[i].nhap();
	}
	cout << "==========================Bang ket qua=======================" << endl;
	cout << setw(15) << "Ma Sach" << setw(15) << "TenSach" << setw(15) 
	<< "NhaXuatBan" << setw(15) << "SoTrang" << setw(15) << "GiaTien" << endl;
	for (int i = 0; i < n; i++) {
		s[i].xuat();
	}
	return 0;
}
