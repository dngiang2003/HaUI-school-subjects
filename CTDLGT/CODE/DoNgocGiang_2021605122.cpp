#include <bits/stdc++.h>
using namespace std;
#define MAX 125

struct SinhVien {
	char HoTen[30];
	char GioiTinh[10];
	int NamSinh;
	float Diem;
};

struct List {
	int count;
	SinhVien ds[MAX];
};

void NhapSV(SinhVien &sv) {
	cout << "Nhap ho ten sinh vien: ";	  fflush(stdin);		gets(sv.HoTen);
	cout << "Nhap gioi tinh: ";		      fflush(stdin);		gets(sv.GioiTinh);
	cout << "Nhap nam sinh: ";			  cin >> sv.NamSinh;
	cout << "Nhap diem: ";				  cin >> sv.Diem;
}

void NhapDSSV(List &L) {
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	L.count = 0;
	for (int i = 0; i < n; i++) {
		cout << "\nNhap thong tin sinh vien thu " << i + 1 << endl;
		NhapSV(L.ds[i]);
		L.count++;
	}
}

void XuatSV(SinhVien sv) {
	cout << setw(25) << sv.HoTen
		 << setw(15) << sv.GioiTinh
		 << setw(15) << sv.NamSinh
		 << setw(15) << sv.Diem << endl;
}

void XuatDSSV(List &L) {
	cout << setw(25) << "Ho ten"
		 << setw(15) << "Gioi tinh"
		 << setw(15) << "Nam sinh"
		 << setw(15) << "Diem" << endl;
	// in danh sach
	for(int i = 0; i < L.count; i++)
		XuatSV(L.ds[i]);
}

void SapXepSV(List &L) {
	// sap xep theo diem
	cout << L.count;
	for (int i = 0; i < L.count - 1; i++)
		for (int j = i + 1; j < L.count; j++)
			if (L.ds[i].Diem < L.ds[j].Diem) 
				swap(L.ds[i], L.ds[j]);
	cout << "\nDanh sach sinh vien sau khi sap xep la:\n";
}

void ChenSV(List &L) {
	cout << "\nChen them sinh vien\n";
	SinhVien x;
	NhapSV(x);
	int pos;
	cout << "Nhap vi tri can chen: ";
	cin >> pos;
	// kiem tra vi tri
	while (pos < 1 || pos > L.count) {
		cout << "Nhap lai vi tri chen: ";
		cin >> pos;
	}
	// chen
	for (int i = L.count; i >= pos; i--)
		L.ds[i] = L.ds[i - 1];
    L.ds[pos - 1] = x;
    L.count++;
    cout << "\nDanh sach sinh vien sau khi chen la:\n";
}

void TimTheoTen(List &L) {
	SinhVien e[MAX];
	cout << "Tim kiem sinh vien theo ten:\n";
	char name[30];
	cout << "Nhap ten sv can tim: ";    fflush(stdin);    gets(name);
	int flag = 0;
	for (int i = 0; i < L.count; i++)
		if (strcmp(name, L.ds[i].HoTen) == 0) {
			e[flag++] = L.ds[i];
		}
	if (flag) {
		cout << "Thong tim sinh vien vua tim la: \n";
		for (int i = 0; i <= flag; i++)
			XuatSV(e[i]);
	} else {
		cout << "Khong tim thay sinh vien nao!\n";
	}
	cout << endl;
}

void TimTheoDiem(List &L) {
	SinhVien e[MAX];
	cout << "Tim kiem sinh vien theo diem:\n";
	float diem;
	cout << "Nhap diem sv can tim: ";
	cin >> diem;
	int flag = 0;
	for (int i = 0; i < L.count; i++)
		if (L.ds[i].Diem == diem)
			e[flag++] = L.ds[i];
	if (flag) {
		cout << "Thong tim sinh vien vua tim la: \n";
		for (int i = 0; i <= flag; i++)
			XuatSV(e[i]);
	} else {
		cout << "Khong tim thay sinh vien nao!\n";
	}
	cout << endl;
}

void XoaSV(List &L) {
	int pos;
	cout << "Nhap vi tri sinh vien can xoa: ";
	cin >> pos;
	while(pos < 1 || pos > L.count) {
		cout << "Nhap lai vi tri sinh vien can xoa: ";
		cin >> pos;
	}
	for(int i = pos-1; i < L.count; i++) {
		L.ds[i]= L.ds[i+1];
	}
	L.count--;
	cout << "\nDanh sach sinh vien sau khi xoa la:\n";
}


int main() {
	List L;
	NhapDSSV(L);
	XuatDSSV(L);
	SapXepSV(L);
	XuatDSSV(L);
	ChenSV(L);
	XuatDSSV(L);
	TimTheoTen(L);
	TimTheoDiem(L);
	XoaSV(L);
	XuatDSSV(L);
	return 0;
}
