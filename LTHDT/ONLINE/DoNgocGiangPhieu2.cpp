#include <bits/stdc++.h>
using namespace std;

class NGUOI {
	protected:
		char HoTen[30];
		char NgaySinh[15];
		char QueQuan[30];
	public:
		void nhap();
		void xuat();
};

void NGUOI::nhap() {
	cout << "Nhap vao Ho Ten: ";      fflush(stdin);   gets(HoTen);
	cout << "Nhap vao Ngay Sinh: ";   fflush(stdin);   gets(NgaySinh);
	cout << "Nhap vao Que Quan: ";    fflush(stdin);   gets(QueQuan);
}

void NGUOI::xuat() {
	cout << "Ho va ten: " << HoTen << endl;
	cout << "Ngay sinh: " << NgaySinh << endl;
	cout << "Que quan: "  << QueQuan << endl;
}

class LOPHOC;
class SINHVIEN: public NGUOI {
	private:
		char MaSV[10];
		char Nganh[15];
		int KhoaHoc;
	public:
		void nhap();
		void xuat();
	friend class LOPHOC;
	friend void bonus1(LOPHOC z);
	friend void bonus2(LOPHOC &z);
};

void SINHVIEN::nhap() {
	NGUOI::nhap();
	cout << "Nhap ma sinh vien: ";   fflush(stdin);   gets(MaSV);
	cout << "Nhap nganh: ";          fflush(stdin);   gets(Nganh);
	cout << "Nhap hoa hoc: ";        cin >> KhoaHoc;
}

void SINHVIEN::xuat() {
	NGUOI::xuat();
	cout << "Ma sinh vien: " << MaSV << endl;
	cout << "Nganh: " << Nganh << endl;
	cout << "Khoa hoc: " << KhoaHoc << endl;
}

class LOPHOC {
	private:
		char MaLH[10];
		char TenLH[10];
		char NgayMo[15];
		char GiaoVien[30];
		SINHVIEN a[100];
		int n;
	public:
		void nhap();
		void xuat();
	friend void bonus1(LOPHOC z);
	friend void bonus2(LOPHOC &z);
};

void LOPHOC::nhap() {
	cout << "Nhap ma lop: ";    fflush(stdin);   gets(MaLH);
	cout << "Nhap ten lop: ";   fflush(stdin);   gets(TenLH);
	cout << "Nhap ngay mo: ";   fflush(stdin);   gets(NgayMo);
	cout << "Ten giao vien: ";  fflush(stdin);   gets(GiaoVien);
	cout << "\nNhap so luong sinh vien n = ";
	cin >> n;
	// nhap ds sinh vien
	for (int i = 0; i < n; i++) {
		cout << "\nNhap thong tin sinh vien thu " << i + 1 << endl;
		a[i].nhap();
		cout << endl;
	}
}

void LOPHOC::xuat() {
	cout << "Ma lop: " << MaLH << endl;
	cout << "Ten lop: " << TenLH << endl;
	cout << "Ngay mo: " << NgayMo << endl;
	cout << "Giao vien: " << GiaoVien << endl;
	cout << "\nSo luong sinh vien = " << n << endl;
	// xuat ds sinh vien
	for (int i = 0; i < n; i++) {
		cout << "\nThong tin sinh vien thu " << i + 1 << endl;
		a[i].xuat();
		cout << endl;
	}
}

void bonus1(LOPHOC z) {
	// tim co bn sv khoa 11
	int count = 0;
	for (int i = 0; i < z.n; i++)
		if (z.a[i].KhoaHoc == 11)
			count += 1;
	cout << "\n1. Lop hoc co " << count << " sinh vien khoa 11!\n\n";
}

void bonus2(LOPHOC &z) {
	// sap xep ds sv tang dan khoa hoc
	for (int i = 0; i < z.n - 1; i++)
		for (int j = i + 1; j < z.n; j++)
			if (z.a[i].KhoaHoc > z.a[j].KhoaHoc)
				swap(z.a[i], z.a[j]);
	cout << "\n2. Sap xep thanh cong!\n";
	cout << "Danh sach moi la: \n\n";
}

int main() {
	LOPHOC z;
	z.nhap();
	cout << "\nThong tin lop vua nhap la: \n";
	z.xuat();
	bonus1(z);
	bonus2(z);
	z.xuat();
	return 0;
}
