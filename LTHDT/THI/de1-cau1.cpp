#include <bits/stdc++.h>
using namespace std;

class VECTOR {
	private:
		int n;
		float *a;
	public:
		VECTOR();
		VECTOR(int size, float k);
		~VECTOR();
		float findMax();
		float findMin();
		friend istream& operator >> (istream& in, VECTOR& x);
		friend ostream& operator << (ostream& out, VECTOR x);
};

VECTOR::VECTOR() {
	n = 5;
	a = new float[n];
	for (int i = 0; i < n; i++)
		a[i] = 1.25;
}

VECTOR::VECTOR(int size, float k) {
	n = size;
	a = new float[n];
	for (int i = 0; i < n; i++)
		a[i] = k;
}

VECTOR::~VECTOR() {
	cout << "";
}

float VECTOR::findMin() {
	float min = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] < min)
			min = a[i];
	return min;
}

float VECTOR::findMax() {
	float max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

ostream& operator << (ostream& out, VECTOR x) {
	out << "So phan tu cua vector n = " << x.n << endl;
	out << "Danh sach phan tu: " << endl;
	for (int i = 0; i < x.n; i++)
		out << x.a[i] << " ";
	return out;
}

istream& operator >> (istream& in, VECTOR& x) {
	cout << "Nhap so phan tu n = ";
	in >> x.n;
	for (int i = 0; i < x.n; i++) {
		cout << "a[" << i << "] = ";
		in >> x.a[i];
	}
	return in;
}

int main() {
	VECTOR m;
	cout << "Nhap thong tin cua vector m:" << endl;
	cin >> m;
	cout << "Thong tin vector vua nhap la: " << endl;
	cout << m << endl;
	cout << "Phan tu nho nhat cua vector " << m.findMin() << endl;
	cout << "Phan tu lon nhat cua vector " << m.findMax() << endl;
	return 0;
}

