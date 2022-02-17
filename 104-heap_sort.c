#include "sort.h"
/* Task 104 0x1B. C - Sorting algorithms & Big O */

/**
 * heapify -  sorts an array using the Selection sort algorithm
 * @array: Array to sort
 * @n: Size of the array
 *
 * Return: void
*/
void heapify(int *array, int n)
{
	int i, root, maxI, parentI, tmp;

	i = n;
	root = 0;

	while (i > root)
	{
		maxI = i;
		if (i % 2 == 0)
		{
			i--;
			if (array[i] > array[maxI])
				maxI = i;
		}
		parentI = (i - 1) / 2;
		if (array[maxI] > array[parentI])
		{
			tmp = array[parentI];
			array[parentI] = array[maxI];
			array[maxI] = tmp;
			print_array(array, n);
			sift_down(array, maxI, n - 1, n);
		}
		i--;
	}
}

/**
 * sift_down -  sorts an array using the Selection sort algorithm
 * @array: Array to sort
 * @parentI: Size of the array
 * @end: End
 * @n: Size
 *
 * Return: void
*/
void sift_down(int *array, int parentI, int end, size_t n)
{
	int left, right, maxI, tmp;

	while (parentI < end)
	{
		left = (parentI * 2) + 1;
		right = (parentI * 2) + 2;
		maxI =  parentI;
		if (left > end)
			break;
		if (right <= end)
			maxI = right;
		if (array[left] > array[maxI])
			maxI = left;

		if (array[maxI] > array[parentI])
		{
			tmp = array[parentI];
			array[parentI] = array[maxI];
			array[maxI] = tmp;
			parentI = maxI;
			print_array(array, n);
		}
		else
			break;
	}
}

/**
 * heap_sort - sorts an array using the Heap sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: void
*/
void heap_sort(int *array, size_t size)
{
	int n, i, root, tmp;

	n = (int)size;
	heapify(array, n);
	i = n - 1;
	root = 0;

	while (i > root)
	{
		tmp = array[i];
		array[i] = array[root];
		array[root] = tmp;
		n--;
		print_array(array, size);
		sift_down(array, root, n - 1, size);
		i--;
	}
}
