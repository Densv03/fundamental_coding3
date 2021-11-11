#pragma once
#ifndef methods
#define methods

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "windows.h"
#include <time.h>
#include <conio.h>
#include <malloc.h>

using namespace std;

class SUM {
private:
    int x, y;
    int Sum = 0;
public:
    SUM() : x(0), y(0) {}
    SUM(int a, int b) : x(a), y(b) {};
    void set(int a, int b);
    void print();
    void sum();
    void NUL();
};
#endif