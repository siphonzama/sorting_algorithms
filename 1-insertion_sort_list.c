#include "sort.h"

/**
 * insertion_sort_list - insertion sort algorithm implementation
 * @list: list to sort
 * Description: sorts a doubly linked list of integers in ascending order
 *				using the insertion sort algorithm
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *unsorted_el, *el_to_sort;

	if (!list || !(*list) || !(*list)->next)
		return;

	unsorted_el = (*list)->next;

	while (unsorted_el)
	{
		el_to_sort = unsorted_el;
		unsorted_el = unsorted_el->next;

		while (el_to_sort->prev && (el_to_sort->prev->n > el_to_sort->n))
		{
			el_to_sort->prev->next = el_to_sort->next;
			if (el_to_sort->next)
				el_to_sort->next->prev = el_to_sort->prev;

			el_to_sort->next = el_to_sort->prev;
			el_to_sort->prev = el_to_sort->prev->prev;
			el_to_sort->next->prev = el_to_sort;

			if (el_to_sort->prev)
				el_to_sort->prev->next = el_to_sort;
			else
				*list = el_to_sort;

			print_list(*list);
		}
	}
}
