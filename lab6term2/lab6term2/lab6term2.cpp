#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <windows.h>

using namespace std;

class Planet {
public:
    string  name;
    float radius;
    float mass;
    string system;
    Planet() { name = ""; radius = 0; mass = 0; system = ""; };
};
void change(Planet&, string&, float&, float&, string);
void show();
void sort();

Planet planets[10];

void change(Planet& planet, string& _name, float& _radius, float& _mass, string _system)
{
    planet.name = _name;
    planet.radius = _radius;
    planet.mass = _mass;
    planet.system = _system;
}

void sort()
{
    Planet temp;
    for (int i = 0; i < 10; i++)
        for (int j = i + 1; j < 10; j++)
            if (planets[i].radius > planets[j].radius)
            {
                swap(planets[i], planets[j]);
            }
}
void show()
{
    cout << "____________________________________________________________________\n";
    cout << "|                              Планета                             |\n";
    cout << "|------------------------------------------------------------------|\n";
    cout << "|   Название   |  Радиус  |  Масса  | Система, в которой находится |\n";
    cout << "|------------------------------------------------------------------|\n";

    for (int i = 0; i < 10; i++)
    {
        cout << "|" << setw(12) << planets[i].name << "  | ";
        cout << setw(8) << planets[i].radius << " |";
        cout << setw(8) << planets[i].mass << " |";
        cout << setw(24) << planets[i].system << "      |";
        cout << "\n";
        cout << "|------------------------------------------------------------------|\n";
    }
}

int main()
{
    setlocale(LC_ALL, "russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string a, d;
    float b, c;
    int p;
    bool empty = true;
    int ind = 0;

    for (;;) {
        cout << "1. Добавить записи\n";
        cout << "2. Сортировать базу\n";
        cout << "3. Вывести базу\n";
        cout << "4. Выход\n";
        cout << "> ";
        cin >> p;
        switch (p) {
        case 1: {
            if (ind >= 10)
            {
                cout << "Массив полон!\n";
            }
            else
            {
                cout << "Название, Радиус, Масса, Система, в которой находится:\n";
                cin >> a >> b >> c;
                cin.ignore();
                getline(cin, d);
                change(planets[ind], a, b, c, d);
                empty = false;
                ind++;
            }
            break;
        }

        case 2: {
            if (empty) { cout << "В базе нет записей!\n"; }
            else sort();
            break;
        }

        case 3: {
            if (empty) { cout << "В базе нет записей!\n"; }
            else show();
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