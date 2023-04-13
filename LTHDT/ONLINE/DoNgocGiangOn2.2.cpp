#include <bits/stdc++.h>
using namespace std;

class FACULTY;
class STUDENT;
class SCHOOL {
	private:
		char NameS[30];
		char DateS[15];
	friend class FACULTY;
	friend class STUDENT;
	friend void bonus1(STUDENT &z);
};

class FACULTY {
	private:
		char NameF[30];
		char DateF[15];
		SCHOOL x;
	public:
		void input();
		void output();
	friend class STUDENT;
	friend void bonus1(STUDENT &z);
};

void FACULTY::input() {
	cout << "Name faculty: ";             fflush(stdin);  gets(NameF);
	cout << "Faculty founding date: ";    fflush(stdin);  gets(DateF);
	cout << "Name school: ";              fflush(stdin);  gets(x.NameS);
	cout << "School founding date: ";     fflush(stdin);  gets(x.DateS);
}

void FACULTY::output() {
	cout << "Name faculty: " << NameF << endl;
	cout << "Faculty founding date: " << DateF << endl;
	cout << "Name school: " << x.NameS << endl;
	cout << "School founding date: " << x.DateS << endl;
}

class PERSON {
	protected:
		char NameP[30];
		char Birth[15];
		char Address[30];
	public:
		void input();
		void output();
		PERSON();
};

void PERSON::input() {
	cout << "Name preson: ";         fflush(stdin);   gets(NameP);
	cout << "Date of birth: ";       fflush(stdin);   gets(Birth);
	cout << "Address of preson: ";   fflush(stdin);   gets(Address);
}

void PERSON::output() {
	cout << "Name preson: " << NameP << endl;
	cout << "Date of birth: " << Birth << endl;
	cout << "Address of person: " << Address << endl;
}

PERSON::PERSON() {
	strcpy(NameP, "Trieu Dang Tuan");
	strcpy(Birth, "22/07/2003");
	strcpy(Address, "Vu Ban, Nam Dinh, Viet Nam");
}

class STUDENT: public PERSON {
	private:
		FACULTY y;
		char Class[10];
		float Score;
	public:
		void input();
		void output();
		STUDENT();
	friend void bonus1(STUDENT &z);
};

void STUDENT::input() {
	PERSON::input();
	y.input();
	cout << "Class of student: ";   fflush(stdin);   gets(Class);
	cout << "Score of student: "; 					 cin >> Score;
}

void STUDENT::output() {
	PERSON::output();
	y.output();
	cout << "Class of student: " << Class << endl;
	cout << "Score of student: " << Score << endl;
}

STUDENT::STUDENT() {
	PERSON();
	strcpy(y.NameF, "Information Technology");
	strcpy(y.DateF, "05/07/1999");
	strcpy(y.x.NameS, "HaNoi University of Industry");
	strcpy(y.x.DateS, "15/10/1956");
	strcpy(Class, "IT07");
	Score = 8.8;
}

void bonus1(STUDENT &z) {
	// sua thong tin truong thanh DHCNHN
	strcpy(z.y.x.NameS, "DHCNHN");
	cout << "\nSuccessful school name change!\n";
}

int main() {
	STUDENT z;
	z.input();
	cout << "\nInfo student after enter:\n\n";
	z.output();
	bonus1(z);
	cout << "\nStudent after change school name: \n\n";
	z.output();
	return 0;
}
/* test case
Trieu Dang Tuan
22/07/2003
Vu Ban, Nam Dinh, Viet Nam
Information Technology
05/07/1999
HaNoi University of Industry
15/10/1956
IT07
8.8
*/
