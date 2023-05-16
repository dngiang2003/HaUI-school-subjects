#include <bits/stdc++.h>
using namespace std;

int mu2(int n) {
	if (n == 0) {
		return 1;
	} else {
		return 2 * mu2(n - 1);
	}
}

int tongscs(int n) {
	if (n < 10) {
		return n;
	} else {
		return (n % 10) + tongscs(n / 10);
	}
}

int demscs(int n) {
	if (abs(n) < 10) return 1;
	return 1 + demscs(n / 10);
}

int f(int n) {
	if (n == 0) {
		return 0;
	} else {
		return n * f(n - 1);
	}
}

int f2(int n) {
	if (n <= 2) {
		return 2;
	} else {
		return f2(n - 2) + f2(n - 1);
	}
}

int fa2(int n) {
	if(n >= 10) {
		return n * n;
	} else {
		return n + fa2(n + 1);
	}
}


int main() {
	cout << mu2(5) << endl;
	cout << tongscs(123) << endl;
	cout << demscs(123456) << endl;
	cout << f(5) << endl;
	cout << f2(6) << endl;
	cout << fa2(2);
	return 0;
}

