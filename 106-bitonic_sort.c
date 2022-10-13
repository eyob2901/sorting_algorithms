#include "sort.h"

void swap_ints(int *n1, int *n2);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

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
* bitonic_merge - funtion that sorts a bitonic sequence inside
* an array of integers
* @array: array of integers to be sorted
* @size: size of the array to be sorted
* @start: beginning index of the sequence in array to be sorted
* @seq: size of the sequence to be sorted
* @flow: direction to sort in
*
* Return: nothing
*/
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t n, jump = seq / 2;

	if (seq > 1)
	{
		for (n = start; n < start + jump; n++)
		{
			if ((flow == UP && array[n] > array[n + jump]) ||
			    (flow == DOWN && array[n] < array[n + jump]))
				swap_ints(array + n, array + n + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
* bitonic_seq - function that converts an array of integers into
* a bitonic sequence
* @array: An array of integers to be converted
* @size: size of the array to be converted
* @start: beginning index of a block of the building bitonic sequence
* @seq: size of a block of the building bitonic sequence
* @flow: direction to sort the bitonic sequence block in
*
* Return: nothing
*/
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t div = seq / 2;
	char *string = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, string);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, div, UP);
		bitonic_seq(array, size, start + div, div, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, string);
		print_array(array + start, seq);
	}
}

/**
* bitonic_sort - function that sorts an array of integers in ascending
* order using the bitonic sort algorithm
* @array: array of integers to be sorted
* @size: size of the array to be sorted
*
* Return: nothing
*/
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
