#include<bits/stdc++.h>
using namespace std;

struct THISINH{
	int SoBD;
	char HoTen[20];
	int NamSinh;
	char KhoiThi[5];
	float TongDiem;
};
struct Node{
	THISINH infor;
	Node *next;
};

typedef Node *TRO;

void KhoiTao(TRO &L){
	L = NULL;
}
int Length(TRO L){
	int n = 0;
	TRO Q = L;
	while (Q != NULL){
		Q = Q->next;
		n++;
	}
	return n;
}

void NhapTS(THISINH &ts){
	cout<<"Nhap so bao danh: "; cin>>ts.SoBD;
	if(ts.SoBD == 0) return;
	cout<<"Nhap ho va ten: "; 	fflush(stdin); 	gets(ts.HoTen);
	cout<<"Nhap nam sinh: "; cin>>ts.NamSinh;
	cout<<"Nhap khoi thi: "; 	fflush(stdin); 	gets(ts.KhoiThi);
	cout<<"Nhap tong diem: "; cin>>ts.TongDiem;
}
void NhapDS(TRO &L){
	KhoiTao(L);
	THISINH TS;
	TRO P, Q;
	int i=1;
	do{
		cout<<"________________________________"<<endl;
		cout<<"Nhap thong tin hoc thi sinh "<<i<<": "<<endl;
		if (i>5)
			cout<<"\nDANH SACH DA DU 5 THI SINH, NHAP SBD = '0' DE DUNG NHAP."<<endl;
		NhapTS(TS);
		if (TS.SoBD == 0){
			if (i < 5) {
				cout<<"\nDANH SACH CHUA DU 5 THI SINH, NHAP TIEP THONG TIN."<<endl;
				NhapTS(TS);
			}
			else
				return;
		} 
		P = new (Node);
		P->infor = TS;
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
	cout<<setw(5)<<"STT"<<setw(10)<<"So BD"<<setw(20)<<"Ho va ten"<<setw(10)<<"Nam sinh"<<setw(10)<<"Khoi thi"<<setw(10)<<"Tong diem"<<endl;
	int i = 1;
	TRO Q = L;
	while(Q != NULL){
		THISINH TS = Q->infor;
			cout<<setw(5)<<i<<setw(10)<<TS.SoBD<<setw(20)<<TS.HoTen<<setw(10)<<TS.NamSinh<<setw(10)<<TS.KhoiThi<<setw(10)<<TS.TongDiem<<endl;
			i++;
		Q = Q->next;
	}
}
//xoa thi sinh o vi tri thu 3
void XoaT3(TRO &L){
	TRO T = L;
	for(int i=1; i<3; i++)
		T = T->next;
	if (T == L) L = T->next;
		else{
			TRO M = L;
			while (M->next != T)
				M = M->next;
			M->next = T->next;
			}
	delete T;
	cout<<"\n_____________________ DANH SACH HOC PHAN SAU KHI XOA _______________________\n"<<endl;
	XuatDS(L);
}
//tim vi tri thi sinh khoi A1
int Tim_KhoiA1(TRO &L){
	int tg = 0;
	TRO Q = L;
	for(int i=1; i<=Length(L); i++){
		if(strcmp(Q->infor.KhoiThi,"A1") == 0 )
			tg++;
		Q = Q->next;
		return tg;
   }
}
//hien thi danh sach thi sinh khoi a1
void KhoiA1(TRO &L){
	int tg = Tim_KhoiA1(L);
	if (tg == 0)
		cout<<"\nKHONG CO THI SINH THI KHOI A1\n"<<endl;
	else{
		TRO Q = L;
		int i = 1;
		int j = 1;
		cout<<"_____________________DANH SACH THI SINH KHOI A1___________________\n"<<endl;
		cout<<setw(5)<<"STT"<<setw(10)<<"So BD"<<setw(20)<<"Ho va ten"<<setw(10)<<"Nam sinh"<<setw(10)<<"Khoi thi"<<setw(10)<<"Tong diem"<<endl;
		while(i<=Length(L) && Q!=NULL){
			THISINH TS = Q->infor;
			if(strcmp(Q->infor.KhoiThi,"A1") == 0 ){
				cout<<setw(5)<<i<<setw(10)<<TS.SoBD<<setw(20)<<TS.HoTen<<setw(10)<<TS.NamSinh<<setw(10)<<TS.KhoiThi<<setw(10)<<TS.TongDiem<<endl;
				j++;
			}
				Q = Q->next;
				i++;
		}
    }
}
//tim tong diem max
float Tim_Tongmax(TRO &L){
	TRO Q = L;
	float max = 0;
	while (Q != NULL){
		if (Q->infor.TongDiem > max) max = Q->infor.TongDiem;
		Q = Q->next;
	}
	return max;
}
//hien thi danh sach thi sinh co tong diem cao nhat
void Tongmax(TRO &L){
	int i = 0;
	TRO Q = L;
	cout<<"\n__________________ DANH SACH THI SINH CO TONG DIEM CAO NHAT ___________________\n"<<endl;
	cout<<setw(5)<<"STT"<<setw(10)<<"So BD"<<setw(20)<<"Ho va ten"<<setw(10)<<"Nam sinh"<<setw(10)<<"Khoi thi"<<setw(10)<<"Tong diem"<<endl;
	while (Q != NULL){
		if (Q->infor.TongDiem == Tim_Tongmax(L)){
			i++;
			THISINH TS = Q->infor;
			cout<<setw(5)<<i<<setw(10)<<TS.SoBD<<setw(20)<<TS.HoTen<<setw(10)<<TS.NamSinh<<setw(10)<<TS.KhoiThi<<setw(10)<<TS.TongDiem<<endl;
		}
		Q = Q->next;
	}
}
//tim vi tri sau thi sinh co diem cao nhat dau tien
TRO Tim_TSmax(TRO &L){
	TRO Q = L;
	TRO T;
	while (Q != NULL && Q->infor.TongDiem==Tim_Tongmax(L)){
		Q = Q->next;
		T = Q->next;
	}
	return T;
}
//hien thi danh sach sau khi chen sau thi sinh diem cao nhat
void TSmax(TRO &L){
	TRO Q = L;
	TRO T = Tim_TSmax(L);
	TRO P;
	THISINH TS;
	cout<<"Nhap thong tin thi sinh can chen: "<<endl;
		NhapTS(TS);
			P = new (Node);
			P->infor = TS;
			P->next = Q->next;
			Q->next = P;
		cout<<"_____________________________ DANH SACH THI SINH ___________________________\n"<<endl;
		XuatDS(L);
}
//chen cuoi
void ChenCuoi(TRO &L){
	TRO Q = L;
	THISINH TS;
	cout<<"Nhap thong tin thi sinh can chen cuoi: "<<endl;
	NhapTS(TS);
	for (int i=1; i<Length(L); i++) Q = Q->next;
		TRO P = new (Node);
		P->infor = TS;
		P->next = Q->next;
		Q->next = P;
	cout<<"________________________ DANH SACH THI SINH DA CHEN CUOI _______________________\n"<<endl;
	XuatDS(L);
}
int main(){
	TRO L;
	cout<<"NHAP SO BAO DANH = '0' DE DUNG NHAP DANH SACH\n"<<endl;
	NhapDS(L);
	cout<<"_____________________________ DANH SACH THI SINH ___________________________\n"<<endl;
	XuatDS(L);
	XoaT3(L);
	KhoiA1(L);
	Tongmax(L);
	TSmax(L);
	ChenCuoi(L);
	
	return 0;
}


