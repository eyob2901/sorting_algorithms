#include "sort.h"

/**
* swap_ints - function that swaps two integers in an array
* @n1: first integer to be swapped
* @n2: second integer to be swapped
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
* selection_sort - function that sorts an array of integers in ascending
* order using the Selection sort algorithm
* @array: array of integers to be swapped
* @size: size of the array to be swapped
*
* Return: nothing
*/
void selection_sort(int *array, size_t size)
{
	int *mid;
	size_t n, m;

	if (array == NULL || size < 2)
		return;

	for (n = 0; n < size - 1; n++)
	{
		mid = array + n;
		for (m = n + 1; m < size; m++)
			mid = (array[m] < *mid) ? (array + m) : mid;

		if ((array + n) != mid)
		{
			swap_ints(array + n, mid);
			print_array(array, size);
		}
	}
}
