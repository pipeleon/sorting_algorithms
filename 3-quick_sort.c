#include "sort.h"
/* Task 3 0x1B. C - Sorting algorithms & Big O */

/**
 * partition - sorts an array using the Quick sort algorithm
 * @array: Array to sort
 * @high: pivot
 * @low: low comparison
 * @size: size
 * Return: void
 */
int partition(int *array, int high, int low, size_t size)
{
	int pivot, i, j, tmp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high; j++)
	{
		if (pivot >= array[j])
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	return (i);
}

/**
 * lomuto - sorts an array using the Quick sort algorithm
 * @array: Array to sort
 * @high: pivot
 * @low: low comparison
 * @size: size
 * Return: void
 */
void lomuto(int *array, int high, int low, size_t size)
{
	int i;

	if (low < high)
	{
		i = partition(array, high, low, size);
		lomuto(array, i - 1, low, size);
		lomuto(array, high, i + 1, size);
	}
}

/**
 * quick_sort - sorts an array using the Quick sort algorithm
 * @array: Array to sort
 * @size: Array size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	int high, low;

	low = 0;
	high = size - 1;

	lomuto(array, high, low, size);
}
