#include <bits/stdc++.h>
using namespace std;

class TRUONGDH;
class KHOA {
	private:
		char MaKhoa[10];
		char TenKhoa[30];
		char TruongKhoa[30];
	friend class TRUONGDH;
	friend void bonus1(TRUONGDH &z);
};

class BAN {
	private:
		char MaBan[10];
		char TenBan[30];
		char NgayThanhLap[15];
	friend class TRUONGDH;
};

class TRUONG {
	protected:
		char MaTruong[10];
		char TenTruong[30];
		char DiaChi[30];
	public:
		void nhap();
		void xuat();
};

void TRUONG::nhap() {
	cout << "Nhap Ma Truong: ";   fflush(stdin);   gets(MaTruong);
	cout << "Nhap Ten Truong: ";  fflush(stdin);   gets(TenTruong);
	cout << "Nhap Dia Chi: ";     fflush(stdin);   gets(DiaChi);
}

void TRUONG::xuat() {
	cout << setw(15) << "Ma Truong" 
		 << setw(15) << "Ten Truong"
		 << setw(25) << "Dia Chi" << endl;
		 
	cout << setw(15) << MaTruong 
		 << setw(15) << TenTruong
		 << setw(25) << DiaChi << endl;
}

class TRUONGDH: public TRUONG {
	private:
		KHOA x[69];
		BAN y[69];
		int n, m;
	public:
		void nhap();
		void xuat();
	friend void bonus1(TRUONGDH &z);
};

void TRUONGDH::nhap() {
	TRUONG::nhap();
	cout << "\nSo Khoa n = ";   cin >> n;
	cout << "\nNhap thong tin khoa: \n";
	for (int i = 0; i < n; i++) {
		cout << "\nNhap thong tin khoa thu " << i + 1 << endl;
		cout << "Ma Khoa: ";       fflush(stdin);   gets(x[i].MaKhoa);
		cout << "Ten Khoa: ";      fflush(stdin);   gets(x[i].TenKhoa);
		cout << "Truong Khoa: ";   fflush(stdin);   gets(x[i].TruongKhoa);
	}
	
	cout << "\nSo Ban m = ";    cin >> m;
	cout << "\nNhap thong tin ban: \n";
	for (int i = 0; i < m; i++) {
		cout << "\nNhap thong tin ban thu " << i + 1 << endl;
		cout << "Ma Ban: ";           fflush(stdin);   gets(y[i].MaBan);
		cout << "Ten Ban: ";          fflush(stdin);   gets(y[i].TenBan);
		cout << "Ngay Thanh Lap: ";   fflush(stdin);   gets(y[i].NgayThanhLap);
	}
}

void TRUONGDH::xuat() {
	cout << "\n";
	TRUONG::xuat();
	cout << "\nThong tin ve khoa:\n";
	cout << setw(15) << "Ma khoa" << setw(15) << "Ten khoa"
	     << setw(25) << "Truong khoa" << endl;
	for (int i = 0; i < n; i++)
		cout << setw(15) << x[i].MaKhoa
			 << setw(15) << x[i].TenKhoa
			 << setw(25) << x[i].TruongKhoa << endl;

	cout << "\nThong tin ve ban:\n";
	cout << setw(15) << "Ma ban" << setw(15) << "Ten ban"
	     << setw(25) << "Ngay thanh lap" << endl;
	for (int i = 0; i < m; i++)
		cout << setw(15) << y[i].MaBan
			 << setw(15) << y[i].TenBan
			 << setw(25) << y[i].NgayThanhLap << endl;
}

void bonus1(TRUONGDH &z) {
	bool flag = false;
	for (int i = 0; i < z.n; i++) {
		if (strcmp(z.x[i].MaKhoa, "KH01") == 0) {
			// xoa khoa
			for (int j = i; j < z.n; j++) {
				z.x[j] = z.x[j + 1];
			}	
			flag = true; 
			z.n--;
		}
	}
	if (flag)
		cout << "\n1. Xoa thanh cong khoa co ma KH01!\nDS moi la: \n";
	else
		cout << "\n1. Khong tim thay khoa nao co ma KH01!\nDS khong doi\n";
}

int main() {
	TRUONGDH z;
	z.nhap();
	z.xuat();
	bonus1(z);
	z.xuat();
	return 0;
}
/* TEST CASE
HAUI
DHCNHN
NAM TU LIEM, HA NOI
3
KH01
CNTT
GIANG
KH02
QTKD
PHUONG
KH03
DULICH
CHUYEN
2
BAN1
QUANLY
31/01/2003
BAN2
GIANGVIEN
31/09/2003
*/
