#include "viscosity.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));
	int a = 0;

	string name;
	int num;
	int temperature;
	int viscosity;

	cout << "Заполнить таблицу вручную - введите 1\n";
	cout << "Заполнить таблицу случайным образом - введите 2\n";
	cin >> a;
	elements A[S];
	switch (a) {

	case 1:
		cout << "Имя, атомный номер, температуру, вязкость\n";
		for (int i = 0; i < S; i++)
		{
			cout << "---------------------\n";
			cin >> name;
			cin >> num;
			cin >> temperature;
			cin >> viscosity;
			A[i].setter(name, num, temperature, viscosity);
		}
		break;

	case 2:
		for (int i = 0; i < S; i++)
		{
			A[i].random();
		}

	default:
		cout << "Неверное число" << endl;
		break;
	}
	system("cls");

	printf("------------------------------------------------------------------\n");
	printf("|Вязкость металлов в жидком состоянии                            |\n");
	printf("|----------------------------------------------------------------|\n");
	printf("| Вещество     |  Атомный номер   |  Температура |  Вязкость     |\n");
	printf("|              |                  |  (град.С)    |  (кг/м*сек)   |\n");
	printf("|--------------|------------------|--------------|---------------|\n");

	for (int i = 0; i < S; i++)
	{
		A[i].show();
	}
	printf("|----------------------------------------------------------------|\n");
	printf("|Примечание: данные даны для температуры плавления               |\n");
	printf("------------------------------------------------------------------\n");
	return 0;
}