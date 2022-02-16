#include "sort.h"
/**
* cocktail_sort_list - Sorts a doubly linked list of integers in ascending
* order using the Cocktail sorting algorithm
* @list: list of integers.
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *tmp;
	int swap = 1;

	if (list == NULL || *list == NULL)
		return;
	while (swap == 1)
	{
		swap = 0;
		for (current = (*list)->next; current; current = current->next)
		{
			if (current->prev->n > current->n)
			{
				tmp = current->prev, current->prev = tmp->prev, tmp->prev = current;
				tmp->next = current->next, current->next = tmp;
				if (current->prev)
					current->prev->next = current;
				else
					*list = current;
				if (tmp->next)
					tmp->next->prev = tmp;
				print_list(*list), swap = 1, tmp = current;
			}
		}
		if (swap == 0)
			break;
		for (current = tmp->prev; current; current = current->prev)
		{
			if (current->next->n < current->n)
			{
				tmp = current->next, current->next = tmp->next, swap = 1;
				if (current->prev)
					current->prev->next = tmp;
				else
					*list = tmp;
				if (tmp->next)
					tmp->next->prev = current;
				tmp->next = current, tmp->prev = current->prev, current->prev = tmp, print_list(*list);
			}
		}
	}
}
