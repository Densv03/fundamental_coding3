#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
class B1 {
	int a;
public:
	B1() { a = 0; };
	B1(int x) { a = x; }
	void show_B1() { cout << "B1 =  " << a << "\n"; }
};

class B2 {
	int b;
public:
	B2() { b = 0; };
	B2(int x) { b = x; }
	void show_B2() { cout << "B2 =  " << b << "\n"; }
};

class D1 : public B1, protected B2 {
	int c;
public:
	D1() : B1(), B2() { c = 0; }
	D1(int x, int y, int z) : B1(y), B2(z) { c = x; };
	void show_D1() { cout << "D1 =  " << c << "\n"; show_B1(); show_B2(); }
};

class D2 : protected D1 {
	int d;
public:
	D2() : D1() { d = 0; }
	D2(int x, int y, int z, int i) : D1(y, z, i) { d = x; };
	void show_D2() { cout << "D2 =  " << d << "\n"; show_D1(); }
};

class D3 : private D2 {
	int e;
public:
	D3() : D2() { e = 0; }
	D3(int x, int y, int z, int i, int j) : D2(y, z, i, j) { e = x; }
	void show_D3() { cout << "D3 =  " << e << "\n"; show_D2(); }
};

class D4 : public D2 {
	int f;
public:
	D4() : D2() { f = 0; }
	D4(int x, int y, int z, int i, int j) : D2(y, z, i, j) { f = x; }
	void show_D4() { cout << "D4 =  " << f << "\n"; show_D2(); }
};

int main()
{
	setlocale(LC_ALL, "russian");
	D3 temp(10, 20, 30, 40, 50);
	D4 temp1(1, 2, 3, 4, 5);
	cout << "D3 temp(100,200,300,400,500);\n";
	cout << "D4 temp1(1,2,3,4,5);\n";
	cout << "\nСледуя иерархии класса D3: \n";
	temp.show_D3();
	cout << "\nСледуя иерархии класса D4\n";
	temp1.show_D4();
}