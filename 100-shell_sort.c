#include "sort.h"
/**
 * shell_sort - sorts an array of ints in ASC order
 * @array: pointer to an array of ints to be sorted
 * @size: size of the array to get sorted
 * Performs a shell sorting algorithm with knuth sequence
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1, i = 0, j = 0;

	if (array == NULL || size <= 2)
		exit(EXIT_FAILURE);

	while (n < (size / 3))
		n = n * 3 + 1;

	while (n > 0)
	{
		for (i = n; i < size; i++)
		{
		short temp = array[i];

		for (j = i; j >= n && array[j - n] > temp; j -= n)
			array[j] = array[j - n];

		array[j] = temp;
		}

		print_array(array, size);
		n /= 3;
	}
}
