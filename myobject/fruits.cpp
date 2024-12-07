#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> make_list(stringstream& ss, char listnum) {
    vector<string> fruits;
    string fruit;
    if (listnum == 1) {
        while ((ss >> fruit) && (fruit != "==="))
            fruits.push_back(fruit);
    } else if (listnum == 2) {
        while ((ss >> fruit) && (fruit != "===")) {}
        while (ss >> fruit) 
            fruits.push_back(fruit);
    }
    return fruits;
}

vector<string> make_pairs(vector<string> fruits) {
    vector<string> pairs;
    return pairs;
}

