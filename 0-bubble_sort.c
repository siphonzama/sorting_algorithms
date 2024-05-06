#include "sort.h"

/**
 * bubble_sort - bubble sort algorithm implementation
 * @array: array to sort
 * @size: size of the array to sort
 * Description: sorts an array of integers in ascending order using
 *		bubble sort algorith
 */
void bubble_sort(int *array, size_t size)
{
	int *left, *right, tmp, swapped;
	size_t idx;

	if (array == NULL || size < 2)
		return;

	do {
		idx = 1;
		left = array;
		right = array + idx;
		swapped = false;

		while (idx < size)
		{
			if (*left > *right)
			{
				tmp = *left;
				*left = *right;
				*right = tmp;
				swapped = true;
				print_array(array, size);
			}
			idx += 1;
			left = right;
			right = array + idx;
		}

	} while (swapped == true);
}
