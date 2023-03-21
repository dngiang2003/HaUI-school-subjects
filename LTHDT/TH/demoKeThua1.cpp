#include <bits/stdc++.h>

using namespace std;

class PERSON {
	protected:
		char Hoten[30];
		int Tuoi;
		char Diachi[30];
	public:
		void nhap();
		void xuat();
};

void PERSON::nhap() {
	cout << "Nhap ho ten: ";   fflush(stdin);	gets(Hoten);
	cout << "Nhap tuoi = "; 				cin >> Tuoi;
	cout << "Nhap Dia chi: ";  fflush(stdin);    gets(Diachi);
}

void PERSON::xuat() {
	cout << setw(15) << Hoten 
	<< setw(6) << Tuoi << setw(15) << Diachi;
}

class STUDENT: public PERSON {
	private:
		char Lop[10];
		char Nganh[30];
		char Truong[30];
	public:
		void nhap();
		void xuat();
};

void STUDENT::nhap() {
	cout << "Nhap lop: ";      fflush(stdin);  gets(Lop);
	cout << "Nhap nganh: ";    fflush(stdin);  gets(Nganh);
	cout << "Nhap truong: ";   fflush(stdin);  gets(Truong);
	PERSON::nhap();
}

void STUDENT::xuat() {
	cout << setw(10) << Lop << setw(15) << Nganh
	<< setw(15) << Truong;
	cout << endl;
	PERSON::xuat();
}


int main() {
	STUDENT a;
	a.nhap();
	a.xuat();
	return 0;
}

