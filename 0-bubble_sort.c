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
	short proc = 0;

	if (array == NULL || size < 2)
		exit(EXIT_FAILURE);

	do {
		proc = 0;

		for (i = 0; i < (size -  1); i++)
		{
		if (array[i] > array[i + 1])
		{
		swapperFunc(array + i, array + i + 1);
		print_array(array, size);
		proc++;
		}
		}
	} while (proc > 0);
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


