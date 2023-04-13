#include <bits/stdc++.h>
using namespace std;

class BENHNHAN;
class NGUOI {
	protected:
		char HoTen[30];
		int Tuoi;
	public:
		void nhap();
		void xuat();
	friend void bonus1(BENHNHAN a[], int n);
	friend void bonus2(BENHNHAN a[], int n);
};

void NGUOI::nhap() {
	cout << "Ho ten: ";    fflush(stdin);   gets(HoTen);
	cout << "Nhap tuoi: ";                  cin >> Tuoi;
}

void NGUOI::xuat() {
	cout << "Ho ten la: " << HoTen << endl;
	cout << "Tuoi la: " << Tuoi << endl;
}

class BENHVIEN {
	private:
		char TenBenhVien[30];
		char DiaChi[30];
		NGUOI GiamDoc;
	public:
		friend class BENHNHAN;
};

class BENHNHAN: public NGUOI {
	private:
		char MaBN[10];
		char TienSu[30];
		char ChuanDoan[30];
		BENHVIEN x;
	public:
		void nhap();
		void xuat();
	friend void bonus2(BENHNHAN a[], int n);
};

void BENHNHAN::nhap() {
	cout << "Nhap ma benh nhan: ";   fflush(stdin);   gets(MaBN);
	NGUOI::nhap();
	cout << "Nhap tien su: ";        fflush(stdin);   gets(TienSu);
	cout << "Nhap chuan doan: ";     fflush(stdin);   gets(ChuanDoan);
	cout << "Nhap ten benh vien: ";  fflush(stdin);   gets(x.TenBenhVien);
	cout << "Nhap DC benh vien: ";   fflush(stdin);   gets(x.DiaChi);
	cout << "Nhap thong tin giam doc: \n";
	x.GiamDoc.nhap();
}

void BENHNHAN::xuat(){
		cout << "Ma benh nhan: " << MaBN << endl;
		NGUOI::xuat();
		cout << "Tien su benh: " << TienSu << endl;
		cout << "Chuan doan benh: "  << ChuanDoan << endl;
		cout << "Ten benh vien: " << x.TenBenhVien <<endl;
		cout << "Dia chi: " << x.DiaChi << endl ;
		cout << "Giam doc: " << endl;
		x.GiamDoc.xuat();
}

void bonus1(BENHNHAN a[], int n) {	
	// co bao nhieu benh nhan lon hon 30 tuoi
	int count = 0;
	for (int i = 0; i < n; i++)
		if (a[i].Tuoi > 30)
			count += 1;
	cout << "\n1. DS co " << count << " benh nhan lon hon 30 tuoi!\n";
}

void bonus2(BENHNHAN a[], int n) {
	// sua Tuoi cua bn co ma "BN01" thanh 20 neu co
	int count = 0;
	for (int i = 0; i < n; i++)
		if (strcmp(a[i].MaBN, "BN01") == 0) {
			count += 1;
			a[i].Tuoi = 20;
		}
	if (count) {
		cout << "\n2. Sua thanh cong tuoi cua " << count << " benh nhan!\n";
		cout << "DS sau khi sua la: \n";
	} else {
		cout << "\n2. Khong co benh nhan nao!\n";
		cout << "DS duoc giu nguyen la: \n";
	}
}

int main() {
	BENHNHAN a[69];
	int n;
	cout << "Nhap so luong benh nhan n = ";
	cin >> n;
	// nhap benh nhan
	for (int i = 0; i < n; i++) {
		cout << "\nNhap thong tin benh nhan thu " << i + 1 << endl;
		a[i].nhap();
	}
	// xuat benh nhan
	for (int i = 0; i < n; i++) {
		cout << "\nThong benh nhan thu " << i + 1 << endl;
		a[i].xuat();
	}
	bonus1(a, n);
	bonus2(a, n);
	// xuat benh nhan sau khi sua
	for (int i = 0; i < n; i++) {
		cout << "\nThong benh nhan thu " << i + 1 << endl;
		a[i].xuat();
	}
	return 0;
}
