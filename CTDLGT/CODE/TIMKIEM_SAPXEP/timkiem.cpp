#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

int taoMang(int a[], int n) {
	for (int i = 0; i < n; i++)
		a[i] = rand() % 60;
}

void inMang(int a[], int n) {
	for (int i = 0; i < n ; i++)
		cout << a[i] << " ";
}

int timKiemTuanTu(int a[], int n, int k) {
	for (int i = 0; i < n; i++)
		if (a[i] == k)
			return i;
	return -1;
}

void sapXepBoiBot(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}

int sapXepNhiPhan(int a[], int l, int r, int key) {
	// neu day rong
	if (r < l) return -1;
	// tim phan giua
	int m = (l + r) / 2;
	// return ket qua
	if (a[m] == key) return m;
	if (a[m] > key) {
		return sapXepNhiPhan(a, l, m - 1, key);
	} else {
		return sapXepNhiPhan(a, m + 1, r, key);
	}
}

int main() {
	int a[125];
	taoMang(a, 100);
//	inMang(a, 100);
	cout << "\ntim kiem tuan tu: " << timKiemTuanTu(a, 100, 52);
	sapXepBoiBot(a, 100);
//	inMang(a, 100);
	cout << "\ntim kiem nhi phan: " << sapXepNhiPhan(a, 0, 100, -1);
	return 0;
}

