
#include <stdio.h>
#include <stdlib.h>

#include "ch4.h"
#include "binary_tree.h"

#define MAX_NUM_ELEMENTS 32

int main(int argc, char** argv)
{
    int sorted_array_vals[MAX_NUM_ELEMENTS];
    int num_vals = argc - 1;

    for(int i = 1; i < argc; ++i)
    {
        sorted_array_vals[i-1] = atoi(argv[i]);
    }

    BinaryTree* bst = bt_create_minimal_bst(sorted_array_vals, num_vals);

    bool is_bst = validate_bst(bst);

    printf("is_bst = %d\n", is_bst);
}
