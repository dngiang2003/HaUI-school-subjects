#include <iostream>
#define ll long long
#define MAX 125
using namespace std;

class MATRAN {
	private:
		int n, m;
		double a[MAX][MAX];
	public:
		MATRAN();
		MATRAN(int n, int m, double k);
		MATRAN operator!();
		friend istream& operator>>(istream& in, MATRAN& x);
		friend ostream& operator<<(ostream& out, MATRAN x);
		
};

MATRAN::MATRAN() {
	n = 3;
	m = 3;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = 0;
}

MATRAN::MATRAN(int n, int m, double k) {
	this->n = n;
	this->m = m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = k;
}

istream& operator >> (istream& in, MATRAN& x) {
	cout << "Nhap so cot n = ";
	in >> x.n;
	cout << "Nhap so cot m = ";
	in >> x.m;
	for (int i = 0; i < x.n; i++)
		for (int j = 0; j < x.m; j++) {
			cout << "a[" << i << "][" << j <<"] = ";
			in >> x.a[i][j];
		}
	return in;
}

ostream& operator << (ostream& out, MATRAN x) {
	for (int i = 0; i < x.n; i++) {
		for (int j = 0; j < x.m; j++) {
			out << x.a[i][j] << " ";
		}
		out << endl;
	}
	return out;
}

MATRAN MATRAN::operator!() {
	MATRAN temp(m, n, 0);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp.a[i][j] = a[j][i];
		}
	}
	return temp;
}

int main() {
	MATRAN P, Q;
	cout << "Nhap vao ma tran P: \n";
	cin >> P;
	cout << "\nNhap vao ma tran Q: \n";
	cin >> Q;
	
	// chuyen vi
	P = !P;
	Q = !Q;
	cout << "\nMa tran P sau khi chuyen vi: \n";
	cout << P;
	cout << "\nMa tran Q sau khi chuyen vi: \n";
	cout << Q;
	return 0;
}
/*
2
2
1
2
3
4
3
3
1.1
2.2
3.3
4.4
5.5
6.6
7.7
8.8
9.9
*/

