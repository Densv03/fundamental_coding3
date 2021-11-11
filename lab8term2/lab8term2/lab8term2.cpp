#include <assert.h>
#include <iostream>
#include <math.h>
#include <windows.h>

using namespace std;

template <class T>
class Array
{
private:
    int length;
    int index;
    T* data;

public:
    Array()
    {
        length = 100;
        index = 0;
        data = new T[length];
    }

    void setData(T d)
    {
        data[index] = d;
        index++;
    }

    T getSum()
    {
        T sum = 0;
        for (int i = 0; i < index; i++)
        {
            sum += data[i];
        }
        return sum;
    }

    T getAvg()
    {
        T avg;
        avg = getSum() / index;
        return avg;
    }

    void Print()
    {
        for (int i = 0; i < index; i++)
        {
            cout << data[i] << " ";
        }
        cout << '\n';
    }

    T operator[](int ind)
    {
        if (ind == 0)
        {
            return data[0];
        }
        assert(ind > 0 && ind < index);
        T maximum = max(data[0], data[1]);
        for (int i = 2; i <= ind; i++)
        {
            maximum = max(maximum, data[i]);
        }
        return maximum;
    }

    ~Array()
    {
        delete[] data;
    }
};

int main()
{
    setlocale(LC_ALL, "russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Array<int> intArray;
    Array<float> floatArray;

    int int_length, float_length, int_maxindex, float_maxindex;
    cout << "Введите размер массива int: ";
    cin >> int_length;
    cout << "Введите массив: \n";
    for (int i = 0; i < int_length; i++)
    {
        int a;
        cin >> a;
        intArray.setData(a);
    }
    cout << "Введите размер массива float: ";
    cin >> float_length;
    cout << "Введите массив: \n";
    for (int i = 0; i < float_length; i++)
    {
        float a;
        cin >> a;
        floatArray.setData(a);
    }

    cout << "Сумма значений в массиве int: " << intArray.getSum() << '\n' << "Сумма значений в массиве float: " << floatArray.getSum() << "\n\n";

    cout << "Среднеарифметическое значений в массиве int: " << intArray.getAvg() << '\n' << "Среднеарифметическое значений в массиве float: " << floatArray.getAvg() << "\n\n";

    cout << "Массив int: ";
    intArray.Print();
    cout << "Массив float: ";
    floatArray.Print();
    cout << '\n';

    cout << "Введите индекс по которому будет произведен подсчет максимально значения в массиве int: \n";
    cin >> int_maxindex;
    cout << "Введите индекс по которому будет произведен подсчет максимально значения в массиве float: \n";
    cin >> float_maxindex;
    cout << "Максимальное значение в массиве int: " << intArray[int_maxindex] << '\n' << "Максимальное значение в массиве float: " << floatArray[float_maxindex];
}