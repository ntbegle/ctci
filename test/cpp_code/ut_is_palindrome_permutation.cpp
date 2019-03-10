
#include <iostream>
#include <string>
#include <ch1.h>

using namespace std;

int main(int argc, char** argv)
{
    const int num_tc = 6;
    string test_case_s[num_tc] = {"tact coa", "Tact Coa", "TactCoa", "Tac cAt", "Tacco", "taco"};
    bool test_case_result[num_tc] = {true, true, true, true, false, false};

    Ch1 uut;
    int failed = 0;
    for(int i = 0; i < num_tc; ++i)
    {
        
        if(uut.is_palindrome_permutation(test_case_s[i]) != test_case_result[i])
        {
            cout << "urlify failed test case: " << test_case_s[i] << endl;
            --failed;
        }
    }

    cout << "Total failed test cases: " << failed << endl;
    cout << "Final Result: " << (failed < 0 ? "FAIL" : "PASS") << endl;
    return failed;
}
