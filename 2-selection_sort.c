#include "sort.h"
/* Task 2 0x1B. C - Sorting algorithms & Big O */

/**
 * selection_sort -  sorts an array using the Selection sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: void
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, k = 0;
	int tmp, tmp2;

	for (i = 0; i < size; i++)
	{
		tmp = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (tmp > array[j])
			{
				tmp = array[j];
				k = j;
			}
		}
		if (k > 0)
		{
			tmp2 = array[i];
			array[i] = tmp;
			array[k] = tmp2;
			print_array(array, size);
		}
		k = 0;
	}
}
