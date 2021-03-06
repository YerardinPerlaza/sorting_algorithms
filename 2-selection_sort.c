#include "sort.h"

/**
 * selection_sort - Selection sort algorithm
 * Description: Selection sort algorithm
 * @array: Array
 * @size: Size of array
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		size_t jMin = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[jMin])
			{
				jMin = j;
			}
		}

		if (jMin != i)
		{
			temp = array[i];
			array[i] = array[jMin];
			array[jMin] = temp;
			print_array(array, size);
		}
	}
}
