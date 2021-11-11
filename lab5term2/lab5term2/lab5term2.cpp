#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <stdlib.h>
using namespace std;

class file {
private:
    string result;
public:
    file(string name) {
        string s;
        ifstream fin(name);
        while (!fin.eof()) {
            fin >> s;
            if (atof(s.c_str()) && s.find(".") != string::npos) {
                int n = atof(s.c_str()) * 100;
                int first = n / 100;
                int second = n % 100;
                result += to_string(first) + '.';
                if (second < 10) {
                    result += "0" + to_string(second);
                }
                else {
                    result += to_string(second);
                }
            }
            else {
                if (s.length() > 2 && s[0] == '0' && s[1] == '.') {
                    bool cond = true;
                    for (int i = 2; i < s.length(); i++) {
                        if (s[i] != '0') {
                            cond = false;
                            break;
                        }
                    }
                    if (cond) {
                        result += "0.00";
                    }
                    else {
                        result += s;
                    }
                }
                else {
                    for (char c : s) {
                        if ('a' <= c && c <= 'z') {
                            result += c + 'A' - 'a';
                        }
                        else {
                            result += c;
                        }
                    }
                }

            }
        }
        fin.close();
    }
    ~file() {
        ofstream fout("output.txt");
        fout << result;
        fout.close();
    }
};
int main()
{
    file* bul = new file("test.txt");
    delete bul;
    return 0;
}