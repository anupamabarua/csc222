#include "Fraction.h"
#include <iostream>
using namespace std;

Fraction::Fraction(int n, int d){
    numerator = n;
    denominator = d; 
}

Fraction::Fraction(){
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(string s){
    numerator = 0;
    denominator = 0;
}
