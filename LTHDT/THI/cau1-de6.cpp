#include <bits/stdc++.h>
using namespace std;

class PHUONGTRINH {
	private:
		float a, b, c, d;
	public:
		PHUONGTRINH();
		void nhap();
		PHUONGTRINH operator!();
		friend ostream& operator << (ostream& out, PHUONGTRINH z);
};

PHUONGTRINH::PHUONGTRINH() {
	a = 0;
	b = 0;
	c = 0;
	d = 0;
}

void PHUONGTRINH::nhap() {
	cout << "Nhap he so a = ";     cin >> a;
	cout << "Nhap he so b = ";     cin >> b;
	cout << "Nhap he so c = ";     cin >> c;
	cout << "Nhap he so d = ";     cin >> d;
}

PHUONGTRINH PHUONGTRINH::operator!() {
	a = -a;
	b = -b;
	c = -c;
	d = -d;
	return *this;
}

ostream& operator << (ostream& out, PHUONGTRINH z) {
	out << z.a << "x^3";
	if (z.b < 0)
		out << " - " << -z.b << "z^2";
	else
		out << " + " << z.b << "z^2";
	
	if (z.c < 0)
		out << " - " << -z.c << "z";
	else
		out << " + " << z.c << "z";
		
	if (z.d < 0)
		out << " - " << -z.d;
	else
		out << " + " << z.d;
	return out;
}


int main() {
	PHUONGTRINH p;
	p.nhap();
	cout << endl << p;
	return 0;
}

