#include <stdio.h>

#define ARRAY_LENGTH 10

void doubleSelectionSort(int array[]);
void printArray(int array[]);

int main()
{
    int numbers[ARRAY_LENGTH] = {10, 18, 1, 8, 0, 88, 12, 56, 10, 100};
    doubleSelectionSort(numbers);
    printArray(numbers);
    return 0;
}

void doubleSelectionSort(int array[])
{
    int length = ARRAY_LENGTH - 1;
    int start, end, middle = length / 2;
    int min, max;
    int minValue, maxValue;
    int temp;

    for (int i = 0; i <= middle; i++)
    {
        start = i;
        end = length - i;

        min = i;
        max = end;

        minValue = array[min];
        maxValue = array[max];

        for (int j = i; j <= end; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
                minValue = array[min];
            }
            else if (array[j] > array[max])
            {
                max = j;
                maxValue = array[max];
            }
        }

        if (start != min)
        {
            temp = minValue;
            if (array[start] == maxValue)
                max = min;
            array[min] = array[start];
            array[start] = temp;
        }

        if (end != max)
        {
            temp = maxValue;
            array[max] = array[end];
            array[end] = temp;
        }
    }
}

void printArray(int array[])
{
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}