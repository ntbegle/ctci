
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <ch1.h>

using namespace std;

int main(int argc, char** argv)
{
    const int num_tc = 5;
    string test_case_s1[num_tc] = {"aabcccccaa", "abcdefg", "aabbccddee", "aaaaaaaaaa", "aabbccddeee"};
    string test_case_result[num_tc] = {"a2b1c5a2", "abcdefg", "aabbccddee", "a10", "a2b2c2d2e3"};

    Ch1 uut;
    int failed = 0;
    for(int i = 0; i < num_tc; ++i)
    {
        char* input = (char*) malloc(sizeof(char) * test_case_s1[i].length());
        strcpy(input, test_case_s1[i].c_str());
        uut.string_compression(input);
        if(input != test_case_result[i])
        {
            cout << "is_string_compression failed test case: " << test_case_s1[i] << endl;
            cout << "  result = " << input << endl;
            --failed;
        }

        free(input);
    }

    cout << "Total failed test cases: " << failed << endl;
    cout << "Final Result: " << (failed < 0 ? "FAIL" : "PASS") << endl;
    return failed;
}
