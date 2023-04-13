#include <iostream>
#include <fstream>
using namespace std;

class PHANSO {
	private:
		int tuSo, mauSo;
	public:
		PHANSO();
		PHANSO(int a, int b);
		PHANSO operator+(PHANSO z);
		PHANSO operator-(PHANSO z);
		PHANSO operator*(PHANSO z);
		PHANSO operator/(PHANSO z);
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

PHANSO PHANSO::operator+(PHANSO z) {
	PHANSO temp;
	temp.tuSo = tuSo * z.mauSo + mauSo * z.tuSo;
	temp.mauSo = mauSo * z.mauSo;
	return temp;
}

PHANSO PHANSO::operator-(PHANSO z) {
	PHANSO temp;
	temp.tuSo = tuSo * z.mauSo - mauSo * z.tuSo;
	temp.mauSo = mauSo * z.mauSo;
	return temp;
}

PHANSO PHANSO::operator*(PHANSO z) {
	PHANSO temp;
	temp.tuSo = tuSo * z.tuSo;
	temp.mauSo = mauSo * z.mauSo;
	return temp;
}

PHANSO PHANSO::operator/(PHANSO z) {
	PHANSO temp;
	temp.tuSo = tuSo * z.mauSo;
	temp.mauSo = mauSo * z.tuSo;
	return temp;
}

float PHANSO::operator!() {
	return (float)tuSo / mauSo;
}

int main() {
	PHANSO a, b;
	cout << "Nhap phan so dau tien: " << endl;
	cin >> a;
	cout << "\nNhap phan so thu hai: " << endl;
	cin >> b;
	ofstream write("data3.1.txt");
	
	PHANSO tich, thuong, tong, hieu;
	
	// tich
	tich = a * b;
	cout  << "\nTich cua 2 phan so = " << tich << " ~ " << !tich << endl;
    write << "\nTich cua 2 phan so = " << tich << " ~ " << !tich << endl;
    
    // thuong
    thuong = a / b;
	cout  << "\nThuong cua 2 phan so = " << thuong << " ~ " << !thuong << endl;
    write << "\nThuong cua 2 phan so = " << thuong << " ~ " << !thuong << endl;
    
    // tong
    tong = a + b;
	cout  << "\nTong cua 2 phan so = " << tong << " ~ " << !tong << endl;
    write << "\nTong cua 2 phan so = " << tong << " ~ " << !tong << endl;
    
    // hieu
    hieu = a - b;
	cout  << "\nHieu cua 2 phan so = " << hieu << " ~ " << !hieu << endl;
    write << "\nHieu cua 2 phan so = " << hieu << " ~ " << !hieu << endl;
    write.close();
	return 0;
}
