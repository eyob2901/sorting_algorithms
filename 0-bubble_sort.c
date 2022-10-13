#include "sort.h"

/**
* swap_ints - function that swaps two integers in an array
* @n1: Number to be swapped
* @n2: Another number to be swapped
*
* Return: nothing
*/
void swap_ints(int *n1, int *n2)
{
	int temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

/**
* bubble_sort - function that sorts an array of integers in ascending
* order using the Bubble sort algorithm
* @array: The array of integers to be sorted
* @size: The array size
*
* Return: nothing
*/
void bubble_sort(int *array, size_t size)
{
	size_t n, length = size;
	bool bud = false;

	if (array == NULL || size < 2)
		return;

	while (bud == false)
	{
		bud = true;
		for (n = 0; n < length - 1; n++)
		{
			if (array[n] > array[n + 1])
			{
				swap_ints(array + n, array + n + 1);
				print_array(array, size);
				bud = false;
			}
		}
		length--;
	}
}
