#include <bits/stdc++.h>

using namespace std;

class HCN{
	private:
		float D, R;
	public:
		void nhap();
		void ve();
		float dienTich();
		// khoi tao du lieu
		HCN();
		HCN(float a, float b);
		~HCN();
};

HCN::~HCN() {
	cout << endl << "Phuong thuc huy da duoc goi!";
}

HCN::HCN() {
	D = 10;
	R = 9;	
}

HCN::HCN(float a, float b) {
	D = a;
	R = b;
}

void HCN::nhap() {
	cout << "Nhap chieu Dai = ";  cin >> D;
	cout << "Nhap chieu Rong = "; cin >> R;
}

void HCN::ve() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < D; j++) {
			cout << "*";
		}
		cout << "\n";
	}
}

float HCN::dienTich() {
	return D * R; 
}

int main() {
	HCN a(4, 8);
//	a.nhap();
	cout << endl;
	a.ve();
	cout << endl << "Dien tich = " << a.dienTich();
	return 0;
}

