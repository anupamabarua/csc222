#include <iostream>
#include <string>
using namespace std;

struct Fraction {
    int numerator, denominator;
    Fraction();
    Fraction(int, int);
    Fraction(string s);
};
