#include <bits/stdc++.h>
#define MAX 100
using namespace std;


class MATRAN {
	private:
		int n;
		float ds[MAX];
	public:
		MATRAN();
		~MATRAN();
		MATRAN(int size, int k);
		MATRAN operator/(MATRAN z);
		int operator!();
		friend istream& operator >> (istream& in, MATRAN& x);
		friend ostream& operator << (ostream& out, MATRAN x);
};

MATRAN::MATRAN() {
	n = 1;
	ds[0] = 1;
}

MATRAN::MATRAN(int size, int k) {
	n = size;
	for (int i = 0; i < n; i++)
		ds[i] = k;
}

MATRAN::~MATRAN() {
	cout << endl << "Huy ma tran thanh cong!";
}

int MATRAN::operator!() {
	float tong = 0;
	for (int i = 1; i < n; i++) 
		tong += ds[i];
	return round((tong / n) * 1000) * 1000;
}

MATRAN MATRAN::operator/(MATRAN z) {
	if (n != z.n) {
		MATRAN error(0, 0);
		return error;
	}
		
	MATRAN temp(n, 1);
	for (int i = 0; i < n; i++)
		temp.ds[i] = ds[i] / z.ds[i];
	return temp;	
}

istream& operator >> (istream& in, MATRAN& x) {
	cout << "Nhap so phan tu n = ";
	in >> x.n;
	for (int i = 0; i < x.n; i++) {
		cout << "a[" << i << "] = ";
		in >> x.ds[i];
	}
	return in;
}

ostream& operator << (ostream& out, MATRAN x) {
	for (int i = 0; i < x.n; i++)
		out << x.ds[i] << " ";
	return out;
}

int main() {
	MATRAN p, q;
	cout << "Nhap vao ma tran p:\n";
	cin >> p;
	cout << "\nNhap vao ma tran q:\n";
	cin >> q;
	MATRAN d = p / q;
	
	cout << "\nThuong cua 2 ma tran la: " << d;
	
	return 0;
}
