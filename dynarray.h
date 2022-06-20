typedef struct dynarray
{
    int *array;
    int size;
    int length;
} dynarray;

dynarray *newDynArray(int size);
int resizeDynArray(dynarray *arr, int newSize);
int getElemDynArray(dynarray *arr, int n);
int setElemDynArray(dynarray *arr, int n, int value);
void appendDynArray(dynarray *arr, int x);
int popDynArray(dynarray *arr);
void freeDynarray(dynarray *arr);