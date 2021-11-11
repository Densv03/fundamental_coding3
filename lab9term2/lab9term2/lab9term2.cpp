#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <windows.h>

using namespace std;

class Person
{
private:
	string name;
	int age;
public:
	Person()
	{
		name = "";
		age = 0;
	}
	Person(string str)
	{
		name = str;
		age = 0;
	}
	Person(int i)
	{
		name = "";
		age = i;
	}
	void set_name(string _name)
	{
		name = _name;
	}
	void set_age(int _age)
	{
		age = _age;
	}
	string get_name()
	{
		return name;
	}
	int get_age()
	{
		return age;
	}
	void operator< (Person per)
	{
		if (name > per.name)
		{
			Person* temp;
			temp = this;
			name = per.name;
			age = per.age;
			per.name = temp->name;
			per.age = temp->age;
		}
	}
	void operator() (Person per)
	{
		if (age > per.age)
		{
			Person* temp;
			temp = this;
			name = per.name;
			age = per.age;
			per.name = temp->name;
			per.age = temp->age;
		}
	}
};

class Staff
{
private:
	map<int, Person> function;
	map<int, Person> functor;
	int index1;
	int index2;
public:
	Staff()
	{
		index1 = 0;
		index2 = 0;
	}
	void input_function()
	{
		map<int, Person> temp;
		int index = 0;
		int n;
		cout << "Введите размер массива #1: ";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "Имя, возраст:\n";
			string _name;
			int _age;
			cin >> _name >> _age;
			temp[index].set_name(_name);
			temp[index].set_age(_age);
			index++;
		}
		function = temp;
		index1 = index;
	}
	void input_functor()
	{
		map<int, Person> temp;
		int index = 0;
		int n;
		cout << "Введите размер массива #2: ";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "Имя, возраст:\n";
			string _name;
			int _age;
			cin >> _name >> _age;
			temp[index].set_name(_name);
			temp[index].set_age(_age);
			index++;
		}
		functor = temp;
		index2 = index;
	}
	void print_all_function()
	{
		for (int i = 0; i < index1; i++)
		{
			cout << "Имя: " << function[i].get_name() << "\tВозраст: " << function[i].get_age() << '\n';
		}
		cout << '\n';
	}
	void print_all_functor()
	{
		for (int i = 0; i < index2; i++)
		{
			cout << "Имя: " << functor[i].get_name() << "\tВозраст: " << functor[i].get_age() << '\n';
		}
		cout << '\n';
	}
	void print_name_function()
	{
		for (int i = 0; i < index1; i++)
		{
			cout << "Имя: " << function[i].get_name() << '\n';
		}
		cout << '\n';
	}
	void print_name_functor()
	{
		for (int i = 0; i < index2; i++)
		{
			cout << "Имя: " << functor[i].get_name() << '\n';
		}
		cout << '\n';
	}
	void print_age_function()
	{
		for (int i = 0; i < index1; i++)
		{
			cout << "Возраст: " << function[i].get_age() << '\n';
		}
		cout << '\n';
	}
	void print_age_functor()
	{
		for (int i = 0; i < index2; i++)
		{
			cout << "Возраст: " << functor[i].get_age() << '\n';
		}
		cout << '\n';
	}
	void remove_function(string _name)
	{
		for (int i = 0; i < index1; i++)
		{
			if (function[i].get_name() == _name)
			{
				for (int j = i + 1; j < index1; j++)
				{
					function[j - 1].set_name(function[j].get_name());
					function[j - 1].set_age(function[j].get_age());
				}
				function[index1 - 1].set_name("");
				function[index1 - 1].set_age(0);
				index1--;
				break;
			}
		}
	}
	void remove_functor(string _name)
	{
		for (int i = 0; i < index2; i++)
		{
			if (functor[i].get_name() == _name)
			{
				for (int j = i + 1; j < index2; j++)
				{
					functor[j - 1].set_name(functor[j].get_name());
					functor[j - 1].set_age(functor[j].get_age());
				}
				functor[index2 - 1].set_name("");
				functor[index2 - 1].set_age(0);
				index2--;
				break;
			}
		}
	}
	void insert_function(string _name, int _age)
	{
		function[index1].set_name(_name);
		function[index1].set_age(_age);
		index1++;
	}
	void insert_functor(string _name, int _age)
	{
		functor[index2].set_name(_name);
		functor[index2].set_age(_age);
		index2++;
	}
	void find_name_function(string _name)
	{
		for (int i = 0; i < index1; i++)
		{
			if (function[i].get_name() == _name)
			{
				cout << "Имя: " << function[i].get_name() << "\tВозраст: " << function[i].get_age() << '\n';
			}
		}
		cout << '\n';
	}
	void find_name_functor(string _name)
	{
		for (int i = 0; i < index2; i++)
		{
			if (functor[i].get_name() == _name)
			{
				cout << "Имя: " << functor[i].get_name() << "\tВозраст: " << functor[i].get_age() << '\n';
			}
		}
		cout << '\n';
	}
	void find_age_function(int _age)
	{
		for (int i = 0; i < index1; i++)
		{
			if (function[i].get_age() == _age)
			{
				cout << "Имя: " << function[i].get_name() << "\tВозраст: " << function[i].get_age() << '\n';
			}
		}
		cout << '\n';
	}
	void find_age_functor(int _age)
	{
		for (int i = 0; i < index2; i++)
		{
			if (functor[i].get_age() == _age)
			{
				cout << "Имя: " << functor[i].get_name() << "\tВозраст: " << functor[i].get_age() << '\n';
			}
		}
		cout << '\n';
	}
	void sort_function()
	{
		for (int i = 0; i < index1 - 1; i++)
			for (int j = 0; j < index1 - i - 1; j++)
				function[j] < function[j + 1];
	}
	void sort_functor()
	{
		for (int i = 0; i < index2 - 1; i++)
			for (int j = 0; j < index2 - i - 1; j++)
				functor[j](functor[j + 1]);
	}
	int get_index1()
	{
		return index1;
	}
	int get_index2()
	{
		return index2;
	}
};

