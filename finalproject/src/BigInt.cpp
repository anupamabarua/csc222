#include <iostream>
#include <string>
#include "BigInt.h"
using namespace std;

BigInt::BigInt() {
    negative = false;
    digits = "0";
}

BigInt::BigInt(int i) {
    negative = (i >= 0) ? false : true;
    digits = (i >= 0) ? std::to_string(i) : std::to_string(-i);
}

BigInt::BigInt(string n) {
    negative = (n.front() == '-') ? true : false;
    digits = (n.front() == '-') ? n.substr(1, n.size() - 1) : n;
}

string BigInt::to_string() const {
    return (!negative) ? digits : "-" + digits;
}

bool BigInt::operator==(const BigInt& num1) const {
    return (num1.digits == digits && num1.negative == negative);
}

bool BigInt::operator>(const BigInt& num1) const {
    return !(*this <= num1);
}

bool BigInt::operator<(const BigInt& num1) const {
    if (*this == num1) {
        return false;
    }
    if (negative && !num1.negative) {
        return true;
    }
    if (!negative && num1.negative) {
        return false;
    }

    if (!negative) { 
        if (digits.length() != num1.digits.length()) {
            return digits.length() < num1.digits.length();
        }
        return digits < num1.digits; // Lexicographical comparison
    } else { // Both are negative
        if (digits.length() != num1.digits.length()) {
            return digits.length() > num1.digits.length();
        }
        return digits > num1.digits; 
    }
}

bool BigInt::operator!=(const BigInt& num1) const {
    return !(*this == num1);
}

bool BigInt::operator<=(const BigInt& num1) const {
    return (*this < num1) || (*this == num1);
}

bool BigInt::operator>=(const BigInt& num1) const {
    return !(*this < num1);
}

