#include <iostream>
#include <fstream>
#define MAX 100
using namespace std;


class ARRAY {
	private:
		int n;
		float a[MAX];
	public:
		ARRAY();
		ARRAY(int n, float value);
		ARRAY operator++();
		ARRAY operator--();
		friend istream& operator>>(istream& in, ARRAY& x);
		friend ostream& operator<<(ostream& out, ARRAY x);
};

ARRAY::ARRAY() {
	n = 10;
	for (int i = 0; i < n; i++)
		a[i] = 0;
}

ARRAY::ARRAY(int n, float value) {
	for (int i = 0; i < n; i++)
		a[i] = value;
}

ARRAY ARRAY::operator++() {
	float temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	return *this;
}

ARRAY ARRAY::operator--() {
	float temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] < a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	return *this;
}

istream& operator >> (istream& in, ARRAY& x) {
	cout << "Nhap vao so phan mang N = ";
	in >> x.n;
	for (int i = 0; i < x.n; i++) {
		cout << "a[" << i << "] = ";
		in >> x.a[i];
	}
	return in;
}

ostream& operator << (ostream& out, ARRAY x) {
	for (int i = 0; i < x.n; i++) {
		out << x.a[i] << " ";
	}
	return out;
}


int main() {
	ofstream write("MANG.txt");
	ARRAY arrayTest;
	cin >> arrayTest;
	
	// mang ban dau
	cout << "\n1. Mang sau khi nhap la: \n";
	cout << arrayTest;
	
	write << "\n1. Mang sau khi nhap la: \n";
	write << arrayTest;
	
	// mang sau khi sap xep
	ARRAY arraySort = --arrayTest;
	cout << "\n\n2. Mang sau khi sap xep giam dan la: \n";
	cout << arraySort;
	
	write << "\n\n2. Mang sau khi sap xep giam dan la: \n";
	write << arraySort;
	write.close();
	return 0;
}
/*
10
1
2
3
4
5
6
7
8
9
10
*/
