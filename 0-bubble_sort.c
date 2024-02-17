#include "sort.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

void swapperFunc(int *, int *);

/**
 * bubble_sort - sorts an array of integer number in ASC order
 * @array: pointer to array of integers to be sorted
 * @size: size of the array
 * func does bubble sorting in an ascending order and prints
 * array after ea swap
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;

	if (array == NULL || size < 2)
		exit(EXIT_FAILURE);

	for (; i < (size - 1); i++)
	{
		size_t j = 0;
		bool unlock = false;

		for (j = 0; j < (size - i - 1); j++)
		{
		if (array[j] > array[j + 1])
		{
		swapperFunc(&array[j], &array[j + 1]);
		unlock = true;
		}
		}

		if (unlock == false)
			break;

	print_array(array, size);
	}
}

/**
 * swapperFunc - triple bucket function
 * @Num1: pointer to the 1st integer
 * @Num2: pointer to the 2nd integer
 */
void swapperFunc(int *Num1, int *Num2)
{
	short temp = 0;

	temp = *Num1;
	*Num1 = *Num2;
	*Num2 = temp;
}


