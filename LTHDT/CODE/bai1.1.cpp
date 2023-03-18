#include <bits/stdc++.h>
using namespace std;

class SINHVIEN {
	private:
		char MaSV[10];
		char HoTen[30];
		int Tuoi;
		float Diem;
	public:
		void nhap();
		void xuat();
};

void SINHVIEN::nhap() {
	cout << "Nhap MaSV = ";			fflush(stdin); gets(MaSV);
	cout << "Nhap Ho va Ten = ";	fflush(stdin); gets(HoTen);
	cout << "Nhap Tuoi = "; 					cin >> Tuoi;
	cout << "Nhap Diem = ";						cin >> Diem;
}

void SINHVIEN::xuat() {
	cout << setw(15) << left << "MaSV: " << setw(15) << left << MaSV << endl;
	cout << setw(15) << left << "Ho va Ten: " << setw(15) << left << HoTen << endl;
	cout << setw(15) << left << "Tuoi: " << setw(15) << left << Tuoi << endl;
	cout << setw(15) << left << "Diem: " << setw(15) << left << Diem;
}


int main() {
	SINHVIEN a, b;
	a.nhap();
	b.nhap();
	a.xuat();
	cout << endl;
	b.xuat();
	return 0;
}
