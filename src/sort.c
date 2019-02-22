
#include <stddef.h>
#include "sort.h"

int partition(int* data, int start, int stop)
{
    int temp;
    int part_idx = start;

    for(int i = start; i < stop; ++i)
    {
        if(data[i] < data[stop])
        {
            temp = data[i];
            data[i] = data[part_idx];
            data[part_idx] = temp;
            ++part_idx;
        }
    }

    temp = data[part_idx];
    data[part_idx] = data[stop];
    data[stop] = temp;

    return part_idx;
}

void sort_quick_recurse(int* data, int start, int stop)
{
    if(stop < start)
    {
        return;   
    }

    int part_idx = partition(data, start, stop);
    sort_quick_recurse(data, start, part_idx - 1);
    sort_quick_recurse(data, part_idx + 1, stop);
}

void sort_quick(int* data, int size)
{
    if(data == NULL)
        return;

    sort_quick_recurse(data, 0, size - 1);
}
