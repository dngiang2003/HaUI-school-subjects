#include <bits/stdc++.h>
using namespace std;

class XE {
	protected:
		char mauSon[20];
		char bienSo[20];
		char noiDK[30];
		int namDK;
	public:
		XE();
		XE(char *ms, char *bs, char *ndk, int nam);
		~XE();
		void nhap();
		void xuat();
};

XE::XE() {
	strcpy(mauSon, "do");
	strcpy(bienSo, "34-E1 9968");
	strcpy(noiDK, "Hai Duong");
	namDK = 2022;
}

XE::XE(char *ms, char *bs, char *ndk, int nam) {
	strcpy(mauSon, ms);
	strcpy(bienSo, bs);
	strcpy(noiDK, ndk);
	namDK = nam;
}

XE::~XE() {
	cout << "";
}

void XE::nhap() {
	cout << "Nhap mau son: ";     fflush(stdin);     gets(mauSon);
	cout << "Nhap bien so: ";     fflush(stdin);     gets(bienSo);
	cout << "Nhap noi DK: ";      fflush(stdin);     gets(noiDK);
	cout << "Nhap nam DK: ";      cin >> namDK;
}

void XE::xuat() {
	cout << setw(10) << mauSon;
	cout << setw(15) << bienSo;
	cout << setw(15) << noiDK;
	cout << setw(10) << namDK << endl;
}

class CHUSOHUU: public XE {
	private:
		char tenCSH[45];
		char CMT[15];
	public:
		CHUSOHUU();
		CHUSOHUU(char *ms, char *bs, char *ndk, int nam, char *csh, char *cmt);
		~CHUSOHUU();
		void nhap();
		void xuat();
		friend void xuatHaNoi(CHUSOHUU ds[], int n);
};

CHUSOHUU::CHUSOHUU() {
	strcpy(tenCSH, "Minh Tien");
	strcpy(CMT, "123456789");
}

CHUSOHUU::CHUSOHUU(char *ms, char *bs, char *ndk, int nam, char *csh, char *cmt):XE(ms, bs, ndk, nam) {
	strcpy(tenCSH, csh);
	strcpy(CMT, cmt);
}

CHUSOHUU::~CHUSOHUU() {
	cout << "";
}

void CHUSOHUU::nhap() {
	cout << "Nhap ten csh: ";     fflush(stdin);    gets(tenCSH);
	cout << "Nhap cmt: ";         fflush(stdin);    gets(CMT);
	XE::nhap();
}

void CHUSOHUU::xuat() {
	cout << setw(20) << tenCSH;
	cout << setw(15) << CMT;
	XE::xuat();
}

void xuatAll(CHUSOHUU ds[], int n) {
	cout << setw(20) << "Chu so huu";
	cout << setw(15) << "CMT";
	cout << setw(10) << "Mau sac";
	cout << setw(15) << "Bien so";
	cout << setw(15) << "Noi DK";
	cout << setw(10) << "Nam DK" << endl;
	for (int i = 0; i < n; i++)
		ds[i].xuat();
}

void xuatHaNoi(CHUSOHUU ds[], int n) {
	int count = 0;
	CHUSOHUU temp[100];
	for (int i = 0; i < n; i++)
		if (strcmp(ds[i].noiDK, "Ha Noi") == 0) {
			temp[count++] = ds[i];
		}
	if (!count) {
		cout << "\nKhong co se nao o Ha Noi!";
		return;
	}
	cout << "\nDanh sach tren co " << count << " xe DK o Ha Noi: \n";
	xuatAll(temp, count);
}

int main() {
	cout << "Nhap so chu so huu k = ";
	int k;
	cin >> k;
	CHUSOHUU ds[100];
	for (int i = 0; i < k; i++) {
		cout << "Nhap thong tin chu so huu thu " << i + 1 << endl;
		ds[i].nhap();
	}
	xuatAll(ds, k);
	xuatHaNoi(ds, k);
	return 0;
}

