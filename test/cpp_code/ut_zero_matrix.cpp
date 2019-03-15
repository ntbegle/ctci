
#include <iomanip>
#include <iostream>
#include "ch1.h"

using namespace std;

#define MAX_LENGTH 5

void print_matrix(int** matrix, int rows, int cols)
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool comp_matrix(int** result, int** expected, int rows, int cols)
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
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
        for(int j = 0; j < MAX_LENGTH; ++j)
        {
            matrix[i][j] = orig[i][j];
        }
    }

}

int main(int argc, char** argv)
{
    const int num_tc = 7;
    int test_case_matrix[num_tc][MAX_LENGTH][MAX_LENGTH] = 
        {{{1}},

         {{0}},

         {{0, 1}},

         {{1},
          {0}},

         {{ 1, 2},
          { 3, 0},
          { 1, 1}},

         {{ 1, 2, 3, 4},
          { 5, 0, 7, 8},
          { 9,10, 0,12},
          {13,14,15, 0}},

         {{ 0, 2, 3, 4, 5},
          { 6, 7, 8, 9,10},
          {11,12,13,14,15},
          {16,17,18,19,20},
          {21,22,23,24,-1}}};
    int test_case_num_rows[num_tc] = {1, 1, 1, 2, 3, 4, 5};
    int test_case_num_cols[num_tc] = {1, 1, 2, 1, 2, 4, 5};
    int test_case_result[num_tc][MAX_LENGTH][MAX_LENGTH] = 
        {{{1}},

         {{0}},

         {{0, 0}},

         {{0},
          {0}},

         {{ 1, 0},
          { 0, 0},
          { 1, 0}},
        
         {{ 1, 0, 0, 0},
          { 0, 0, 0, 0},
          { 0, 0, 0, 0},
          { 0, 0, 0, 0}},
         
         {{ 0, 0, 0, 0, 0},
          { 0, 7, 8, 9,10},
          { 0,12,13,14,15},
          { 0,17,18,19,20},
          { 0,22,23,24,-1}}};

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
        uut.zero_matrix(input, test_case_num_rows[i], test_case_num_cols[i]);
        if(!comp_matrix(input, result, test_case_num_rows[i], test_case_num_cols[i]))
        {
            cout << "zero_matrix failed test case: " << i << endl;
            cout << "output: " << endl;
            print_matrix(input, test_case_num_rows[i], test_case_num_cols[i]);
            --failed;
        }
    }

    cout << "Total failed test cases: " << failed << endl;
    cout << "Final Result: " << (failed < 0 ? "FAIL" : "PASS") << endl;
    return failed;
}
