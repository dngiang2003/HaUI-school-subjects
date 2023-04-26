#include<bits\stdc++.h>
using namespace std;
#define max 50

struct SACH{
	char MaSach[10];
	char TenSach[20];
	char TenTG[20];
	int NamXB;
};

struct List{
	int count;
	SACH S[max];
};
void KhoiTao(List &L){
	L.count = -1;
}
int Full(List L){
	return L.count == max-1;
}
int Empty(List L){
	return L.count == -1;
}
//them cuoi
int Add(List &L, SACH S){
	if (Full(L)) return 0;
	else{
		L.count++;
		L.S[L.count] = S;
		return 1;
	}
}
void Nhap(SACH &s){
	cout<<"\nNhap ma sach: "; fflush(stdin); gets(s.MaSach);
	if (strcmp(s.MaSach, "#") == 0) return;
	cout<<"Nhap ten sach: "; fflush(stdin); gets(s.TenSach);
	cout<<"Nhap ten tac gia: "; fflush(stdin); gets(s.TenTG);
	cout<<"Nhap nam xuat ban: "; cin>>s.NamXB;
}
void NhapDS(List &L){
	KhoiTao(L);
	SACH S;
		int i=1;
		do {
			cout<<"________________________________"<<endl;
			cout<<"Nhap thong tin cuon sach thu "<<i<<": "<<endl;
			Nhap(S);
			if(strcmp(S.MaSach,"#") == 0) return;
			if (!Add(L,S)){
				cout<<"\nDUNG NHAP VI DANH SACH DA DAY."<<endl;
				return;
			} 
			i++;
		} while(1);
}
void XuatDS(List &L){
	cout<<setw(5)<<"STT"<<setw(10)<<"Ma sach"<<setw(20)<<"Ten sach"<<setw(20)<<"Ten tac gia"<<setw(15)<<"Nam XB"<<endl;
	for (int i=0; i<=L.count; i++)
		cout<<setw(5)<<i+1<<setw(10)<<L.S[i].MaSach<<setw(20)<<L.S[i].TenSach<<setw(20)<<L.S[i].TenTG<<setw(15)<<L.S[i].NamXB<<endl;
}
//xoa vi tri thu 4
void Xoa(List &L){
	SACH S;
	for (int i=3; i<L.count; i++){
		L.S[i] = L.S[i+1];
	}
	L.count--;
	cout<<"_____________________ DANH SACH THONG TIN SACH DA XOA ____________________\n"<<endl;
	XuatDS(L);
}
//chen vi tri thu 3
void Chen(List &L){
	SACH S;
	cout<<"\nNhap thong tin cuon sach can chen: ";
	Nhap(S);
	L.count++;
	for (int i=L.count; i>2; i--){
		L.S[i] = L.S[i-1];
	}
	L.S[2] = S;
	cout<<"_____________________ DANH SACH THONG TIN SACH DA CHEN ____________________\n"<<endl;
	XuatDS(L);
}
int main(){
	List L;
	cout<<"NHAP MA SACH = '#' DE DUNG NHAP DANH SACH\n"<<endl;
	NhapDS(L);
	cout<<"________________________ DANH SACH THONG TIN SACH _______________________\n"<<endl;
	XuatDS(L);
	if (L.count >= 4)
		Xoa(L);
	else
		cout<<"\nKHONG THUC HIEN XOA VI DANH SACH CO IT HON 4 CUON SACH."<<endl;
	if (L.count >= 2)
		Chen(L);
	else
		cout<<"\nKHONG THUC HIEN XOA VI DANH SACH CO IT HON 2 CUON SACH."<<endl;
		
	return 0;
}



