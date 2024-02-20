#include "sort.h"
#include <limits.h>
#include <stdio.h>
void freeAlloc(int *, int *);
int *count(int *, int, size_t);
/**
 * counting_sort - sorts array of ints in asc
 * @array: pointer to arrays of ints
 * @size: size of array to be sorted
 * perfomrs a counting sort algorithm in ASC order
 */
void counting_sort(int *array, size_t size)
{
	int maxInt = 0, *counter, *confirmSorting = NULL;
	size_t i = 0, arrIdx = 0;

	if (array == NULL || size < 2)
		exit(EXIT_FAILURE);

	while (i < size)
	{
	if (array[i] > maxInt)
		maxInt = array[i];

	i++;
	}

	confirmSorting = (int *)malloc(sizeof(int) * size);
	if (confirmSorting == NULL)
	{
	free(confirmSorting);
	exit(EXIT_FAILURE);
	}

	counter = count(array, maxInt, size);
	print_array(counter, (maxInt + 1));

	for (i = 0; i < size; i++)
	{
		arrIdx = counter[array[i]];

		confirmSorting[arrIdx - 1] = array[i];
		arrIdx--;
	}

	for (i = 0; i < size; i++)
		array[i] = confirmSorting[i];

	freeAlloc(confirmSorting, counter);
}
/**
 * count - count the occurences of ea element in an int array
 * @arr: pointer to an array of ints
 * @maxInt: max int value in an array
 * @size: size of the array
 * Return: array of counts of ea element
 */
int *count(int *arr, int maxInt, size_t size)
{
	int *counter = NULL;
	size_t i = 0;

	counter = (int *)malloc(sizeof(int) * (maxInt + 1));
	if (counter == NULL)
	{
	free(counter);
	exit(EXIT_FAILURE);
	}

	for (i = 0; i < (size_t)(maxInt + 1); i++)
		counter[i] = 0;

	for (i = 0; i < size; i++)
		counter[arr[i]]++;

	for (i = 0; i < (size_t)(maxInt + 1); i++)
		counter[i] += counter[i - 1];

	return (counter);
}
/**
 * freeAlloc - frees allocated memory of two ints
 * @first: pointer to the first int array
 * @second: pointer to the second int array
 */
void freeAlloc(int *first, int *second)
{
	if (first != NULL)
		free(first);

	if (second != NULL)
		free(second);
}
