// Copyright (C) 2020 Robert Coffey
// Released under the GPLv2 license

#include <stdlib.h>

int bin_search(char *arr, char target, int left, int right)
{
    if (left > right)
        return -1;

    int middle = (left + right) / 2;
    if (target < arr[middle])
        return bin_search(arr, target, left, --middle);
    else if (target > arr[middle])
        return bin_search(arr, target, ++middle, right);
    else
        return middle;
}
