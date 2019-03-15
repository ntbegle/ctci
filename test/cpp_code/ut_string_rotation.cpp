
#include <iostream>
#include <string>
#include "ch1.h"

using namespace std;

int main(int argc, char** argv)
{
    const int num_tc = 7;
    string test_case_s1[num_tc] = {
        "waterbottle",
        "waterbottle",
        "waterbottle",
        "waterbottle",
        "waterbottle",
        "w",
        "w"};
    string test_case_s2[num_tc] = {
        "erbottlewat",
        "aterbottlew",
        "ewaterbottl",
        "waterbottls",
        "bottlewaterbottle",
        "w",
        "a"};
    bool test_case_result[num_tc] = {
        true,
        true,
        true,
        false,
        false,
        true,
        false};

    Ch1 uut;
    int failed = 0;
    for(int i = 0; i < num_tc; ++i)
    {
        if(uut.is_string_rotation(test_case_s1[i], test_case_s2[i]) != test_case_result[i])
        {
            cout << "is_string_rotation failed test case: " << test_case_s1[i] << " : " << test_case_s2[i] << endl;
            --failed;
        }
    }

    cout << "Total failed test cases: " << failed << endl;
    cout << "Final Result: " << (failed < 0 ? "FAIL" : "PASS") << endl;
    return failed;

}
