#pragma once
#ifndef vIscosity
#define vIscosity


#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "windows.h"
#include <time.h>
#include <iomanip>

#define S 4

using namespace std;

class elements {
private:
	string name;
	int num;
	int temperature;
	float viscosity;
public:

	elements();
	elements(string name1, int num1, int temperature1, float viscosity1);
	elements(const elements& liq);

	void random();
	int random_number();
	void show();
	void setter(string name1, int num1, int temperature1, float viscosity1);
	~elements();
};
#endif