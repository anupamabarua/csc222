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
bool BigInt::operator<(const BigInt& num1) const{
    return (!(*this > num1) && !(*this == num1));
}
bool BigInt::operator!=(const BigInt& num1) const{
    return !(*this == num1);
}
bool BigInt::operator>=(const BigInt& num1) const{
    return !(*this < num1);
}
bool BigInt::operator<=(const BigInt& num1) const{
    return !(*this > num1);
}

BigInt BigInt::operator=(const BigInt& num1) const {
    BigInt output;
    if(*this>=num1.digits){
        output.digits = digits;
        output.negative = negative;
    }else{
        output.digits = num1.digits;
        output.negative = num1.negative;
    }

    int length = digits.length();
    int shortlength = num1.digits.length();
    int curent;
    int carry;
    int c = 0;
    if (num1.digits.length() > length) {
        length = num1.digits.length();
        shortlength = digits.length();
    }
    c=shortlength;
    for(int i = shortlength-1; i >= shortlength; i--){
        current = std::to_int(digits[i])+ std::to_int(num1.digits[i]) + carry;
        output[i] = std::to_string(current);
        carry = 0;
        if(curent >= 10){
            carry = 1;
            current -= 10;
        }
        c--;
    }

    while(c>0){
        current = to_int(digits[i]);
        output[i] = std::to_string(current);
    }
    return output;
    }

