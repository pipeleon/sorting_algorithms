#include "sort.h"
/* Task 2 0x1B. C - Sorting algorithms & Big O */

/**
 * array_to_list - creates a listint_t based on an array
 * @array: Array to sort
 *
 * Return: listint_t
 */
listint_t *array_to_list(int *array)
{
	int i;
	listint_t *head = NULL;

	for (i = 0; array[i]; i++)
		add_dnodeint_end(&head, array[i]);
	return (head);
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
	
	current = *head;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
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

void selection_sort(int *array, size_t size)
{
}
*/