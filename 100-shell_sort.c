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
* shell_sort - function that sorts an array of integers in ascending order
* using the Shell sort algorithm, using the Knuth sequence
* @array: array to be sorted
* @size: size of the array to be sorted
*
* Return: nothing
*/
void shell_sort(int *array, size_t size)
{
	size_t vacant, n, m;

	if (array == NULL || size < 2)
		return;

	for (vacant = 1; vacant < (size / 3);)
		vacant = vacant * 3 + 1;

	for (; vacant >= 1; vacant /= 3)
	{
		for (n = vacant; n < size; n++)
		{
			m = n;
			while (m >= vacant && array[m - vacant] > array[m])
			{
				swap_ints(array + m, array + (m - vacant));
				m -= vacant;
			}
		}
		print_array(array, size);
	}
}
