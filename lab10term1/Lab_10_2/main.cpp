#include "methods.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	SUM b(5, 7), c;
	SUM* bb, * cc;
	int a1, a2;
	bb = &b;
	bb->sum();
	bb->print();
	b.NUL();
	cout << endl;
	cc = &c;

	cout << "Введите два числа" << endl;
	cin >> a1 >> a2;
	c.set(a1, a2);
	c.print();
	c.sum();
	c.print();
	c.NUL();
	return 0;
}