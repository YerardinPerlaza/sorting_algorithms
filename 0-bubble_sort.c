#include "sort.h"
/**
*bubble_sort - sort an array
*@array: array to sort
*@size: size of the array
*Return: nothing
*/
void bubble_sort(int *array, size_t size)
{
    int tmp = 0;
    size_t counter = 0, i = 0;

    if (array == NULL || size < 2)
		return;

    for (counter = 0; size - 1 != counter;)
    {
        counter = 0;

        for (i = 0; i + 1 != size; i++)
        {
            if (array[i + 1] < array[i])
            {
                tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
                print_array(array, size);
            }
            else
            {
                counter++;
            }
        }
    }
}
