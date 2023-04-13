#include <bits/stdc++.h>
using namespace std;

class SinhVien {
	private:
		char MaSv[10];
		char TenSv[30];
		char Lop[10];
		int Khoa;
	public:
		void nhap();
		void xuat();
};

void SinhVien::nhap() {
	cout << "Nhap Ma SV: ";		fflush(stdin);    gets(MaSv);
	cout << "Nhap Ten SV: ";	fflush(stdin);    gets(TenSv);
	cout << "Nhap Lop SV: ";	fflush(stdin);    gets(Lop);
	cout << "Nhap Khoa: ";						  cin >> Khoa;
}

void SinhVien::xuat() {
	cout << setw(15) << "Ma sinh vien:"  << setw(10) << MaSv;
	cout << setw(20) << "Ten sinh vien:" << setw(15) << TenSv << endl;
	cout << setw(15) << "Lop:"  << setw(10) << Lop;
	cout << setw(20) << "Khoa:" << setw(15) << Khoa << endl;
}

class Phieu;
class MonHoc {
	private:
		char TenMon[30];
		int SoTrinh;
		float Diem;
	public:
		void nhap();
		void xuat();
	friend class Phieu;
	friend void bonus1(Phieu a);
	friend void bonus2(Phieu &a);
};

void MonHoc::nhap() {
	cout << "Nhap Ten Mon: ";	fflush(stdin);   gets(TenMon);
	cout << "Nhap So Trinh: ";	  			     cin >> SoTrinh;
	cout << "Nhap Diem: ";						 cin >> Diem;
}

void MonHoc::xuat() {
	cout << setw(20) << TenMon;
	cout << setw(20) << SoTrinh;
	cout << setw(20) << Diem << endl;
}

class Phieu {
	private:
		SinhVien x;
		MonHoc ds[69];
		int n;
	public:
		void nhap();
		void xuat();
	friend void bonus1(Phieu a);
	friend void bonus2(Phieu &a);
};

void Phieu::nhap() {
	// nhap thong tin sinh vien
	x.nhap();
	//
	cout << "\nNhap so mon hoc N = "; cin >> n;
	// nhap thong tin mon hoc
	for (int i = 0; i < n; i++) {
		cout << "\nNhap mon hoc thu " << i + 1 << endl;
		ds[i].nhap();
	}
}

void Phieu::xuat() {
	cout << setw(40) << "PHIEU BAO DIEM" << endl;
	// xuat thong bao sinh vien
	x.xuat();
	cout << "Bang diem:\n";
	cout << setw(20) << "Ten Mon";
	cout << setw(20) << "So Trinh";
	cout << setw(20) << "Diem" << endl;
	// xuat thong tin mon hoc + tinh tong diem, tong trinh
	float tongDiem = 0;
	int tongTrinh = 0;
	for (int i = 0; i < n; i++) {
		ds[i].xuat();
		tongDiem += ds[i].SoTrinh * ds[i].Diem;
		tongTrinh += ds[i].SoTrinh;
	}
	// xuat diem trung binh = tongdiem / tong trinh
	cout << setw(40) << "Diem trung binh";
	cout << setw(20) << round((tongDiem / tongTrinh) * 100) / 100;
}

void bonus1(Phieu a) {
	int dem = 0;
	// mang luu Chi So mon neu thoa man
	int dsCS[69]; 
	// kiem tra co bao nhiem mon thoa man
	for (int i = 0; i < a.n; i++)
		if (a.ds[i].SoTrinh > 3)
			dsCS[dem++] = i;
	// xuat thong bao
	if (dem) {
		cout << "\n\nCo " << dem << " mon co so trinh > 3 do la: \n";
		for (int j = 0; j < dem; j++)
			cout << j + 1 << ". " << a.ds[dsCS[j]].TenMon << endl;
	} else {
		cout << "\n\nKhong co mon hoc nao co so trinh > 3!";
	}
	// cach nay giam so lan lap, kiem tra dieu kien trong truong hop co phan tu thoa man 
	// nhung chua toi uu neu khong co phan tu thoa man!
}

void bonus2(Phieu &a) {
	MonHoc z;
	strcpy(z.TenMon, "HQT SQL Server");
	z.SoTrinh = 3;
	z.Diem = 6;
	a.ds[a.n++] = z;
	cout << "\nPhieu sau khi chen 1 mon!\n";
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
SV001
Nguyen Hai Ha
CNTT1
10
3
Co so du lieu
4
8
Lap trinh HDT
3
7
He dieu hanh
5
9
*/
