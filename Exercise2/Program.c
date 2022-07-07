#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "ArrayList.h"

ArrayList createArrayList(int capacity);
int GetEntryAtIndex(ArrayList arrayList, int index);
void AddValue(ArrayList* arrayList, int value);
void RemoveValue(ArrayList* arrayList, int index);
ArrayList CloneList(ArrayList originalList);

int main() 
{
	ArrayList list = createArrayList(1);
	AddValue(&list, 5);
	AddValue(&list, 7);
	AddValue(&list, 10);
	RemoveValue(&list, 0);
	int entry = GetEntryAtIndex(list, 0);

	for (int i = 0; i < list.Count; i++)
	{
		printf("value at %d: %d\n", i, list.List[i]);
	}

	printf("Entry: %d\n", entry);

	free(list.List);
}

ArrayList createArrayList(int capacity)
{
	ArrayList arrayList;
	arrayList.EMPTY_CELL_VALUE = -156489;
	arrayList.List = calloc(capacity, sizeof(int));
	arrayList.Capacity = capacity;
	arrayList.Count = 0;

	for (int i = 0; i < arrayList.Capacity; i++)
	{
		arrayList.List[i] = arrayList.EMPTY_CELL_VALUE;
	}

	return arrayList;
}

int GetEntryAtIndex(ArrayList arrayList, int index)
{
	if (index >= arrayList.Capacity)
	{
		printf("Index out of bounds. Index: %d. Capacity: %d.", index, arrayList.Capacity);
		exit(-1);
	}

	int value = arrayList.List[index];
	
	return value;
}

void AddValue(ArrayList* arrayList, int value)
{
	int capacity = arrayList->Capacity;
	const float CAPACITY_INCREASE_BY = 1.3;

	if (arrayList->List[capacity - 1] == arrayList->EMPTY_CELL_VALUE)
	{
		int firstEmptyCellIndex = 0;

		for (firstEmptyCellIndex = 0; arrayList->List[firstEmptyCellIndex] != arrayList->EMPTY_CELL_VALUE; firstEmptyCellIndex++)
		{}

		arrayList->List[firstEmptyCellIndex] = value;
	}
	else
	{
		int newCapacity = ceil(capacity * CAPACITY_INCREASE_BY);
		arrayList->List = realloc(arrayList->List, newCapacity * sizeof(int));
		arrayList->List[capacity] = value;
		arrayList->Capacity = newCapacity;

		for (int i = capacity + 1; i < arrayList->Capacity; i++)
		{
			arrayList->List[i] = arrayList->EMPTY_CELL_VALUE;
		}
	}

	arrayList->Count++;
}

void RemoveValue(ArrayList* arrayList, int index)
{
	if (index >= arrayList->Capacity)
	{
		printf("Index out of bounds. Index: %d. Capacity: %d.", index, arrayList->Capacity);
		exit(-1);
	}

	for (int i = index; i < arrayList->Capacity - 1; i++)
	{
		arrayList->List[i] = arrayList->List[i + 1];
	}

	arrayList->List[arrayList->Capacity - 1] = arrayList->EMPTY_CELL_VALUE;
	arrayList->Count--;
}

ArrayList CloneList(ArrayList originalList)
{
	int capacity = originalList.Capacity;
	ArrayList clonedList = createArrayList(capacity);

	for (int i = 0; i < capacity; i++)
	{
		clonedList.List[i] = originalList.List[i];
		clonedList.Count++;
	}

	return clonedList;
}