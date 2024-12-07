#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> make_list(stringstream& ss, char listnum) {
    vector<string> fruits;
    string fruits;
    if (listnum == 1) {
        while ((ss >> fruits) && (fruits != "==="))
            fruits.push_back(fruits);
    } else if (listnum == 2) {
        while ((ss >> fruits) && (fruits != "==="));
        while (ss >> fruits) fruits.push_back(fruits);
    }
    return fruits;
}
vector<string> make_pairs(vector<string> fruits) {
    vecotr<string> pairs;
    return pairs;
}
