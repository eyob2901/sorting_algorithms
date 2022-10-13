#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
* get_max - function that gets the maximum value in an array of integers
* @array: array of integers to be sorted
* @size: size of the array to be sorted
*
* Return: maximum integer in the array
*/
int get_max(int *array, int size)
{
	int maximum, n;

	for (maximum = array[0], n = 1; n < size; n++)
	{
		if (array[n] > maximum)
			maximum = array[n];
	}

	return (maximum);
}

/**
* radix_counting_sort - function that sorts the significant digits of an
* array of integers in ascending order using the counting sort algorithm
* @array: array of integers to be sorted
* @size: size of the array to be sorted
* @sig: significant digit to be  sorted
* @buff: buffer to store the sorted array
*
* Return: nothing
*/
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int counter[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t n;

	for (n = 0; n < size; n++)
		counter[(array[n] / sig) % 10] += 1;

	for (n = 0; n < 10; n++)
		counter[n] += counter[n - 1];

	for (n = size - 1; (int)n >= 0; n--)
	{
		buff[counter[(array[n] / sig) % 10] - 1] = array[n];
		counter[(array[n] / sig) % 10] -= 1;
	}

	for (n = 0; n < size; n++)
		array[n] = buff[n];
}

/**
* radix_sort - function that sorts an array of integers in ascending
* order using the radix sort algorithm
* @array: array of integers to be sorted
* @size: size of the array to be sorted
*
* Return: nothing
*/
void radix_sort(int *array, size_t size)
{
	int maximum, sig, *buf_size;

	if (array == NULL || size < 2)
		return;

	buf_size = malloc(sizeof(int) * size);
	if (buf_size == NULL)
		return;

	maximum = get_max(array, size);
	for (sig = 1; maximum / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buf_size);
		print_array(array, size);
	}

	free(buf_size);
}
