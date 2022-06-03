
#include "Swap.h"

void swap(int* a, int* b, int size)
{
    printf("\nswap int*:\n\n");
    for (int i = 0; i < size; i++)
    {
        int tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;
    }
}
//--------------------------------------
void swapGeneric(void* a, void* b, size_t size)
{ // swap between 2 types (generic) // in c++ we can also use Templates (behind the scene do something similar)
    
    void* buffer = malloc(size);
    memcpy(buffer, a, size);
    memcpy(a, b, size);
    memcpy(b, buffer, size);

    free(buffer);
}
