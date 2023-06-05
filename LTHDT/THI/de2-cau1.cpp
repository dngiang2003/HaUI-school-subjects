#include <bits/stdc++.h>
using namespace std;

class COMPLEX {
	private:
		float phanThuc, phanAo;
	public:
		COMPLEX();
		COMPLEX(float a, float b);
		COMPLEX operator+(COMPLEX z);
		friend istream& operator >> (istream& in, COMPLEX& z);
		friend ostream& operator << (ostream& out, COMPLEX z);
};

COMPLEX::COMPLEX() {
	phanThuc = 2003;
	phanAo = 2003;
}

COMPLEX::COMPLEX(float a, float b) {
	phanThuc = a;
	phanAo = b;
}

COMPLEX COMPLEX::operator+(COMPLEX z) {
	COMPLEX temp;
	temp.phanThuc = phanThuc + z.phanThuc;
	temp.phanAo = phanAo + z.phanAo;
	return temp;
}

istream& operator >> (istream& in, COMPLEX& x) {
	cout << "Nhap phan thuc: ";
	in >> x.phanThuc;
	cout << "Nhap phan ao: ";
	in >> x.phanAo;
	return in;
}

ostream& operator << (ostream& out, COMPLEX x) {
	out << x.phanThuc;
	if (x.phanAo < 0) {
		out << " - " << -x.phanAo;
	} else {
		out << " + " << x.phanAo;
	}
	out << "i";
	return out;
}



int main() {
	int n;
	cout << "Nhap so luong n = ";
	cin >> n;
	COMPLEX *ds = new COMPLEX[n];
	COMPLEX result(0, 0);
	for (int i = 0; i < n; i++) {
		cout << "Nhap so phuc thu " << i + 1 << endl;
		cin >> ds[i];
		result = result + ds[i];
	}
	cout << "\nTong cac so phuc la: ";
	cout << result;
	return 0;
}

