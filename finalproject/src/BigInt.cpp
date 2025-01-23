#include <iostream>
#include <string>
#include "BigInt.h"
using namespace std;

BigInt::BigInt()
{
    negative = false;
    digits = "0";
}

BigInt::BigInt(int i)
{
    negative = (i >= 0) ? false : true;
    digits = (i >= 0) ? std::to_string(i) : std::to_string(-i);
}

BigInt::BigInt(string n)
{
    negative = (n.front() == '-') ? true: false;
    digits = (n.front() == '-') ? n.substr(1, n.size() - 1) : n;
}

string BigInt::to_string() const
{
    return (!negative) ? digits : "-" + digits;
}

bool BigInt::operator==(const BigInt& num1) const
{

    if (num1.digits==digits && num1.negative==negative)
    {
        return true;
    }
    else
    {
        return false;

    }
}

bool BigInt::operator>(const BigInt& num1) const{
    if(!negative && num1.negative){
        return  true;
    }else if(negative && !num1.negative){
        return false;
    }
    if(!negative){
    if(digits.length() > num1.digits.length()){
        return true;
        }else if(digits.length() < num1.digits.length()){
            return false;
        }
    }else if(negative){
        if(digits.length() < num1.digits.length()){
            return true;
        }else if(digits.length() > num1.digits.length()){
            return false;
        }
    }
    if(!negative){
        for(int i = 0; i < digits.length(); i++){
            if(digits[i] > num1.digits[i]){
                return true;
            }else if(digits[i] < num1.digits[i]){
                return false;
            }
        }
    }
    if(negative){
        for(int i = 0; i < digits.length(); i++){
            if(digits[i] < num1.digits[i]){
                return true;
            }else if(digits[i] > num1.digits[i]){
                return false;
            }
        }
    }
    return false; // Add this return statement
}
bool BigInt::operator<(const BigInt& num1) const {
    if (negative != num1.negative) {
        return negative; // Negative is always less than positive
    }

    if (!negative) { // Both numbers are non-negative
        if (digits.length() != num1.digits.length()) {
            return digits.length() < num1.digits.length();
        }
        return digits < num1.digits; // Lexicographical comparison
    } else { // Both numbers are negative
        if (digits.length() != num1.digits.length()) {
            return digits.length() > num1.digits.length(); // Reverse length comparison
        }
        return digits > num1.digits; // Reverse lexicographical comparison
    }
}

bool BigInt::operator!=(const BigInt& num1) const{
    return !(*this == num1);
}
bool BigInt::operator<=(const BigInt& num1) const{
    return !(*this == num1);
}
bool BigInt::operator>=(const BigInt& num1) const{
    return !(*this == num1);
}
