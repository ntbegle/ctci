
#include <iostream>
#include <string>
#include <map>
#include <ch1.h>

using namespace std;

int main(int argc, char** argv)
{
    map<string, bool> test_case;
    test_case["abcde"] = true;
    test_case["aabcde"] = false;
    test_case["abcdee"] = false;
    test_case["abccde"] = false;
    test_case["asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdf;alksdjfa;lskdjfa;lsdkjfa;lksdjf;alskdjfasoidfhj;aoeijf;aslkfjds;lajfd;slfja;lsdnflasnfv;lajnv;lkanl;fjdsafioejowijfa;wiefja;slidfja;slkdjf;aa;slkdjfoewirpqoaiwuerpoqiwuerpoewjr;lj;sladkfjak;sldnvnsvna;sdjf;alsjdf;ljasdofpqoiwueproiuqweporiuqjwe;lkfjas;dlknvk,nczxvjnzxvjdlkflkahsdlfa;feiwurqpweoirupwoeifj;asdlkfja;sdfijpoiquweproiuqewproiuewjf;lkasjdf;alksjdf;lskjfvzmvnzxcmnvzx,.nvkldj;lfajsd;lkjfasjfdsfpewijrpqweurpoiewuriopewujrpfasdf"] = 
        false;

    ch1 uut;
    int failed = 0;
    for(map<string, bool>::iterator iter = test_case.begin(); iter != test_case.end(); ++iter)
    {
        if(uut.is_unique(iter->first) != iter->second)
        {
            cout << "is_unique failed test case: " << iter->first << endl;
            --failed;
        }

        if(uut.is_unique_in_place(iter->first) != iter->second)
        {
            cout << "is_unique_in_place failed test case: " << iter->first << endl;
            --failed;
        }
    }

    cout << "Total failed test cases: " << failed << endl;
    cout << "Final Result: " << (failed < 0 ? "FAIL" : "PASS") << endl;
    return failed;
}
