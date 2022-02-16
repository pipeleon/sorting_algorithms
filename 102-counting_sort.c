#include "sort.h"
/* Task 102 0x1B. C - Sorting algorithms & Big O */

/**
 * counting_sort -  sorts an array using the Counting sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: void
*/
void counting_sort(int *array, size_t size)
{
    int n, i, j, k = array[0], *count, *sorted;
    
    n = (int)size;
    for (i = 0; i < n; i++)
        if (k < array[i])
            k = array[i];
    k++;
    count = malloc(sizeof(int) * k);
    if (!count)
        return;
    sorted = malloc(sizeof(int) * n);
    if (!sorted)
        return;
    for (i = 0; i < n; i++)
    {
        j = array[i] - 1;
        count[j]++;
    }
    for (j = 1; j < k; j++)
        count[j] = count[j] + count[j - 1];
    for (i = n - 1; i >= 0; i--)
    {
        j = array[i] - 1;
        count[j]--;
        sorted[count[j]] = array[i];
    }
    print_array(count, k);
    for (i = 0; i < n; i++)
        array[i] = sorted[i];
    free(count);
    free(sorted);
}