#include <iostream>
#include <fstream>
using namespace std;

class TAMGIAC {
	private:
		float a, b, c;
	public:
		TAMGIAC();
		TAMGIAC(float x, float y, float z);
		float operator!();
		friend istream& operator>>(istream& in, TAMGIAC& x);
		friend ostream& operator<<(ostream& out, TAMGIAC x);
};

TAMGIAC::TAMGIAC() {
	a = 12;
	b = 5;
	c = 2003;
}

TAMGIAC::TAMGIAC(float x, float y, float z) {
	a = x;
	b = y;
	c = z;
}

float TAMGIAC::operator!() {
	return a + b + c;
}

istream& operator>>(istream& in, TAMGIAC& x) {
	cout << "Nhap canh a = ";
	in >> x.a;
	cout << "\nNhap canh b = ";
	in >> x.b;
	cout << "\nNhap canh c = ";
	in >> x.c;
	return in;
}

ostream& operator<<(ostream& out, TAMGIAC x) {
	out << "\nCanh a = " << x.a << endl;
	out << "\nCanh b = " << x.b << endl;
	out << "\nCanh c = " << x.c << endl;
	out << "\nChu vi = " << x.a << " + ";
	out << x.b << " + " << x.c << " = ";
	out << !x << endl;
	return out;
}

int main() {
	TAMGIAC P, Q;
	ofstream write("INOUT.txt");
	cout << "Nhap thong tin tam gia P:\n";
	cin >> P;
	cout << "\nNhap thong tin tam gia Q:\n";
	cin >> Q;
	
	// xuat thong tin
	cout << "\nThong tin tam gia P:\n";
	cout << P;
	write << "\nThong tin tam gia P:\n";
	write << P;
	
	cout << "\nThong tin tam gia Q:\n";
	cout << Q;
	write << "\nThong tin tam gia Q:\n";
	write << Q;
	return 0;
}
/*
1
2
3
4
5
6
*/
