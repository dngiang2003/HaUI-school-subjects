#include<bits/stdc++.h>
using namespace std;

struct HOCPHAN{
	char MaHP[10];
	char TenHP[20];
	int SoTinChi;
};

struct Node{
	HOCPHAN infor;
	Node *next;
};

typedef Node *TRO;

void KhoiTao(TRO &L){
	L = NULL;
}

void NhapHP(HOCPHAN &hp){
	cout<<"Nhap ma hoc phan: "; 		fflush(stdin); 	gets(hp.MaHP);
	if(strcmp(hp.MaHP,"#") == 0) return;
	cout<<"Nhap ten hoc phan: "; 		fflush(stdin); 	gets(hp.TenHP);
	cout<<"Nhap so tin chi: ";	cin>>hp.SoTinChi;
}
void NhapDS(TRO &L){
	KhoiTao(L);
	HOCPHAN HP;
	TRO P, Q;
	int i=1;
	do{
		cout<<"________________________________"<<endl;
		cout<<"Nhap thong tin hoc phan thu "<<i<<": "<<endl;
		if (i>5)
			cout<<"\nDANH SACH DA DU 5 HOC PHAN, NHAP MA HP = '#' DE DUNG NHAP."<<endl;
		NhapHP(HP);
		if (strcmp(HP.MaHP,"#") == 0){
			if (i < 5) {
				cout<<"\nDANH SACH CHUA DU 5 HOC PHAN, NHAP TIEP THONG TIN."<<endl;
				NhapHP(HP);
			}
			else
				return;
		} 
		P = new (Node);
		P->infor = HP;
		P->next = NULL;
		if (L == NULL)
			L = P;
		else
			Q->next = P;
		Q = P;
		i++;
	} while(1);
}
void XuatDS(TRO L){
	if (L == NULL){
		cout<<"Danh sach rong!";
		return;
	}
	cout<<setw(5)<<"STT"<<setw(15)<<"Ma HP"<<setw(20)<<"Ten HP"<<setw(20)<<"So tin chi"<<endl;
	int i = 1;
	TRO Q = L;
	while(Q != NULL){
		HOCPHAN HP = Q->infor;
			cout<<setw(5)<<i<<setw(15)<<HP.MaHP<<setw(20)<<HP.TenHP<<setw(20)<<HP.SoTinChi<<endl;
			i++;
		Q = Q->next;
	}
}
//chen hoc phan moi vao vi tri thu 3
void Chen(TRO &L){
	HOCPHAN HP;
	cout<<"\nNhap thong tin hoc phan moi can chen vao vi tri thu 3: "<<endl;
	NhapHP(HP);
	TRO P,Q;
	Q = L;
	P = new(Node);
	P->infor = HP;
	for(int i=1; i<2; i++)
		Q = Q->next;
	P->next = Q->next;
	Q->next = P;
}
//thuc hien chen truoc
void TH_ChenTruoc(TRO &L, TRO Q, HOCPHAN HP){
	TRO P;
	P = new (Node);
	P->infor = HP;
	P->next = Q->next;
	Q->next = P;
}
//chen hoc phan moi vao truoc vi tri thu 3
void ChenTruoc(TRO &L){
	TRO T = L;
	for(int i=1; i<2; i++)
		T = T->next;
	HOCPHAN HP;
	cout<<"\nNhap thong tin hoc phan can chen truoc vi tri thu 3: "<<endl;
	NhapHP(HP);
	TH_ChenTruoc(L,T,HP);
	cout<<"___________ DANH SACH HOC PHAN DA CHEN THEM TRUOC VI TRI THU 3 ___________\n"<<endl;
	XuatDS(L);
}
//chen vao dau danh sach
void ChenDauTien(TRO &L){
	TRO P = new (Node);
	HOCPHAN HP;
	cout<<"\nNhap thong tin hoc phan can chen vao vi tri dau tien: "<<endl;
	NhapHP(HP);
	P->infor = HP;
	P->next = L;
	L = P;
	cout<<"___________ DANH SACH HOC PHAN DA CHEN VAO VI TRI DAU TIEN ___________\n"<<endl;
	XuatDS(L);
}
//tim so tin chi max
int Tim_STCmax(TRO &L){
	TRO Q = L;
	int max = 0;
	while (Q != NULL){
		if (Q->infor.SoTinChi > max) max = Q->infor.SoTinChi;
		Q = Q->next;
	}
	return max;
}
//hien thi danh sach hoc phan co stc max va danh sach sau khi xoa nhung hoc phan do
void STCmax(TRO &L){
	int i = 0;
	TRO Q = L;
	cout<<"\n__________________ DANH SACH HOC PHAN CO STC CAO NHAT ___________________\n"<<endl;
	cout<<setw(5)<<"STT"<<setw(15)<<"Ma HP"<<setw(20)<<"Ten HP"<<setw(20)<<"So tin chi"<<endl;
	while (Q != NULL){
		if (Q->infor.SoTinChi == Tim_STCmax(L)){
			i++;
			TRO T = Q;
			TRO M = Q;
			HOCPHAN HP = Q->infor;
			cout<<setw(5)<<i<<setw(15)<<HP.MaHP<<setw(20)<<HP.TenHP<<setw(20)<<HP.SoTinChi<<endl;
			if (T == L) L = T->next;
			else{
				M = L;
				while (M->next != T)
					M = M->next;
				M->next = T->next;
			}
			delete T;
		}
		Q = Q->next;
	}
	cout<<"\n_______________ DANH SACH HOC PHAN SAU KHI XOA STC CAO NHAT__________________\n"<<endl;
	XuatDS(L);
}
//tim vi tri truoc hoc phan ma 123 trong danh sach
TRO Tim_Ma123(TRO &L){
	TRO Q = L;
	TRO T;
	while (Q != NULL && strcmp(Q->infor.MaHP,"123")!=0){
		T = Q;
		Q = Q->next;
	}
	return T;
}
//xoa hoc phan truoc hoc phan co ma 123
void Ma123(TRO &L){
	TRO T = Tim_Ma123(L);
	if (T == NULL)
		cout<<"\nKHONG TON TAI MA HOC PHAN LA 123 TRONG DANH SACH"<<endl;
	else{
		if (T == L) L = T->next;
			else{
				TRO M = L;
				while (M->next != T)
					M = M->next;
				M->next = T->next;
			}
		delete T;
	}
	cout<<"\n_________________ DANH SACH HOC PHAN SAU KHI XOA ____________________\n"<<endl;
	XuatDS(L);
}
int main(){
	TRO L;
	cout<<"NHAP MA SINH VIEN = '#' DE DUNG NHAP DANH SACH\n"<<endl;
	NhapDS(L);
	cout<<"_____________________________ DANH SACH HOC PHAN ___________________________\n"<<endl;
	XuatDS(L);
	Chen(L);
	cout<<"________________ DANH SACH HOC PHAN DA CHEN VAO VI TRI THU 3 _______________\n"<<endl;
	XuatDS(L);
	ChenTruoc(L);
	ChenDauTien(L);
	STCmax(L);
	
	
	return 0;
}

