#include <stdio.h>

typedef struct ArrayList
{
	int EMPTY_CELL_VALUE;
	int* List;
	int Count;
	int Capacity;
} ArrayList;