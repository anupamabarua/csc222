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

BigInt BigInt::operator+(const BigInt& num1) const {
    BigInt output;
    const BigInt* longer;
    const BigInt* shorter;
    
    if (*this >= num1) {
        longer = this;
        shorter = &num1;
    } else {
        longer = &num1;
        shorter = this;
    }
    
    output.digits = longer->digits;
    output.negative = longer->negative;

    int carry = 0;
    int curent = 0;
    int length = longer->digits.length();
    int shortlength = shorter->digits.length();

    for (int i = 0; i < shortlength; i++) {
        curent = (longer->digits[length - 1 - i] - '0') +  (shorter->digits[shortlength - 1 - i] - '0') + carry;
        carry = curent / 10;
        output.digits[length - 1 - i] = (curent % 10) + '0';
    }
    for (int i = shortlength; i < length; i++) {
        curent = (longer->digits[length - 1 - i] - '0') + carry;
        carry = curent / 10;
        output.digits[length - 1 - i] = (curent % 10) + '0';
    }

    if (carry > 0) {
        output.digits.insert(output.digits.begin(), carry + '0');
    }

    return output;
}

BigInt BigInt::operator-(const BigInt& num1) const {
    BigInt output;
    int carry = 0;
    int fl = digits.length();
    int sl = num1.digits.length();
    if(num1>*this && !num1.negative && !negative){
        output = num1 - *this;
        output.negative = true;
        return output;
    }
    if(num1.negative && !negative){
        BigInt temp1 = *this;
        BigInt temp2 = num1;
        temp2.negative = false;
        output = temp1 + temp2;
        return output;
    }
    if(negative && !num1.negative){
        BigInt temp1 = *this;
        BigInt temp2 = num1;
        temp1.negative = false;
        output = temp1 + temp2;
        output.negative = true;
        return output;
    }
    
    for (int i = 0; i < fl; i++) {
        int d1 = (fl - 1 - i >= 0) ? digits[fl - 1 - i] - '0' : 0;
        int d2 = (sl - 1 - i >= 0) ? num1.digits[sl - 1 - i] - '0' : 0;
        
        int curent = d1 - d2 - carry;
        
        if (curent < 0) {
            curent += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        
        output.digits.insert(output.digits.begin(), curent + '0');
    }

    while (output.digits.length() > 1 && output.digits[0] == '0') {
        output.digits.erase(output.digits.begin());
    }
    output.digits.pop_back();
    return output;
}
