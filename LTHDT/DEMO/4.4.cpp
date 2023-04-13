#include <bits/stdc++.h>
using namespace std;

class ELECTRONIC {
	protected:
		float CongSuat;
		float DienAp;
	ELECTRONIC(float x, float y);
};
ELECTRONIC::ELECTRONIC(float x, float y) {
	CongSuat = x;
	DienAp = y;
}

class MAYGIAT:public ELECTRONIC {
	private:
		float DungTich;
		char Loai[30];
	public:
		void xuat();
	MAYGIAT(float x, float y, float dt, char *loai);
};

void MAYGIAT::xuat() {
	cout << "Cong Xuat: " << CongSuat << endl;
	cout << "Dien Ap: " << DienAp << endl;
	cout << "Dung tich: " << DungTich << endl;
	cout << "Loai: " << Loai << endl << endl;
}

MAYGIAT::MAYGIAT(float x, float y, float dt, char *loai):ELECTRONIC(x, y) {
	DungTich = dt;
	strcpy(Loai, loai);
}

class TULANH:public ELECTRONIC {
	private:
		float DungTich;
		int SoNgan;
	public:
		void xuat();
	TULANH(float x, float y, float dt, int sn);
};

void TULANH::xuat() {
	cout << "Cong Xuat: " << CongSuat << endl;
	cout << "Dien Ap: " << DienAp << endl;
	cout << "Dung tich: " << DungTich << endl;
	cout << "So Ngan: " << SoNgan << endl;
}

TULANH::TULANH(float x, float y, float dt, int sn):ELECTRONIC(x, y) {
	DungTich = dt;
	SoNgan = sn;
}

int main() {
	MAYGIAT a(30, 78, 89, "test");
	TULANH b(200, 763, 982, 12);
	a.xuat();
	b.xuat();
	return 0;
}

