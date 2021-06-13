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
int i,j;
int temp; 

    for (i = 0; i < size -1; i++)
    {
        int jMin = i;
        
        for (j = i+1; j < size; j++)
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
