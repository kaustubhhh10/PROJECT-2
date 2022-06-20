#include "dynarray.h"

#include <stdlib.h>

dynarray *newDynArray(int size)
{
    dynarray *arr = malloc(sizeof(dynarray));
    arr->length = 0;
    arr->size = size;
    arr->array = calloc(size, sizeof(int));
    return arr;
}

int resizeDynArray(dynarray *arr, int newSize)
{
    if (newSize <= arr->length)
    {
        return -1;
    }
    else
    {
        // FIXME would a smaller size work
        arr = realloc(arr->array, newSize * sizeof(int));
        return 0;
    }
}

int getElemDynArray(dynarray *arr, int n)
{
    return arr->array[n];
}

int setElemDynArray(dynarray *arr, int n, int value)
{
    if (n < arr->length)
    {
        arr->array[n] = value;
    }
}

void appendDynArray(dynarray *arr, int value)
{
    if (arr->length == arr->size)
    {
        // resizing geometrically
        resizeDynArray(arr, arr->size * 2);
    }
    arr->array[arr->length] = value;
    arr->length++;
}

int popDynArray(dynarray *arr)
{
    if (arr->length > 0)
    {
        int lastElem = arr->array[arr->length - 1];
        arr->length -= 1;
        return lastElem;
    }
    else
    {
        return -1;
    }
}

void freeDynarray(dynarray *arr)
{
    // FIXME is this line needed?
    free(arr->array);

    free(arr);
}