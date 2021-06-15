#include "sort.h"
#include <stdlib.h>
void swap(int *array, int gap, int index);

/**
 * shell_sort - sorts an array of integers in ascending order unsing the
 * shell sort algorithm.
 * @array: pointer to array.
 * @size: size of the array.
 */
void shell_sort(int *array, size_t size)
{
	int limit;
	int index;
	int gap;
	int up;

	if (size < 2)
		return;
	up = (int) size;
	for (gap = 1; gap < up / 3; gap = gap * 3 + 1)
	{}

	for (limit = 0; limit < up;)
	{
		index = limit;

		while (index < up)
		{
			if (index + gap < up && array[index] > array[index + gap])
				swap(array, gap, index);
			index = index + gap;
		}
		limit++;
		if (limit == gap)
		{
			gap = gap / 3;
			limit = 0;
			print_array(array, size);
		}
		if (gap < 1)
			break;
	}
}
/**
 * swap - Swaps the numbers when needed.
 * @array: Points to array of numbers.
 * @gap: The gap used to swap the numbers.
 * @index: The index of the number.
 */
void swap(int *array, int gap, int index)
{
	int tmp;

	tmp = array[index];
	array[index] = array[index + gap];
	array[index + gap] = tmp;
	index = index - gap;
	while (index >= 0)
	{
		if (array[index] > array[index + gap])
		{
			tmp = array[index];
			array[index] = array[index + gap];
			array[index + gap] = tmp;
		}

		index = index - gap;
	}
}
