#include "sort.h"

/**
* get_max - function that gets the maximum value of an array of integers
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
* counting_sort - function that sorts an array of integers in ascending
* order using the Counting sort algorithm
* @array: array of integers to be sorted
* @size: size of the array to be sorted
*
* Return: nothing
*/
void counting_sort(int *array, size_t size)
{
	int *counter, *arranged, maximum, n;

	if (array == NULL || size < 2)
		return;

	arranged = malloc(sizeof(int) * size);
	if (arranged == NULL)
		return;
	maximum = get_max(array, size);
	counter = malloc(sizeof(int) * (maximum + 1));
	if (counter == NULL)
	{
		free(arranged);
		return;
	}

	for (n = 0; n < (maximum + 1); n++)
		counter[n] = 0;
	for (n = 0; n < (int)size; n++)
		counter[array[n]] += 1;
	for (n = 0; n < (maximum + 1); n++)
		counter[n] += counter[n - 1];
	print_array(counter, maximum + 1);

	for (n = 0; n < (int)size; n++)
	{
		arranged[counter[array[n]] - 1] = array[n];
		counter[array[n]] -= 1;
	}

	for (n = 0; n < (int)size; n++)
		array[n] = arranged[n];

	free(arranged);
	free(counter);
}
