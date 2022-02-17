#include "sort.h"
/* Task 103 0x1B. C - Sorting algorithms & Big O */

/**
 * topdownmerge -  sorts an array using the Merge sort algorithm
 * @A: Array to sort
 * @B: Size of the array
 * @begin: Begin
 * @middle: Middle
 * @end: End
 *
 * Return: void
*/
void topdownmerge(int *A, int *B, int begin, int middle, int end)
{
    int i, j, k;

    printf("Merging...\n");
    printf("[left]: ");
    for (i = begin; i < middle; i++)
    {
        printf("%d", A[i]);
        if (i + 1 < middle)
            printf(", ");
        else
            printf("\n");
    }
    printf("[right]: ");
    for (i = middle; i < end; i++)
    {
        printf("%d", A[i]);
        if (i + 1 < end)
            printf(", ");
        else
            printf("\n");
    }
    i = begin;
    j = middle;

    for (k = begin; k < end; k++)
    {
        if (i < middle && (j >= end || A[i] <= A[j]))
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }
    }
    printf("[Done]: ");
    for (k = begin; k < end; k++)
    {
        printf("%d", B[k]);
        if (k + 1 < end)
            printf(", ");
        else
            printf("\n");
    }
}

/**
 * topdownsplit -  sorts an array using the Merge sort algorithm
 * @A: Array to sort
 * @B: Size of the array
 * @begin: Begin
 * @end: End
 *
 * Return: void
*/
void topdownsplit(int *A, int *B, int begin, int end)
{
    int middle;

    if (end - begin <= 1)
        return;
    middle = (end + begin) / 2;
    topdownsplit(B, A, begin, middle);
    topdownsplit(B, A, middle, end);
    topdownmerge(B, A, begin, middle, end);
}

/**
 * merge_sort -  sorts an array using the Merge sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: void
*/
void merge_sort(int *array, size_t size)
{
    int i, n, *sorted;

    if (array == NULL || size < 2)
		return;
    n = (int)size;
    sorted = malloc(sizeof(int) * n);
	if (!sorted)
		return;
    for (i = 0; i < n; i++)
        sorted[i] = array[i];
    
    topdownsplit(array, sorted, 0, n);
    free(sorted);
}