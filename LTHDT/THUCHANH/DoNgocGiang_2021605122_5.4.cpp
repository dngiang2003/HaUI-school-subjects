#include <iostream>
#define MAX 100
using namespace std;

class MATRAN {
	private:
		double a[MAX][MAX];
		int n, m;
	public:
		MATRAN();
		MATRAN(int n, int m, double k);
		MATRAN operator+(MATRAN z);
		MATRAN operator-(MATRAN z);
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
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = -a[i][j];
		}
	}
	return *this;
}

MATRAN MATRAN::operator+(MATRAN z) {
	// truong hop 2 ma tran khac kich thuoc
	if (n != z.n || m != z.m) {
		MATRAN error(1, 1, -1);
		return error;
	}
	// tong hai ma tran
	MATRAN temp(n, m , 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp.a[i][j] = a[i][j] + z.a[i][j];
		}
	}
	return temp;
}

MATRAN MATRAN::operator-(MATRAN z) {
	// truong hop 2 ma tran khac kich thuoc
	if (n != z.n || m != z.m) {
		MATRAN error(1, 1, -1);
		return error;
	}
	// hieu 2 ma tran
	MATRAN temp(n, m, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp.a[i][j] = a[i][j] - z.a[i][j];
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
	
	// doi dau 2 ma tran
	P = !P;
	Q = !Q;
	cout << "\nMa tran P sau khi doi dau: \n";
	cout << P;
	cout << "\nMa tran Q sau khi doi dau: \n";
	cout << Q;
	
	// tong, hieu 2 ma tran
	cout << "\nTong 2 ma tran P va Q la: \n";
	cout << P + Q;
	cout << "\nTong 2 ma tran P va Q la: \n";
	cout << P - Q;
	return 0;
}
