#include <iostream>
#include <string.h>
using namespace std;

class SOPHUC {
	private:
		int phanThuc, phanAo;
	public:
		SOPHUC();
		SOPHUC(int a, int b);
		SOPHUC operator+(SOPHUC z);
		SOPHUC operator-(SOPHUC z);
		friend istream& operator >> (istream& in, SOPHUC& x);
		friend ostream& operator << (ostream& out, SOPHUC x);
};

SOPHUC::SOPHUC() {
	phanThuc = 0;
	phanAo = 0;
}

SOPHUC::SOPHUC(int a, int b) {
	phanThuc = a;
	phanAo = b;
}

SOPHUC SOPHUC::operator+(SOPHUC z) {
	SOPHUC temp;
	temp.phanThuc = phanThuc + z.phanThuc;
	temp.phanAo = phanAo + z.phanAo;
	return temp;
}

SOPHUC SOPHUC::operator-(SOPHUC z) {
	SOPHUC temp;
	temp.phanThuc = phanThuc - z.phanThuc;
	temp.phanAo = phanAo - z.phanAo;
	return temp;
}

istream& operator >> (istream& in, SOPHUC& x) {
	cout << "Nhap vao phan thuc: ";
	in >> x.phanThuc;
	cout << "Nhap vao phan ao: ";
	in >> x.phanAo;
	return in;
}

ostream& operator << (ostream& out, SOPHUC x) {
	if (x.phanAo < 0) {
		out << x.phanThuc << " - " << -x.phanAo << "i" << endl;
	} else {
		out << x.phanThuc << " + " << x.phanAo << "i" << endl;
	}
	return out;
}

int main() {
	SOPHUC sp1, sp2, sp3, sp4;
	cout << "Nhap so phuc thu nhat: \n";
	cin >> sp1;
	cout << "\nNhap so phuc thu hai: \n";
	cin >> sp2;
	// tinh
	sp3 = sp1 + sp2;
	sp4 = sp1 - sp2;
	cout << "\nTong 2 so phuc = " << sp3 << endl;
	cout << "Hieu 2 so phuc = " << sp4;
	return 0;
}
