
#include <stdio.h>
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

void merge(int* data, int start, int mid, int stop)
{
    const int num = stop-start+1;
    int copy[num];

    for(int i = 0; i < num; ++i)
    {
        copy[i] = data[start + i];
    }
    
    int left_idx = 0;
    int right_idx = mid - start + 1;
    
    for(int mrg_idx = start; mrg_idx <= stop; ++mrg_idx)
    {
        if(left_idx <= (mid - start) && right_idx <= (stop - start))
        {
            if(copy[left_idx] <= copy[right_idx])
            {
                data[mrg_idx] = copy[left_idx++];
            }
            else
            {
                data[mrg_idx] = copy[right_idx++];
            }
        }
        else if(left_idx <= (mid - start))
        {
            data[mrg_idx] = copy[left_idx++];
        }
        else
        {
            data[mrg_idx] = copy[right_idx++];
        }
    }
}

void sort_merge_recurse(int* data, int start, int stop)
{
    if(stop <= start)
        return;

    int mid = (stop + start) / 2;
    sort_merge_recurse(data, start, mid);
    sort_merge_recurse(data, mid + 1, stop);
    merge(data, start, mid, stop);
}

void sort_merge(int* data, int size)
{
    if(data == NULL)
        return;
    sort_merge_recurse(data, 0, size - 1);
}
