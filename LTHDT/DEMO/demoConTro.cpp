#include <bits/stdc++.h>

using namespace std;

class HCN{
	private:
		float D, R;
	public:
		void nhap();
		void ve();
		float dienTich();
};

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
	HCN *p new HCN[10];
	p -> nhap();
	cout << endl;
	p -> ve();
	cout << endl << "Dien tich = " << p -> dienTich();
	return 0;
}

