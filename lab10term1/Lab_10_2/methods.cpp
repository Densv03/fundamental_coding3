#include"methods.h"
void SUM::set(int a, int b) {
    x = a;
    y = b;
}
void SUM::print() {
    cout << "x = " << x << "  ";
    cout << "y = " << y << "  ";
    cout << "Sum = " << Sum << "  " << endl;
}
void SUM::sum() {
    Sum = x + y;
    cout << "Sum = " << Sum << endl;
}
void SUM::NUL() {
    Sum = 0;
}