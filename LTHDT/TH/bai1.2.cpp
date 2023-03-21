#include <bits/stdc++.h>
#include <math.h>
using namespace std;

class RECTANGLE {
	private:
		float width;
		float height;
	public:
		void enter();
		void draw();
		float acreage();
		float perimeter();
};

void RECTANGLE::enter() {
	cout << "Enter Width = ";		cin >> width;
	cout << "Enter Height = ";		cin >> height;
}

void RECTANGLE::draw() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || i == width - 1 || j == 0 || j == height - 1) {
				cout << " * ";
			} else {
				cout << "   ";
			}
		}
		cout << endl;
	}
}

float RECTANGLE::acreage() {
	return height * width;
}

float RECTANGLE::perimeter() {
	return (height + width) * 2;
}

int main() {
	RECTANGLE x;
	x.enter();
	x.draw();
	cout << setw(15) << "Acreage = " << setw(15) << round(x.acreage() * 1000) / 1000;
	cout << endl << setw(15) << "Perimeter = " << setw(15) << round(x.perimeter() * 1000) / 1000;
	return 0;
}

