#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <windows.h>

using namespace std;

class Substance
{
private:
	string name;
	char type;
	string humidity;
	float coefficient;
public:
	friend ostream& operator<< (ostream& out, Substance& sub);
	friend istream& operator>> (istream& in, Substance& sub);
	friend void head();
	friend void line();
	Substance() { coefficient = 0; name = ""; humidity = ""; }
	Substance(string&, char, string&, float&);
	void set(string&, char, string&, float&);
	void get(string&, char, string&, float&);
	void show();
	char getType() { return type; }
};
void line() {
	cout << "\n|----------------------------------------------|\n";
}
ostream& operator<< (ostream& out, Substance& sub)
{
	out << "| " << setw(10) << sub.name << "   |";
	out << setw(3) << sub.type << "  |";
	out << setw(8) << sub.humidity << "   |";
	out << setw(9) << sub.coefficient << "    |";
	line();
	return out;
}
istream& operator>> (istream& in, Substance& sub)
{
	in >> sub.name >> sub.type >> sub.humidity >> sub.coefficient;
	return in;
}
void head()
{
	cout << "________________________________________________\n";
	cout << "|                   Вещество                   |\n";
	cout << "|----------------------------------------------|\n";
	cout << "|   Название   | Тип | Влажность | Коэффициент |\n";
	cout << "|----------------------------------------------|\n";
}
Substance::Substance(string& a, char b, string& c, float& d) {
	name = a;
	type = b;
	humidity = c;
	coefficient = d;
}
void Substance::set(string& a, char b, string& c, float& d) {
	name = a;
	type = b;
	humidity = c;
	coefficient = d;
}
void Substance::get(string& a, char b, string& c, float& d) {
	a = name;
	b = type;
	c = humidity;
	d = coefficient;
}
void Substance::show() {
	cout << name << " ";
	cout << type << " ";
	cout << humidity << " ";
	cout << coefficient << " ";
}
class Table
{
private:
	Substance* sub[10];
	int col;
	bool sorted;
public:
	Table() { col = 0; sorted; }
	~Table() { if (col) for (int i = 0; i < col; i++) delete sub[i]; }
	void add_rec(string&, char, string&, float&);
	void del_rec();
	void sort_Table();
	friend ostream& operator<<(ostream&, Table&);
};
void Table::add_rec(string& a, char b, string& c, float& d) {
	if (col >= 10) return;
	else col++;
	sub[col - 1] = new Substance(a, b, c, d);
	sorted = 0;
}
void Table::del_rec() {
	if (col <= 0) return;
	delete  sub[col - 1];
	col--;
}
void Table::sort_Table() {
	if (col < 2) return;
	for (int i = 0; i < col; i++)
		for (int j = i + 1; j < col; j++) {
			if (sub[i]->getType() > sub[j]->getType()) {
				swap(sub[i], sub[j]);
			}
		}
	sorted = 1;
}
ostream& operator<<(ostream& stream, Table& temp) {
	if (temp.sorted == 0) stream << "Таблица не отсортирована.\n";
	else stream << "Таблица отсортирована.\n";
	head();
	if (!temp.col) stream << "Таблица пуста.";
	else {
		for (int i = 0; i < temp.col; i++) {
			stream << *temp.sub[i];
		}
	}
	return stream;
}
int main() {
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string a;
	char b;
	string c;
	float d;
	Table* temp = new Table();

	for (;;) {
		cout << "1. Добавить запись\n";
		cout << "2. Удалить запись\n";
		cout << "3. Сортировать базу\n";
		cout << "4. Вывести базу\n";
		cout << "5. Выход\n";
		cout << "> ";
		int p;
		cin >> p;
		switch (p) {
		case 1: {
			cout << "Название, Тип, Влажность, Коэффициент:\n";
			cin >> a >> b >> c >> d;
			temp->add_rec(a, b, c, d);
			break;
		}

		case 2: {
			temp->del_rec();
			break;
		}

		case 3: {
			temp->sort_Table();
			break;
		}

		case 4: {
			cout << *temp;
			cout << "\nНажмите клавишу для продолжения...";
			break;
		}

		case 5: {
			return 0;
		}

		default: {
			cout << "Неверный вызов";
			break;
		}
		}
	}
}