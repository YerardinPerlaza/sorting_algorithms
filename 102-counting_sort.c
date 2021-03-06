#include "sort.h"

/**
 * key_value - get the max value in the array
 * @array: the array
 * @size: size
 * Return: max value in the array
 */

int key_value(int *array, size_t size)
{
	int tmp = array[0];
	int i;

	if (size == 0)
		return (0);

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > tmp)
			tmp = array[i];
	}
	return (tmp);
}

/**
 * counting_sort - counting sort algorithm
 * @array: the array
 * @size: size
 * Return: nothing
 */

void counting_sort(int *array, size_t size)
{
	int k = key_value(array, size);
	int max_k = k + 1, i = 0;
	int *count;
	int *output;

	if (!array || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	count = malloc(sizeof(int) * max_k);
	if (!count)
	{
		free(output);
		return;
	}

	for (i = 0; i <= k; i++)
		count[i] = 0;

	for (i = 0; i <= (int)size - 1; i++)
		++count[array[i]];

	for (i = 1; i <= k; i++)
		count[i] = count[i] + count[i - 1];

	print_array(count, max_k);

	for (i = size - 1; i >= 0; i--)
		output[--count[array[i]]] = array[i];

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
