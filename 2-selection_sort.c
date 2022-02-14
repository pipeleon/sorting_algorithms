#include "sort.h"
/* Task 2 0x1B. C - Sorting algorithms & Big O */

/**
 * array_to_list - creates a listint_t based on an array
 * @array: Array to sort
 *
 * Return: listint_t
 */
listint_t *array_to_list(int *array, size_t n)
{
	size_t i;
	listint_t *new;

	new = NULL;
	for (i = 0; i < n; i++)
		add_dnodeint_end(&new, array[i]);
	
	return (new);
}

/**
 * add_dnodeint_end - adds a new node at the end of a listint_t list
 * @head: List
 * @n: new int
 *
 * Return: lisint_t
 */
listint_t *add_dnodeint_end(listint_t **head, int n)
{
	listint_t *new;
	listint_t *current;
	int *tmp;
	
	current = *head;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	tmp = (int *)&new->n;
	*tmp = n;
	
	new->next = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		new->prev = current;
		current->next = new;
	}

	return (new);
}

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

