#include <iostream>
using namespace std;

class TTB2 {
	private:
		float a, b, c;
	public:
		TTB2();
		TTB2(float x, float y, float z);
		TTB2 operator!();
		TTB2 operator+(TTB2 z);
		friend ostream& operator << (ostream& out, TTB2 z);
};

TTB2::TTB2() {
	a = 0;
	b = 0;
	c = 0;
}

TTB2::TTB2(float x, float y, float z) {
	a = x;
	b = y;
	c = z;
}

TTB2 TTB2::operator!() {
	a = -a;
	b = -b;
	c = -c;
	return *this;
}

TTB2 TTB2::operator+(TTB2 z) {
	TTB2 temp;
	temp.a = a + z.a;
	temp.b = b + z.b;
	temp.c = c + z.c;
	return temp;
}

ostream& operator << (ostream& out, TTB2 z) {
	out << z.a << "x^2";
	// xu ly b
	if (z.b < 0)
		out << " - " << -z.b << "x";
	else
		out << " + " << z.b << "x";
	// xu ly c	
	if (z.c < 0) 
		out << " - " << -z.c;
	else 
		out << " + " << z.c << endl;
	return out;
}

int main() {
	TTB2 x(-1, -2, -3);
	TTB2 y(-4, -5, -6);
	cout << "Tam thuc x ban dau la: " << x << endl;
	x = !x;
	cout << "Tam thuc x sau khi doi dau la: " << x << endl;
	TTB2 t = x + y;
	cout << "\nTong cua 2 tam thuc la: " << t << endl;
	return 0;
}
