#include <iostream>
#include "Fraction.h"
using namespace std;

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int n, int d) {
    numerator = n;
    denominator = d;
}

Fraction::Fraction(string s) {
        numerator = 0;
        denominator = 1;
}
