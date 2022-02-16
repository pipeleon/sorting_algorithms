#include "sort.h"
/**
* cocktail_sort_list - Sorts a doubly linked list of integers in ascending
* order using the Cocktail sorting algorithm
* @list: list of integers.
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *cur, *tmp;
	int swap = 1;

	if (list == NULL || *list == NULL)
		return;
	while (swap == 1)
	{
		swap = 0;
		for (cur = (*list)->next; cur; cur = cur->next)
		{
			if (cur->prev->n > cur->n)
			{
				tmp = cur->prev, cur->prev = tmp->prev, tmp->prev = cur;
				tmp->next = cur->next, cur->next = tmp;
				if (cur->prev)
					cur->prev->next = cur;
				else
					*list = cur;
				if (tmp->next)
					tmp->next->prev = tmp;
				print_list(*list), swap = 1, tmp = cur;
			}
		}
		if (swap == 0)
			break;
		for (cur = tmp->prev; cur; cur = cur->prev)
		{
			if (cur->next->n < cur->n)
			{
				tmp = cur->next, cur->next = tmp->next, swap = 1;
				if (cur->prev)
					cur->prev->next = tmp;
				else
					*list = tmp;
				if (tmp->next)
					tmp->next->prev = cur;
				tmp->next = cur, tmp->prev = cur->prev, cur->prev = tmp, print_list(*list);
			}
		}
	}
}
