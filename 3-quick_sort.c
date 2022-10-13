#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

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
* lomuto_partition - function that forms the order a subset of an array of
* integers according to the lomuto partition scheme (last element as pivot)
* @array: array of integers to be sorted
* @size: size of the array to be sorted
* @left: starting index of the subset order to be formed
* @right: ending index of the subset order to be formed
*
* Return: final partition index
*/
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
* lomuto_sort - function that implements the quicksort algorithm recursively
* @array: array of integers to be sorted
* @size: size of the array to be sorted
* @left: starting index of the array partition order to be formed
* @right: ending index of the array partition order to be formed
*
* Return: nothing
*/
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, partition - 1);
		lomuto_sort(array, size, partition + 1, right);
	}
}

/**
* quick_sort - function that sorts an array of integers in ascending order
* using the Quick sort algorithm
* @array: array of integers to be sorted
* @size: size of the array to be sorted
*
* Return: nothing
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
