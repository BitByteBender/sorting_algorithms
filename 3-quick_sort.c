#include "sort.h"
#include <stddef.h>
#include <stdlib.h>

short Lomuto(int  *, short, short, size_t);
void qSort(int *, short, short, size_t);
/**
 * quick_sort - sorts an array of ints in ASC
 * @array: pointer to the array of ints
 * @size: size of array of ints
 * Uses the Lomuto function
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		exit(EXIT_FAILURE);

	qSort(array, 0, (size - 1), size);
}

/**
 * qSort - recursive algorithmic quick sort
 * @arr: pointer to the array of ints
 * @startIdx: starting index
 * @endIdx: ending index
 * @len: array length
 * uses the lomuto function to perform a recursive quick sort
 */
void qSort(int *arr, short startIdx, short endIdx, size_t len)
{
	if (startIdx < endIdx)
	{
	short turn = Lomuto(arr, startIdx, endIdx, len);

	qSort(arr, startIdx, (turn - 1), len);
	qSort(arr, (turn + 1), endIdx, len);
	}
}

/**
 * swapper - performs swapping
 * @first: pointer to the first integer
 * @second: pointer to the second integer
 * usage of pointer and memory allocation
 * checks and frees pointer
 */
void swapper(int *first, int *second)
{
	int *temp = (int *)malloc(sizeof(int));

	if (temp == NULL)
		exit(EXIT_FAILURE);

	*temp = *first;
	*first = *second;
	*second = *temp;

	free(temp);
}

/**
 * Lomuto - lomuto partition scheme
 * @arr: pointer to the array of integers
 * @startIdx: starting index
 * @endIdx: ending index
 * @len: array length
 * Return: last partition Idx
 */
short Lomuto(int  *arr, short startIdx, short endIdx, size_t len)
{
	short i = (startIdx - 1), j = startIdx, turn = arr[endIdx];

	while (j < endIdx)
	{
	if (arr[j] < turn)
	{
		i++;
		if (!(i == j))
		{
		swapper(&arr[i], &arr[j]);
		print_array(arr, len);
		}
	}
	j++;
	}

	swapper(&arr[i + 1], &arr[endIdx]);
	print_array(arr, len);


	return (i + 1);
}
