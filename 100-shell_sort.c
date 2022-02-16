#include "sort.h"
/**
* shell_sort - Sorts an array of integers in ascending
* order using the Shell sort algorithm
* @array: array of integers.
* @size: Size of array
*/

void shell_sort(int *array, size_t size)
{
	int i, j, k, interval, n;
	int tmp;
	int gap[] = {0, 1, 4, 13, 40, 121, 364, 1093};

	n = (int)size;

	if (array == NULL || size < 2)
		return;

	for (i = 0; ; i++)
	{
		if (gap[i] > n)
		{
			i--;
			break;
		}
	}

	interval = gap[i];
	while (i > 0)
	{
		for (j = interval; j < n; j++)
		{
			tmp = array[j];
			for (k = j; k >= interval; k = k - interval)
			{
				if (tmp < array[k - interval])
					array[k] = array[k - interval];
				else
					break;
			}
			array[k] = tmp;
		}
		print_array(array, size);
		i--;
		interval = gap[i];
	}
}
