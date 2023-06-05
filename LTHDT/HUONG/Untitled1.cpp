#include<bits/stdc++.h>
using namespace std;
#define PI  3.14
class HinhTron{
	private:
		float R;
	public:
		HinhTron();
		HinhTron(float x);
		float operator*();
		friend ostream&operator<<(ostream&x, HinhTron y);
		float operator+(HinhTron y);
};

HinhTron::HinhTron(){
	R = 0;
}

HinhTron::HinhTron(float x){
	R = x;
}

float HinhTron::operator*(){
	float S;
	S = R*R*PI;
	return S;
}
ostream&operator<<(ostream&x, HinhTron y){
	x<<"R = "<<y.R<<endl;
	x<<"S = "<<*y<<endl;
	return x;
}

float HinhTron::operator+(HinhTron y){
	float S ;
	S = **this + *y;
	return S;
}
int main(){
	HinhTron P(1.5), Q(2.4);
	cout<<P<<endl;
	cout<<Q<<endl;
	float T = P + Q;
	cout<<"Tong: "<<T<<endl;
	
	ofstream f("HinhTron.txt");
	f<<P<<endl;
	f<<Q<<endl;
	f<<"Tong: "<<T<<endl;
return 0;
}
