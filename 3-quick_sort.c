#include "sort.h"
size_t partition(int *array, int lo, int hi, size_t size);
void quick_sort(int *array, size_t size);

/**
 * q_sort - quick sort implementation
 * @array: Array
 * @lo: lower index
 * @hi: higher index
 * @size: size of the array
 * Return: nothing
 */

void q_sort(int *array, int lo, int hi, size_t size)
{
	size_t part;

	if (lo < hi)
	{
		part = partition(array, lo, hi, size);
		q_sort(array, lo, part - 1, size);
		q_sort(array, part + 1, hi, size);
	}
}

/**
 * partition - partition function
 * @array: array
 * @lo: lower index
 * @hi: higher index
 * @size: size of the array
 * Return: index when partition is done
 */

size_t partition(int *array, int lo, int hi, size_t size)
{
	int temp, pivot = array[hi];
	int i = lo - 1, j;

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != hi)
	{
		temp = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort - quick sort
 * Description: Quick sort algorithm
 * @array: Array
 * @size: Size of the array
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
	{
		return;
	}

	q_sort(array, 0, size - 1, (size_t)size);
}
