#include<iostream>
#include<cstring>
using namespace std;

struct HocPhan{
	char Mahp[20];
	char TenHp[30];
	float sotc;
};

void nhapHP(HocPhan &hp){
	cout<<"moi ban nhap MaHp: ";
	fflush(stdin);
	gets(hp.Mahp);
	
	cout<<"moi ban nhap TenHP: ";
	fflush(stdin);
	gets(hp.TenHp);
	
	cout<<"moi ban nhap sotc: ";
	cin>>hp.sotc;
}

void hienthi(HocPhan hp){
	cout<<"\nMaHp: "<<hp.Mahp;
	cout<<"\nTenHP: "<<hp.TenHp;
	cout<<"\nsotc: "<<hp.sotc;
	cout<<"\n-----------------------\n";
}

struct Node{
	HocPhan data;
	Node *next;
};

typedef Node *TRO;

TRO khoitaoNode(HocPhan hp){
	TRO n = new Node();
	n->data = hp;
	n->next = NULL;
	return n;
}



void khoitao(TRO &L){
	L=NULL;
}



bool isEmpty(TRO L){
	return L==NULL;
}

void nhapdanhsach(int n,TRO &L){
	TRO Q;
	int i=1;
	HocPhan p;
	if(!isEmpty(L)){
		Q=L;
		while(Q->next!=NULL){
			Q=Q->next;
		}
	}
	do{
		
		nhapHP(p);
		TRO X = khoitaoNode(p);
		if(isEmpty(L)){
			L=X;
			Q=L;
		}
		Q->next = X;
		Q=X;
	}while(++i<=n);
	
}

void chen3(TRO &L){
	int i = 1;
	TRO Q = L;
	while(Q!=NULL){
		i++;
		Q=Q->next;
	}
	
	if(i<2){
		cout<<"danh sach it hon 2 phan tu!";
		return;
	}
	
	if(i==2){
		HocPhan hp ;
		cout<<"\nnhap hoc phhan muon chen! \n";
		nhapHP(hp);
		TRO C = khoitaoNode(hp);
		Q->next = C;
		return;
	}
	
	HocPhan hp ;
	cout<<"\nnhap hoc phhan muon chen! \n";
	nhapHP(hp);
	TRO C = khoitaoNode(hp);
	i=1;
	Q=L;
	while(++i<3){
		Q=Q->next;
	}
	C->next = Q->next;
	Q->next = C;	
}

void hienthiL(TRO L){
	while(L!=NULL){
		hienthi(L->data);
		L=L->next;
	}
}
void chendautien(TRO &L){
	HocPhan p;
	nhapHP(p);
	TRO Q = khoitaoNode(p);
	if(isEmpty(L)){
		L=Q;
	}else{
		Q->next = L;
		L=Q;
	}
}

void deletehocphan(TRO &L){
	float mintc = L->data.sotc;
	TRO Q=L;
	TRO T;
	while(Q!=NULL){
		if(Q->data.sotc<mintc){
			mintc = Q->data.sotc;
		}
		Q=Q->next;
	}
	//mintc = so tc nho nhat trong day;
	Q=L;
	while(Q!=NULL){
		int x=1;
		cout<<"\n lan: "<<x<<endl;
		if(L->data.sotc==mintc){
			TRO X = L;
			L=L->next;
			Q=L;
			delete X;
			continue;
		}
		if(Q->data.sotc == mintc){
			TRO X = Q;
			Q=Q->next;
			T->next = Q;
			delete X;
			continue;
		}
		T=Q;
		Q=Q->next;
	}
}

void deletehp123(TRO &L){
	
}

int main(){
TRO L;
khoitao(L);
nhapdanhsach(5,L);
hienthiL(L);
deletehocphan(L);
hienthiL(L);


	
}



