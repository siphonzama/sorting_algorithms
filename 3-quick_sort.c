#include "sort.h"

/**
 * swap_ints - swaps two integers
 * @first_int: first int
 * @second_int: second int
 */
void swap_ints(int *first_int, int *second_int)
{
	int tmp;

	tmp = *first_int;
	*first_int = *second_int;
	*second_int = tmp;
}
/**
 * arr_partition - partitions an array by using a pivot
 * @array: array to partition
 * @low: smallest number in array
 * @high: highest number in array
 * @size: size of array
 * Return: integer, index of pivot
 */
int arr_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int x = low - 1, y;

	for (y = low; y <= high; y++)
	{
		if (array[y] <= pivot)
		{
			x++;
			if (x != y)
			{
				swap_ints(&array[x], &array[y]);
				print_array(array, size);
			}
		}
	}
	return (x);
}
/**
 * lomuto_partition - performs rearrangin of array recursively
 * @array: array to sorted
 * @low: the lowest element of the array
 * @high: highest element of the array
 * @size: size of array
 */
void lomuto_partition(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = arr_partition(array, low, high, size);
		lomuto_partition(array, low, i - 1, size);
		lomuto_partition(array, i + 1, high, size);
	}
}

/**
 * quick_sort - quick sort algorithm implementation
 * @array: array to sorted
 * @size: size of the array to sorted
 *
 * Description: sorts an array of integers in ascending order
 *				using the Quick sort algorithm
 */

void quick_sort(int *array, size_t size)
{
	lomuto_partition(array, 0, size - 1, size);
}
