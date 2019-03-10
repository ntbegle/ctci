
#include <iomanip>
#include <iostream>
#include "ch1.h"

using namespace std;

#define MAX_LENGTH 5

void print_matrix(int** matrix, int length)
{
    for(int i = 0; i < length; ++i)
    {
        for(int j = 0; j < length; ++j)
        {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool comp_matrix(int** result, int** expected, int length)
{
    for(int i = 0; i < length; ++i)
    {
        for(int j = 0; j < length; ++j)
        {
            if(result[i][j] != expected[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

void reformat_matrix(int orig[MAX_LENGTH][MAX_LENGTH], int** matrix)
{
    for(int i = 0; i < MAX_LENGTH; ++i)
    {
        matrix[i] = new int[MAX_LENGTH];
        for(int j = 0; j < MAX_LENGTH; ++j)
        {
            matrix[i][j] = orig[i][j];
        }
    }

}

int main(int argc, char** argv)
{
    const int num_tc = 4;
    int test_case_matrix[num_tc][MAX_LENGTH][MAX_LENGTH] = 
        {{{1}},
         {{ 1, 2},
          { 3, 4}},
         {{ 1, 2, 3, 4},
          { 5, 6, 7, 8},
          { 9,10,11,12},
          {13,14,15,16}},
         {{ 1, 2, 3, 4, 5},
          { 6, 7, 8, 9,10},
          {11,12,13,14,15},
          {16,17,18,19,20},
          {21,22,23,24,25}}};
    int test_case_length[num_tc] = {1, 2, 4, 5};
    int test_case_result[num_tc][MAX_LENGTH][MAX_LENGTH] = 
        {{{1}},
         {{ 3, 1},
          { 4, 2}},
         {{13, 9, 5, 1},
          {14,10, 6, 2},
          {15,11, 7, 3},
          {16,12, 8, 4}},
         {{21,16,11, 6, 1},
          {22,17,12, 7, 2},
          {23,18,13, 8, 3},
          {24,19,14, 9, 4},
          {25,20,15,10, 5}}};

    int** input = new int*[MAX_LENGTH];
    int** result = new int*[MAX_LENGTH];
    for(int i = 0; i < MAX_LENGTH; ++i)
    {
        input[i] = new int[MAX_LENGTH];
        result[i] = new int[MAX_LENGTH];
    }

    Ch1 uut;
    int failed = 0;
    for(int i = 0; i < num_tc; ++i)
    {
        reformat_matrix(test_case_matrix[i], input);
        reformat_matrix(test_case_result[i], result);
        uut.rotate_matrix(input, test_case_length[i]);
        if(!comp_matrix(input, result, test_case_length[i]))
        {
            cout << "rotate_matrix failed test case: " << i << endl;
            cout << "output: " << endl;
            print_matrix(input, test_case_length[i]);
            --failed;
        }
    }

    cout << "Total failed test cases: " << failed << endl;
    cout << "Final Result: " << (failed < 0 ? "FAIL" : "PASS") << endl;
    return failed;
}
