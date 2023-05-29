#include <bits/stdc++.h>
using namespace std;


class TTB2 {
	private:
		float a, b, c;
	public:
		TTB2();
		TTB2(float x, float y, float z);
		TTB2 operator+(TTB2 z);
		TTB2 operator!();
};

TTB2::TTB2() {
	a = 1;
	b = 1;
	c = 1;
}

TTB2::TTB2(float x, float y, float z) {
	a = x;
	b = y;
	c = z;
}

TTB2 TTB2::operator+(TTB2 z) {
	TTB2 temp;
	temp.a = a + z.a;
	temp.b = b + z.b;
	temp.c = c + z.c;
	return temp;
}

TTB2 TTB2::operator!() {
	a = -a;
	b = -b;
	c = -c;
	return *this;
}


int main() {
	TTB2 m(1, 3, 4);
	cout << m.a;
	return 0;
}

