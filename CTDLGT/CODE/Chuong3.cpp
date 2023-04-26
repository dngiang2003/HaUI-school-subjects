#include<iostream>
using namespace std;

void selectSort(int a[],int n){
	int tmp;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				tmp=a[i];
				a[i]=a[j];
				a[j] = tmp;
			}
		}
	}
}

void bublesort(int a[], int n){
	int tmp;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
}

void insertsort(int a[], int n){
	int key,j;
	for(int i=1;i<n;i++){
		key=a[i];
		j=i-1;
		while(j>=0&&key<a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1] = key;	
	}
}

void hienthi(int a[],int n){
		for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}


int main(){
	int a[] = {15,7,56,10,-35,19};
	int n= 6;
	hienthi(a,n);
	insertsort(a,n);
	cout<<"\n--------------------\n";
	hienthi(a,n);
	

	
}
