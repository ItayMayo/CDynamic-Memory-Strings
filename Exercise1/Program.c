#include<stdio.h>
#include<stdlib.h>

int* create_index_arr(int n);
int* duplicate_numbers(const int* numbers, int length);
int* fib(int max_num);

int main()
{
    int* dynamicArray = create_index_arr(5);

    for (int i = 0; i < 5; i++)
    {
        printf("dynamic value: %d\n", dynamicArray[i]);
    }

    int* duplicatedNumbers = duplicate_numbers(dynamicArray, 5);
    free(dynamicArray);
    free(duplicatedNumbers);

    int* fibArray = fib(145);

    for (int i = 0; fibArray[i] != -1; i++)
    {
        printf("fib value: %d\n", fibArray[i]);
    }

    free(fibArray);
}

int* create_index_arr(int n)
{
    int* dynamicArray = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        dynamicArray[i] = i;
    }

    return dynamicArray;
}

int* duplicate_numbers(const int* numbers, int length) //הפרמטר יכול להיות דינאמי או בגודל קבוע - זה לא משנה. הפונקציה יודעת להתמודד עם שני סוגי המערכים.
{
    int* newNumbers = calloc(length, sizeof(int));

    for (int i = 0; i < length; i++)
    {
        newNumbers[i] = numbers[i];
    }

    return newNumbers;
}

int* fib(int max_num)
{
    int* fibArray = NULL;

    for (int i = 0; ; i++)
    {
        fibArray = realloc(fibArray, sizeof(fibArray) + ((i + 1) * sizeof(int)));

        if (i < 2)
        {
            fibArray[i] = i;
        }
        else
        {
            int lastValue = fibArray[(i - 2)];
            int currentValue = fibArray[(i - 1)];
            fibArray[i] = currentValue + lastValue;
        }
        if (fibArray[i] > max_num)
        {
            fibArray = realloc(fibArray, sizeof(fibArray) + ((i + 1) * sizeof(int)));
            fibArray[i + 1] = -1;

            return fibArray;
        }
    }
}