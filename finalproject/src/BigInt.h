#include <string>
using namespace std;

class BigInt
{
    bool negative;
    string digits;

    public:
    // constructors
    BigInt();
    BigInt(int);
    BigInt(string);
    
    //opertors
    bool operator==(const BigInt&) const;
    bool operator>(const BigInt&) const;
    bool operator<(const BigInt&) const;
    bool operator!=(const BigInt&) const;
    bool operator<=(const BigInt&) const;

    // member functions
    string to_string() const;
};


