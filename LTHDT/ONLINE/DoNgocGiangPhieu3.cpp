#include <iostream>
#include <fstream>
using namespace std;

class PHANSO {
	private:
		int tuSo, mauSo;
	public:
		PHANSO();
		PHANSO(int a, int b);
		PHANSO operator*(PHANSO z);
		float operator!();
		friend istream& operator >> (istream& in, PHANSO& x);
		friend ostream& operator << (ostream& out, PHANSO x);
};

PHANSO::PHANSO() {
	tuSo = 0;
	mauSo = 1;
}

PHANSO::PHANSO(int a, int b) {
	tuSo = a;
	mauSo = b;
}

istream& operator >> (istream& in, PHANSO& x) {
	cout << "Nhap vao tu so: ";
	in >> x.tuSo;
	cout << "Nhap vao mau so: ";
	in >> x.mauSo;
	while (x.mauSo == 0) {
		cout << "Nhap lai mau so: ";
		in >> x.mauSo;
	}
	return in;
}

ostream& operator << (ostream& out, PHANSO x) {
	out << x.tuSo << "/" << x.mauSo;
	return out;
}

PHANSO PHANSO::operator*(PHANSO z) {
	PHANSO temp;
	temp.tuSo = tuSo * z.tuSo;
	temp.mauSo = mauSo * z.mauSo;
	return temp;
}

float PHANSO::operator!() {
	return (float)tuSo / mauSo;
}

int main() {
	PHANSO a, b, tich;
	cout << "Nhap phan so dau tien: " << endl;
	cin >> a;
	cout << "\nNhap phan so thu hai: " << endl;
	cin >> b;
	ofstream write("PHANSO.txt");
	
	// tich
	tich = a * b;
	cout  << "\nTich cua 2 phan so = " << tich << " ~ " << !tich << endl;
    write << "\nTich cua 2 phan so = " << tich << " ~ " << !tich << endl;
    
    write.close();
	return 0;
}
