#include "sort.h"
/**
 * radix_sort - The radix sort
 * Description: radix sort
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	unsigned int j;
	int p, max, i;
	int *out;

	max = 0;
	if (array == NULL || size < 2)
		return;
	for (j = 0; j < size; j++)
	{
		if (*(array + j) > max)
			max = *(array + j);
	}
	for (p = 1; max / p > 0; p *= 10)
	{
	int count[10] = {0};

	out = malloc(sizeof(int) * size);
	if (out == NULL)
		return;
	for (i = 0; i < (int) size; i++)
		count[(*(array + i) / p) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		out[count[(*(array + i) / p) % 10] - 1] = *(array + i);
		count[(*(array + i) / p) % 10]--;
	}
	for (i = 0; i < (int) size; i++)
		*(array + i) = out[i];
	free(out);
	print_array(array, size);
	}
}