int main()
{
	setlocale(LC_ALL, "russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Staff staff;
	int p;
	bool empty1 = true;
	bool empty2 = true;

	for (;;) {
		cout << "1. Заполнить первый контейнер с нуля\n";
		cout << "2. Заполнить второй контейнер с нуля\n";
		cout << "3. Вывести первый контейнер\n";
		cout << "4. Вывести второй контейнер\n";
		cout << "5. Вывести имена из первого контейнера\n";
		cout << "6. Вывести имена из второго контейнера\n";
		cout << "7. Вывести возрасты из первого контейнера\n";
		cout << "8. Вывести возрасты из второго контейнера\n";
		cout << "9. Удалить запись по имени из первого контейнера\n";
		cout << "10. Удалить запись по имени из второго контейнера\n";
		cout << "11. Добавить запись в первый контейнер\n";
		cout << "12. Добавить запись во второй контейнер\n";
		cout << "13. Найти все записи по имени из первого контейнера\n";
		cout << "14. Найти все записи по возрасту из первого контейнера\n";
		cout << "15. Найти все записи по имени из второго контейнера\n";
		cout << "16. Найти все записи по возрасту из второго контейнера\n";
		cout << "17. Сортировать первый контейнер\n";
		cout << "18. Сортировать второй контейнер\n";
		cout << "19. Выход\n";
		cout << "> ";
		cin >> p;
		switch (p) {
		case 1: {
			staff.input_function();
			empty1 = false;
			break;
		}

		case 2: {
			staff.input_functor();
			empty2 = false;
			break;
		}

		case 3: {
			if (empty1)
			{
				cout << "Контейнер пуст!\n";
			}
			else
			{
				staff.print_all_function();
			}
			break;
		}

		case 4: {
			if (empty2)
			{
				cout << "Контейнер пуст!\n";
			}
			else
			{
				staff.print_all_functor();
			}
			break;
		}

		case 5: {
			if (empty1)
			{
				cout << "Контейнер пуст!\n";
			}
			else
			{
				staff.print_name_function();
			}
			break;
		}

		case 6: {
			if (empty2)
			{
				cout << "Контейнер пуст!\n";
			}
			else
			{
				staff.print_name_functor();
			}
			break;
		}

		case 7: {
			if (empty1)
			{
				cout << "Контейнер пуст!\n";
			}
			else
			{
				staff.print_age_function();
			}
			break;
		}

		case 8: {
			if (empty2)
			{
				cout << "Контейнер пуст!\n";
			}
			else
			{
				staff.print_age_functor();
			}
			break;
		}

		case 9: {
			if (empty1)
			{
				cout << "Контейнер пуст!\n";
			}
			else
			{
				cout << "Введите имя, по которому будет удалена запись: ";
				string str;
				cin >> str;
				staff.remove_function(str);
				if (staff.get_index1() == 0) empty1 = true;
			}
			break;
		}

		case 10: {
			if (empty2)
			{
				cout << "Контейнер пуст!\n";
			}
			else
			{
				cout << "Введите имя, по которому будет удалена запись: ";
				string str;
				cin >> str;
				staff.remove_functor(str);
				if (staff.get_index2() == 0) empty2 = true;
			}
			break;
		}

		case 11: {
			cout << "Имя, возраст: ";
			string str;
			int i;
			cin >> str >> i;
			staff.insert_function(str, i);
			empty1 = false;
			break;
		}

		case 12: {
			cout << "Имя, возраст: ";
			string str;
			int i;
			cin >> str >> i;
			staff.insert_functor(str, i);
			empty2 = false;
			break;
		}

		case 13: {
			if (empty1)
			{
				cout << "Контейнер пуст!\n";
			}
			else
			{
				cout << "Введите имя, по которому будут найдены записи: ";
				string str;
				cin >> str;
				staff.find_name_function(str);
			}
			break;
		}

		case 14: {
			if (empty1)
			{
				cout << "Контейнер пуст!\n";
			}
			else
			{
				cout << "Введите возраст, по которому будут найдены записи: ";
				int i;
				cin >> i;
				staff.find_age_function(i);
			}
			break;
		}

		case 15: {
			if (empty2)
			{
				cout << "Контейнер пуст!\n";
			}
			else
			{
				cout << "Введите имя, по которому будут найдены записи: ";
				string str;
				cin >> str;
				staff.find_name_functor(str);
			}
			break;
		}

		case 16: {
			if (empty2)
			{
				cout << "Контейнер пуст!\n";
			}
			else
			{
				cout << "Введите возраст, по которому будут найдены записи: ";
				int i;
				cin >> i;
				staff.find_age_functor(i);
			}
			break;
		}

		case 17: {
			if (empty2)
			{
				cout << "Контейнер пуст!\n";
			}
			else
			{
				staff.sort_functor();
			}
			break;
		}

		case 18: {
			if (empty2)
			{
				cout << "Контейнер пуст!\n";
			}
			else
			{
				staff.sort_functor();
			}
			break;
		}

		case 19: {
			return 0;
		}
		default: {
			cout << "Неверный вызов!\n";
			break;
		}
		}
	}
}