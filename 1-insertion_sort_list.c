#include "sort.h"
/**
* insertion_sort_list - Sorts a doubly linked list of integers in ascending
* order using the Insertion sort algorithm
* @list: list of integers.
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	listint_t *tmp = NULL;

	if (list == NULL || *list == NULL)
		return;

	for (current = (*list)->next; current; current = current->next)
	{
		while (current->prev && current->prev->n > current->n)
		{
			tmp = current->prev;
			current->prev = tmp->prev;
			tmp->prev = current;
			tmp->next = current->next;
			current->next = tmp;
			if (current->prev)
			{
				current->prev->next = current;
			}
			else
			{
				*list = current;
			}
			if (tmp->next)
			{
				tmp->next->prev = tmp;
			}
			print_list(*list);
		}
	}
}
