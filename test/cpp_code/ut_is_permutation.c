
#include <iostream>
#include <string>
#include <vector>
#include <ch1.h>

using namespace std;

int main(int argc, char** argv)
{
    const int num_tc = 4;
    string test_case_s1[num_tc] = {"abcd", "asdf", "asdfasdf", "asdf"};
    string test_case_s2[num_tc] = {"dcba", "asdf", "asdf",     "bsdf"};
    bool test_case_result[num_tc] = {true, true, false, false};

    ch1 uut;
    int failed = 0;
    for(int i = 0; i < num_tc; ++i)
    {
        if(uut.is_permutation(test_case_s1[i], test_case_s2[i]) != test_case_result[i])
        {
            cout << "is_permuation failed test case: " << test_case_s1[i] << " : " << test_case_s2[i] << endl;
            --failed;
        }
    }

    cout << "Total failed test cases: " << failed << endl;
    cout << "Final Result: " << (failed < 0 ? "FAIL" : "PASS") << endl;
    return failed;
}
