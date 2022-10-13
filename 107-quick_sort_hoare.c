#include "sort.h"

void swap_ints(int *n1, int *n2);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
* hoare_partition - function that orders a subset of an array of integers
* according to the hoare partition scheme
* @array: array of integers to be ordered
* @size: size of the array to be ordered
* @left: starting index of the subset to be ordered
* @right: ending index of the subset to be ordered
*
* Return: the final partition index
*/
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
* hoare_sort - function that implements the quicksort algorithm recursively
* @array: array of integers to be sorted
* @size: size of the array to be sorted
* @left: starting index of the array partition to be ordered
* @right: ending index of the array partition to be ordered
*
* Return: nothing
*/
void hoare_sort(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, partition - 1);
		hoare_sort(array, size, partition, right);
	}
}

/**
* quick_sort_hoare - function that sorts an array of integers in ascending
* order using the quicksort algorithm
* @array: array of integers to be sorted
* @size: size of the array to be sorted
*
* Return: nothing
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
