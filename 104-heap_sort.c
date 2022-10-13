#include "sort.h"

void swap_ints(int *n1, int *n2);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
* max_heapify - function that turns a binary tree into a complete binary heap
* @array: array of integers representing a binary tree
* @size: size of the array/tree
* @base: index of the base row of the tree
* @root: root node of the binary tree
*
* Return: nothing
*/
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, big;

	left = 2 * root + 1;
	right = 2 * root + 2;
	big = root;

	if (left < base && array[left] > array[big])
		big = left;
	if (right < base && array[right] > array[big])
		big = right;

	if (big != root)
	{
		swap_ints(array + root, array + big);
		print_array(array, size);
		max_heapify(array, size, base, big);
	}
}

/**
* heap_sort - function that sorts an array of integers in ascending
* order using the heap sort algorithm
* @array: array of integers to be sorted
* @size: size of the array to be sorted
*
* Return: nothing
*/
void heap_sort(int *array, size_t size)
{
	int n;

	if (array == NULL || size < 2)
		return;

	for (n = (size / 2) - 1; n >= 0; n--)
		max_heapify(array, size, size, n);

	for (n = size - 1; n > 0; n--)
	{
		swap_ints(array, array + n);
		print_array(array, size);
		max_heapify(array, size, n, 0);
	}
}
