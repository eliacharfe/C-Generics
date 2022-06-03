#include <stdio.h>
#include <stdlib.h>,
#include <stdbool.h>
#include "Person.h"
#include "Sort.h"
#include "Compare.h"
#include "Utilities.h"

void print(int* arr);
int fillArr(int* arr, int num);

#define SIZEOF_T(type) (unsigned __int64)(((type*)0 + 1))
#define SIZEOF_V(var) (char *)(&var + 1) - (char*)(&var)

#define sizeofCheck 0  // 0 will turn it off / 1  will turn it on
#define swapCheck 0// 0 will turn it off / 1  will turn it on
#define qsortFunc 0 // 0 will turn it off / 1  will turn it on
#define myQuickSortFunc 0 // 0 will turn it off / 1  will turn it on

// program in pure C
int main()
{
	srand((int)time(NULL)); // for random numbers

#if sizeofCheck
	printf("sizeof(char) %I64u \n", sizeof(char));
	printf("SIZEOF_T(char) %I64u \n", SIZEOF_T(char));

	printf("sizeof(int) %I64u \n", sizeof(int));
	printf("SIZEOF_T(int) %I64u \n", SIZEOF_T(int));

	printf("sizeof(double) %I64u \n", sizeof(double));
	printf("SIZEOF_T(double) %I64u \n", SIZEOF_T(double));

	printf("sizeof(float) %I64u \n", sizeof(float));
	printf("SIZEOF_T(float) %I64u \n", SIZEOF_T(float));

	printf("sizeof(unsigned int) %I64u \n", sizeof(unsigned int));
	printf("SIZEOF_T(unsigned int) %I64u \n", SIZEOF_T(unsigned int));

	printf("sizeof(long long) %I64u \n", sizeof(long long));
	printf("SIZEOF_T(long long) %I64u \n", SIZEOF_T(long long));

	printf("sizeof(bool) %I64u \n", sizeof(bool));
	printf("SIZEOF_T(bool) %I64u \n", SIZEOF_T(bool));

	printf("sizeof(Person) %I64u \n", sizeof(Person));
	printf("SIZEOF_T(Person) %I64u \n", SIZEOF_T(Person));
#endif

	Person* persons = malloc(sizeof(Person) * ARR_SIZE);
	fillPersons(persons); // initiates some persons with data


#if swapCheck
	// Swap check (int* / generic)
	int* a = malloc(sizeof(a));
	int* b = malloc(sizeof(b));

	int num = 1;

	num = fillArr(a, num);
	fillArr(b, num);
	print(a);
	print(b);

	swap(a, b, SIZEOF_T(int)); // swap the 2 int* arrays
	print(a);
	print(b);

	printf("=======================================\nPersons not sorted/swaped: \n\n");
	printPersons(persons);

	swapGeneric(&persons[0], &persons[1], SIZEOF_T(Person));
	printf("swapGeneric persons[0] and persons[1] :\n\n");
	printPersons(persons);

	swapGeneric(&persons[2], &persons[3], SIZEOF_T(Person));
	printf("swapGeneric persons[2] and persons[3] :\n\n");
	printPersons(persons);

	//free(a);
	//free(b);
#endif

#if qsortFunc 
// using qsort func
	printf("=======================================\nPersons not sorted/swaped: \n\n");
	printPersons(persons);

	printf("=======================================\nqsortFunc:\n");
	printf("Sorted by ID's (qsort):\n\n");
	qsort(persons, ARR_SIZE, SIZEOF_T(Person), cmpById); // sort by id
	printPersons(persons, "ID's (qsort)");

	printf("Sorted by ages (qsort):\n\n");
	qsort(persons, ARR_SIZE, SIZEOF_T(Person), cmpByAge); // sort by age
	printPersons(persons, "ages (qsort)");

	printf("Sorted by names (qsort):\n\n");
	qsort(persons, ARR_SIZE, SIZEOF_T(Person), cmpByName); // sort by names
	printPersons(persons, "names (qsort)");
#endif

#if myQuickSortFunc
	// my generic sort implemntation
	printf("=======================================\nPersons not sorted/swaped: \n\n");
	printPersons(persons);

	printf("=======================================\nmy Quicksort Func:\n");
	printf("Sorted by ID's (my quicksort):\n\n");
	myQuickSort(persons, 0, ARR_SIZE - 1, SIZEOF_T(Person), cmpById); // sort by id
	printPersons(persons);

	printf("Sorted by ages (my quicksort):\n\n");
	myQuickSort(persons, 0, ARR_SIZE - 1, SIZEOF_T(Person), cmpByAge); // sort by age
	printPersons(persons);

	printf("Sorted by names (my quicksort):\n\n");
	myQuickSort(persons, 0, ARR_SIZE - 1, SIZEOF_T(Person), cmpByName); // sort by names
	printPersons(persons);

#endif

	free(persons);

	return EXIT_SUCCESS;
}
//----------------------
void print(int* arr)
{
	printf("arr: ");
	for (int i = 0; arr[i] != '\0'; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
//-----------------------
int fillArr(int* arr, int num)
{
	for (int i = 0; arr[i] != '\0'; i++) {
		arr[i] = num;
		num++;
	}
	return num;
}
//-------------------------------
