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
		TTB2 operator-(TTB2 z);
		friend istream& operator >> (istream& in, TTB2& z);
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

TTB2 TTB2::operator-(TTB2 z) {
	TTB2 temp;
	temp.a = a - z.a;
	temp.b = b - z.b;
	temp.c = c - z.c;
	return temp;
}

istream& operator >> (istream& in, TTB2& z) {
	cout << "Nhap vao he so a = ";
	in >> z.a;
	cout << "Nhap vao he so b = ";
	in >> z.b;
	cout << "Nhap vao he so c = ";
	in >> z.c;
	return in;
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
	TTB2 a(-1, -2, -3);
	TTB2 b(4, 5, 6);
	a = !a;
	b = !b;
	TTB2 c, d;
	c = a + b;
	d = a - b;
	cout << "Tam thuc thu nhat la: " << a << endl;
	cout << "Tam thuc thu hai la: " << b << endl;
	cout << "\nTong cua 2 tam thuc la: " << c << endl;
	cout << "\nHieu cua 2 tam thuc la: " << d << endl;
	return 0;
}
