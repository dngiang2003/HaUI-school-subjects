#include <bits/stdc++.h>

using namespace std;

class HINH {
	protected:
		char Mausac[30];
		char Vien[30];
	public:
		void nhap();
		void xuat();
		HINH(char *ms, char *vi);
};

void HINH::nhap() {
	cout << "Mau sac = "; fflush(stdin); gets(Mausac);
	cout << "Vien = ";    fflush(stdin); gets(Vien);
}

void HINH::xuat() {
	cout << setw(15) << Mausac
	<< setw(15) << Vien;
}

HINH::HINH(char *ms, char *vi) {
	strcpy(Mausac, ms);
	strcpy(Vien, vi);
}

class HCN: public HINH {
	private:
		float D, R;
	public:
		void nhap();
		void xuat();
		HCN(char *ms, char *vi, float x, float y);
};

void HCN::nhap() {
	cout << "Nhap chieu dai = ";   cin >> D;
	cout << "Nhap chieu rong = ";  cin >> R;
}

void HCN::xuat() {
	HINH::xuat();
	cout << endl;
	cout << "Dai = " << D << endl;
	cout << "Rong = " << R << endl;
}

HCN::HCN(char *ms, char *vi, float x, float y):HINH(ms, vi) {
	D = x;
	R = y;
}

int main() {
	HCN a("XANH", "dot", 20, 30);
	a.xuat();
	return 0;
}
