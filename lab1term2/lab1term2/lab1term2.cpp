#include <iostream>
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
	void set(string _name, char _type, string _humidity, float _coefficient)
	{
		name = _name;
		type = _type;
		humidity = _humidity;
		coefficient = _coefficient;
	}
	string getName()
	{
		return name;
	}
	char getType()
	{
		return type;
	}
	string getHumidity()
	{
		return humidity;
	}
	float getCoefficient()
	{
		return coefficient;
	}
	void show()
	{
		cout << name << ": ";
		cout << type << ", ";
		cout << humidity << ", ";
		cout << coefficient << '\n';
	}
};
int main()
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Substance sub[3];
	bool empty = true;
	int ind = 0;
	for (;;) {
		cout << "1. Добавить запись с помощью set\n";
		cout << "2. Вывести базу с помощью get\n";
		cout << "3. Вывести базу с помощью show\n";
		cout << "4. Выход\n";
		cout << "> ";
		int p;
		cin >> p;
		switch (p) {
		case 1: {
			if (ind >= 3)
			{
				cout << "Массив полон!\n";
			}
			else
			{
				string a, c;
				char b;
				float d;
				cout << "Название, Тип, Влажность, Коэффициент:\n";
				cin >> a >> b >> c >> d;
				cin.ignore();
				sub[ind].set(a, b, c, d);
				empty = false;
				ind++;
			}
			break;
		}

		case 2: {
			if (empty) { cout << "В базе нет записей!\n"; }
			else
			{
				cout << sub[0].getName() << ": " << sub[0].getType() << ", " << sub[0].getHumidity() << ", " << sub[0].getCoefficient() << '\n';
				cout << sub[1].getName() << ": " << sub[1].getType() << ", " << sub[1].getHumidity() << ", " << sub[1].getCoefficient() << '\n';
				cout << sub[2].getName() << ": " << sub[2].getType() << ", " << sub[2].getHumidity() << ", " << sub[2].getCoefficient() << '\n';
				cout << '\n';
			}
			break;
		}

		case 3: {
			if (empty) { cout << "В базе нет записей!\n"; }
			else
			{
				sub[0].show();
				sub[1].show();
				sub[2].show();
			}
			break;
		}

		case 4: {
			return 0;
		}

		default: {
			cout << "Неверный вызов!\n";
			break;
		}
		}
	}
}