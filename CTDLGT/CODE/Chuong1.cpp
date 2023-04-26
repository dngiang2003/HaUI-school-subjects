#include<iostream>
using namespace std;

int cau1(int n){
	if(n<=0){
		return 1;
	}
	return cau1(n-1)*2;
}

int cau2(int n){
	if(n<=0){
		return 0;
	}
	return cau2(n-1)+n;
}

float cau3(int n){
	if(n==0){
		return 0;
	}
	return n*cau3(n-1);
}

float cau4(int n){
	if(n<=2){
		return 2;
	}
	return cau4(n-2) + cau4(n-1);
}

int cau5(int n){
	if(n<10){
		return n+cau5(n+1);
	}
	
	return n*n;
}

int main(){
	cout<<"";
}

