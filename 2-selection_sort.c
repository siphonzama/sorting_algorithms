#include "sort.h"

/**
 * selection_sort - selection sort algorithm implementation
 * @array: array to sort
 * @size: size of the array to sort
 *
 * Description: sorts an array of integers in ascending order using
 *				the selection sort algorithm
 */

void selection_sort(int *array, size_t size)
{
	size_t cursor, sort_pos, min_pos;
	int hold;

	if (!array || size < 2)
		return;

	sort_pos = 0;

	while (sort_pos < size - 1)
	{
		cursor = sort_pos + 1;
		min_pos = cursor;

		while (cursor < size)
		{
			if (array[cursor] < array[min_pos])
			{
				min_pos = cursor;
			}
			cursor++;
		}

		if (array[min_pos] < array[sort_pos])
		{
			hold = array[min_pos];
			array[min_pos] = array[sort_pos];
			array[sort_pos] = hold;
			print_array(array, size);
		}
		sort_pos++;
	}
}
