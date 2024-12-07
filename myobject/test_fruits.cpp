#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include <sstream>
#include <vector>
#include "fruits.h"
using namespace std;

string input = "CPE1\nCPE2\nCPE3\nCPE4\n===\nNC1\nNC2\nNC3\n";
stringstream ss(input);

TEST_CASE("Test can create and render fruit") {
    MyObject myobj();
    CHECK(myobj.to_string() == "This is fruit");
