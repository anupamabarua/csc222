#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include <sstream>
#include <vector>
#include "fruits.h"
using namespace std;

string input = "CPE1\nCPE2\nCPE3\nCPE4\n===\nNC1\nNC2\nNC3\n";
stringstream ss(input);

TEST_CASE("Test make_list function") {
    vector<string> list1 = make_list(ss, 1);
    CHECK(list1 == vector<string>{"CPE1", "CPE2", "CPE3", "CPE4"});

    stringstream ss2(input);
    vector<string> list2 = make_list(ss2, 2);
    CHECK(list2 == vector<string>{"NC1", "NC2", "NC3"});
}

TEST_CASE("Test make_pairs function") {
    vector<string> fruits = {"CPE1", "CPE2", "CPE3", "CPE4"};
    vector<string> pairs = make_pairs(fruits);
}
