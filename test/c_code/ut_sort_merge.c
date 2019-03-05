
#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

int main(int argc, char** argv)
{
    int data[64];
    int size = argc - 1;

    for(int i = 1; i < argc; ++i)
    {
        data[i-1] = atoi(argv[i]);
    }

    sort_merge(data, size);

    printf("Sorted Array: ");
    for(int j = 0; j < size; ++j)
    {
        printf("%d ", data[j]);
    }
    printf("\n");
}
