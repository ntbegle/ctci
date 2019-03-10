
#include <iostream>
#include <string>
#include <cstring>
#include <ch1.h>

using namespace std;

int main(int argc, char** argv)
{
    const int num_tc = 4;
    const int char_buf = 32;
    char test_case_s[num_tc][char_buf] = {" ab", "  ", "ab ", " ab cd ef "};
    char test_case_result[num_tc][char_buf] = {"%20ab", "%20%20", "ab%20", "%20ab%20cd%20ef%20"};

    Ch1 uut;
    int failed = 0;
    for(int i = 0; i < num_tc; ++i)
    {
        uut.urlify(test_case_s[i], char_buf);
        if(strcmp(test_case_s[i], test_case_result[i]) != 0)
        {
            cout << "urlify failed test case: " << test_case_s[i] << endl;
            --failed;
        }
        printf("result = %s\n", test_case_s[i]);
    }

    cout << "Total failed test cases: " << failed << endl;
    cout << "Final Result: " << (failed < 0 ? "FAIL" : "PASS") << endl;
    return failed;
}
