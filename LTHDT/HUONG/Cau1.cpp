#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int findMin(int a, int b) {
	return a < b ? a : b;
}

int findMax(int a, int b) {
	return b < a ? a : b;
}

class MATRAN {
	private:
		int n;
		int ds[MAX];
	public:
		MATRAN();
		MATRAN(int size, int k);
		MATRAN operator+(MATRAN z);
		MATRAN operator*(MATRAN z);
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

int MATRAN::operator!() {
	int max = ds[0];
	for (int i = 1; i < n; i++) 
		if (ds[i] > max)
			max = ds[i];
	return max;
}

MATRAN MATRAN::operator+(MATRAN z) {
	int min = findMin(n, z.n);
	int max = findMax(n, z.n);
	MATRAN temp(max, 1);
	for (int i = 0; i < min; i++)
		temp.ds[i] = ds[i] + z.ds[i];
	
	if (n < max) {
		for (int i = min; i < max; i++)
			temp.ds[i] = z.ds[i];
	} else {
		for (int i = min; i < max; i++)
			temp.ds[i] = ds[i];
	}
	return temp;	
}

MATRAN MATRAN::operator*(MATRAN z) {
	int min = findMin(n, z.n);
	int max = findMax(n, z.n);
	MATRAN temp(max, 1);
	for (int i = 0; i < min; i++)
		temp.ds[i] = ds[i] * z.ds[i];
	
	if (n < max) {
		for (int i = min; i < max; i++)
			temp.ds[i] = z.ds[i];
	} else {
		for (int i = min; i < max; i++)
			temp.ds[i] = ds[i];
	}
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
	
	MATRAN c = p + q;
	MATRAN d = p * q;
	
	cout << "\nTong cua 2 ma tran la: " << c << endl;
	cout << "\nTich cua 2 ma tran la: " << d;
	
	return 0;
}
/*
3
1
3
5
4
2
4
6
8
*/

