#include <stdio.h>
#include "dynarray.c"

int main()
{
    int size = 5;
    int newSize = 6;
    dynarray *array = newDynArray(5);

    printf("Setting Dynamic Array Values.\n");
    for (int i = 0; i < size; i++)
    {
        appendDynArray(array, i + 1);
    }

    printf("Displaying Dynamic Array Values.\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", getElemDynArray(array, i));
    }
    printf("\n");

    printf("Resizing Dynamic Array.\n");
    resizeDynArray(array, newSize);

    printf("Appending Dynamic Array.\n");
    appendDynArray(array, 9);

    printf("Pop Array.\n");
    printf("%d\n", popDynArray(array));

    printf("Displaying Dynamic Array Values.\n");
    for (int i = 0; i < newSize; i++)
    {
        printf("%d ", getElemDynArray(array, i));
    }
    printf("\n");

    printf("Freeing Array Memory.\n");
    freeDynarray(array);

    printf("Displaying Dynamic Array Values.\n");
    for (int i = 0; i < newSize; i++)
    {
        printf("%d ", getElemDynArray(array, i));
    }
    printf("\n");

    return 0;
}