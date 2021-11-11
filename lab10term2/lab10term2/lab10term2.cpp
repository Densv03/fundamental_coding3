#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

class test
{
private:
	int* arr;
public:
	test()
	{
		arr = new int[0];
	}
	test(int n)
	{
		arr = new int[n];
	}
	void set(int i, int n)
	{
		arr[i] = n;
	}
	int get(int i)
	{
		return arr[i];
	}
	int testmin(int i, int j)
	{
		int k = min(arr[i], arr[j]);
		return k;
	}
	void testsort()
	{
		int i, j;
		for (i = 0; i < sizeof(arr) - 1; i++)
			for (j = 0; j < sizeof(arr) - i - 1; j++)
				if (arr[j] > arr[j + 1])
					swap(&arr[j], &arr[j + 1]);
	}
	int testsum()
	{
		int sum = 0;
		for (int i = 0; i < sizeof(arr); i++)
		{
			if (arr[i] > 0)
			{
				sum += arr[i];
			}
		}
		return sum;
	}
};
int main()
{
	test a(4);
	cout << a.testmin(0, 1) << '\n';
	cout << a.testsum() << '\n';
	a.testsort();
	for (int i = 0; i < 4; i++)
	{
		cout << a.get(i) << " ";
	}
}