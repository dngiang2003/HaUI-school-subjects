#include<iostream>
#include<cstring>
#include<string.h>
#include<stdio.h>
using namespace std;

struct SinhVien{
	char SBD[20];
	char hoten[30];
	int namsinh;
	char khoithi[10];
	float tongdiem;
};

void nhapsinhvien(SinhVien &sv){
	cout<<"nhap SBD: ";
	fflush(stdin);
	gets(sv.SBD);
	
	cout<<"nhap ho ten: ";
	fflush(stdin);
	gets(sv.hoten);
	
	cout<<"nhap nam sinh: ";
	cin>>sv.namsinh;
	
	cout<<"nhap khoi thi: ";
	fflush(stdin);
	gets(sv.khoithi);
	
	cout<<"nhap tong diem: ";
	cin>>sv.tongdiem;
	
};

void hienthisv(SinhVien sv){
	cout<<"\nSBD: "<<sv.SBD;
	cout<<" \nho ten: "<<sv.hoten;
	cout<<" \nnam sinh: "<<sv.namsinh;
	cout<<" \nkhoi thi: "<<sv.khoithi;
	cout<<" \ntong diem: "<<sv.tongdiem;
	cout<<"\n---------------------\n";
}

struct Node{
	SinhVien data;
	Node *next;
};

typedef Node *TRO;

TRO khoitaonode(SinhVien sv){
	TRO n = new Node();
	n->data = sv;
	n->next = NULL;
	return n;
}

void khoitaoList(TRO &L){
	L=NULL;
}

void nhap(TRO &L){
	int i=0;
	TRO Q=L;
	if(L!=NULL){
		while(Q->next!=NULL){
			Q=Q->next;
		}
	}
	do{
		cout<<"\nnhap lan thu "<<++i<<endl;
		SinhVien sv;
		nhapsinhvien(sv);
		TRO T = khoitaonode(sv);
		if(L==NULL){
			L=T;
			Q=L;
		}else{
			Q->next = T;
			Q=T;
		}
		int is;
		cout<<"\n ban co muon tiep tuc khong y:1 n:0 ";
		cin>>is;
		if(is!=1){
			break;
		}
	}while(true);
}

void xoavithithu3(TRO &L){
	TRO Q,X=L;
	if(L==NULL){
		cout<<"L rong!";
		return;
	}
	int i=1;
	while(X->next != NULL){
		i++;
		X=X->next;
	}
	if(i<=2){
		cout<<"\nkhong du phan tu!";
		return;
	}
	i=1;
	X=L;
	while(++i<=3){
		Q=X;
		X=X->next;
	}
	Q->next = X->next;
	delete X;
}

void duarathongtinA1(TRO L){
	while(L!=NULL){
		if(strcmp(L->data.khoithi,"A1")==0){
			hienthisv(L->data);
		}
		L=L->next;
	}
}


void duarathongtindiemmax(TRO L){
	if(L==NULL){
		return;
	}
	TRO Q=L;
	float diem = L->data.tongdiem;
	while(Q!=NULL){
		if(Q->data.tongdiem>diem){
			diem = Q->data.tongdiem;
		}
		Q=Q->next;
	}
	
	while(L!=NULL){
		if(L->data.tongdiem=diem){
			hienthisv(L->data);
		}
		L=L->next;
	}

}

void insertbeforMax(TRO &L){
	TRO Q=L,P;
	SinhVien sv;
	
	float max = L->data.tongdiem;
	while(Q!=NULL){
		if(Q->data.tongdiem>max){
			max = Q->data.tongdiem;
		}
		Q=Q->next;
	}
	Q=L;
	while(Q!=NULL){
		if(L->data.tongdiem==max){
			cout<<"\nnhap sinh vien muon chen: ";
			nhapsinhvien(sv);
			TRO T = khoitaonode(sv);
			T->next = L;
			L=T;
			P=Q;
			Q=Q->next;
			continue;
		}
		if(Q->data.tongdiem == max){
			cout<<"\nnhap sinh vien muon chen: ";
			nhapsinhvien(sv);
			TRO T = khoitaonode(sv);
			T->next=Q;
			P->next=T;
			P=Q;
			Q=Q->next;
			continue;
		}
		P=Q;
		Q=Q->next;
	}
}


void hienthidanhsach(TRO L){
	cout<<"\ndanh sach sinh vien la: \n";
	while(L!=NULL){
		hienthisv(L->data);
		L=L->next;
	}
}


int main(){
	cout<<"success!";
	TRO L;
	khoitaoList(L);
	nhap(L);
	hienthidanhsach(L);
	insertbeforMax(L);
	hienthidanhsach(L);
}

