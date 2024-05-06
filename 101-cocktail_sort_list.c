#include "sort.h"

/**
 * swap_nodes - swaps doubly linked list node
 * @first_node: the first node
 * @second_node: the second node
 */
void swap_nodes(listint_t **first_node, listint_t **second_node)
{
	if ((*first_node)->prev)
		(*first_node)->prev->next = *second_node;
	if ((*second_node)->next)
		(*second_node)->next->prev = *first_node;
	(*first_node)->next = (*second_node)->next;
	(*second_node)->prev = (*first_node)->prev;
	(*second_node)->next = *first_node;
	(*first_node)->prev = *second_node;
}

/**
 * cocktail_sort_list - Cocktail shaker sort algorithm implementation
 * @list: the doubly linked list
 *
 * Description: sorts a doubly linked list of integers in ascending
 *			order using the Cocktail shaker sort algorithm
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *left_node, *right_node;
	int swapped;

	if (!list || !*list)
		return;

	left_node = *list;
	do {
		swapped = 0;
		while (left_node->next)
		{
			right_node = left_node->next;
			if (left_node->n > right_node->n)
			{
				swap_nodes(&left_node, &right_node);
				if (!right_node->prev)
					*list = right_node;
				print_list(*list);
				swapped = 1;
			}
			else
				left_node = left_node->next;
		}
		right_node = left_node->prev;
		while (right_node->prev)
		{
			left_node = right_node->prev;
			if (right_node->n < left_node->n)
			{
				if (!left_node->prev)
					*list = right_node;
				swap_nodes(&left_node, &right_node);
				print_list(*list);
				swapped = 1;
			}
			else
				right_node = right_node->prev;
		}
	} while (swapped);
}
