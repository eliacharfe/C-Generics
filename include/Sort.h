#pragma once
#include "Person.h"
#include "Swap.h"

void myQuickSort(void* base, int low, int high, size_t size, int (*compar)(const void*, const void*));
int partition(void* base, int low, int high, size_t size, int (*compar)(const void*, const void*));

