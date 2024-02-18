#include "sort.h"
#include <stdlib.h>
/**
 * selection_sort - sorts an array of integers in ASC
 * @array: pointer to an array of ints
 * @size: size of array
 * performs a selection sorting algorithm in ascending order
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;

	if (array == NULL || size < 2)
		exit(EXIT_FAILURE);

	while (i < (size - 1))
	{
		size_t minIdx = i;
		int *tempVal = (int *)malloc(sizeof(int));

		j = (i + 1);

		while (j < size)
		{
		if (array[j] < array[minIdx])
			minIdx = j;

		j++;
		}

		if (!(minIdx == i))
		{
		*tempVal = array[i];

		array[i] = array[minIdx];
		array[minIdx] = *tempVal;
		}

		print_array(array, size);
		i++;
	}
}
