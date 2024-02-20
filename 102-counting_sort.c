#include "sort.h"
/**
 * counting_sort - sorts array of ints in asc
 * @array: pointer to arrays of ints
 * @size: size of array to be sorted
 * perfomrs a counting sort algorithm in ASC order
 */
void counting_sort(int *array, size_t size)
{
	int maxInt = 0, *counter = NULL;
	size_t i = 0, arrIdx = 0;

	if (array == NULL || size < 2)
		exit(EXIT_FAILURE);

	maxInt = array[0];
	i = 1;

	while (i < size)
	{
	if (array[i] > maxInt)
		maxInt = array[i];

	i++;
	}

	counter = (int *)malloc(sizeof(int) * (maxInt + 1));
	if (counter == NULL)
		exit(EXIT_FAILURE);

	for (i = 0; i <= (size_t)maxInt; i++)
		counter[i] = 0;

	for (i = 0; i < size; i++)
		counter[array[i]]++;

	print_array(counter, (maxInt + 1));

	for (i = 0; i <= (size_t)maxInt; i++)
	{
		while (counter[i] > 0)
		{
		array[arrIdx++] = i;
		counter[i]--;
		}
	}

	free(counter);
}
