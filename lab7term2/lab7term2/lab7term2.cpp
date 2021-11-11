#include<iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <vector>

using namespace std;

class Substance
{
private:
	string name;
	char type;
	string humidity;
	float coefficient;
public:
	Substance()
	{
		name = "";
		type = ' ';
		humidity = "";
		coefficient = 0;
	}
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
		cout << coefficient;
	}
};

vector<string> files;

class SubArray
{
private:
	Substance sub[3];
public:
	string getSubName(int i)
	{
		return sub[i].getName();
	}
	void setSub(Substance tempSub, int i)
	{
		sub[i].set(tempSub.getName(), tempSub.getType(), tempSub.getHumidity(), tempSub.getCoefficient());
	}
	void Remove(int ind)
	{
		sub[ind].set("", ' ', "", 0);
	}
	void Input(int ind)
	{
		if (ind >= 3)
		{
			cout << "Неверный индекс!\n";
		}
		else
		{
			string a, c;
			char b;
			float d;
			cout << "Название, Тип, Влажность, Коэффициент:\n";
			cin >> a >> b >> c >> d;
			sub[ind].set(a, b, c, d);
		}
	}
	void Print()
	{
		cout << "________________________________________________\n";
		cout << "|                   Вещество                   |\n";
		cout << "|----------------------------------------------|\n";
		cout << "|   Название   | Тип | Влажность | Коэффициент |\n";
		cout << "|----------------------------------------------|\n";
		for (int i = 0; i < 3; i++)
		{
			cout << "| " << setw(10) << sub[i].getName() << "   |";
			cout << setw(3) << sub[i].getType() << "  |";
			cout << setw(8) << sub[i].getHumidity() << "   |";
			cout << setw(9) << sub[i].getCoefficient() << "    |";
			cout << "\n|----------------------------------------------|\n";
		}
	}
	void writeToFile(string filename, int i)
	{
		bool used = false;
		for (int i = 0; i < files.size(); i++)
		{
			if (files[i] == filename)
			{
				used = true;
				break;
			}
		}
		if (!used)
		{
			ofstream use;
			use.open(filename, ios::trunc);
			use.close();
			files.push_back(filename);
		}
		ofstream file;
		file.open(filename, fstream::app);
		file << '\n' << i << ' ';
		file << sub[i].getName() << ' ';
		file << sub[i].getType() << ' ';
		file << sub[i].getHumidity() << ' ';
		file << sub[i].getCoefficient() << ' ' << ' ';
		sub[i].set("", ' ', "", 0);
		file.close();
	}
	void readFromFile(string filename, int num)
	{
		Substance temp;
		ifstream in(filename, ios::in);
		ofstream out("buff.txt", ios::out);
		char buffer[256];
		memset(buffer, 0, sizeof(buffer));
		while (!in.eof())
		{
			in.getline(buffer, 255);
			if ((int(buffer[0]) - '0') == num)
			{
				char newTemp[256];
				memset(newTemp, 0, sizeof(newTemp));
				int ind = 0, ind2 = 1;
				bool space = false;
				string a, c;
				char b;
				float d;
				for (int k = 2; k < 256; k++)
				{
					if (buffer[k] != ' ')
					{
						space = false;
						newTemp[ind] = buffer[k];
						ind++;
					}
					else
					{
						if (space)
						{
							break;
						}
						space = true;
						if (ind2 == 1) { a = string(newTemp); cout << a << " "; }
						if (ind2 == 2) { b = newTemp[0]; cout << b << " "; }
						if (ind2 == 3) { c = string(newTemp); cout << c << " "; }
						if (ind2 == 4) { d = atoi(newTemp); cout << d << '\n'; }
						ind2++;
						ind = 0;
					}
				}
				temp.set(a, b, c, d);
				break;
			}
			out << buffer << endl;
		}
		while (!in.eof()) {
			in.getline(buffer, 255);
			out << buffer << endl;
		}
		out.close();
		in.close();
		remove(filename.c_str());
		rename("buff.txt", filename.c_str());
		setSub(temp, num);
	}
};
int main()
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SubArray arr;
	string a, d;
	float b, c;
	int p;
	bool empty = true;
	int ind = 0;

	for (;;) {
		cout << "1. Добавить записи\n";
		cout << "2. Удалить запись\n";
		cout << "3. Вывести базу\n";
		cout << "4. Поместить запись в файл\n";
		cout << "5. Взять запись из файла\n";
		cout << "6. Выход\n";
		cout << "> ";
		cin >> p;
		switch (p) {
		case 1: {
			if (ind >= 3)
			{
				cout << "Массив полон!\n";
			}
			else
			{
				int i;
				cout << "Введите индекс: ";
				cin >> i;
				if (i < 0 || i > 2)
				{
					cout << "Неверный индекс\n";
				}
				if (arr.getSubName(i) != "")
				{
					cout << "По этому индексу уже существуют данные в массиве!";
				}
				else
				{
					arr.Input(i);
					ind++;
				}
			}
			break;
		}

		case 2: {
			if (ind <= 0)
			{
				cout << "В массиве нет данных!\n";
			}
			else
			{
				int i;
				cout << "Введите индекс: ";
				cin >> i;
				if (i < 0 || i > 2)
				{
					cout << "Неверный индекс\n";
				}
				if (arr.getSubName(i) == "")
				{
					cout << "По этому индексу не существует данных в массиве!";
				}
				else
				{
					arr.Remove(i);
					ind--;
				}
			}
			break;
		}

		case 3: {
			if (ind <= 0) { cout << "В массиве нет данных!\n"; }
			else arr.Print();
			break;
		}

		case 4: {
			if (ind <= 0)
			{
				cout << "В массиве нет данных!\n";
			}
			else
			{
				int i;
				cout << "Введите индекс: ";
				cin >> i;
				if (i < 0 || i > 2)
				{
					cout << "Неверный индекс\n";
				}
				if (arr.getSubName(i) == "")
				{
					cout << "По этому индексу не существует данных в массиве!";
				}
				else
				{
					arr.writeToFile("file.txt", i);
					ind--;
				}
			}
			break;
		}

		case 5: {
			if (ind >= 3)
			{
				cout << "Массив полон!\n";
			}
			else
			{
				int i;
				cout << "Введите индекс: ";
				cin >> i;
				if (i < 0 || i > 2)
				{
					cout << "Неверный индекс\n";
				}
				if (arr.getSubName(i) != "")
				{
					cout << "По этому индексу уже существуют данные в массиве!";
				}
				else
				{
					arr.readFromFile("file.txt", i);
					ind++;
				}
			}
			break;
		}

		case(6):
		{
			return 0;
		}

		default: {
			cout << "Неверный вызов!\n";
			break;
		}
		}
	}
}