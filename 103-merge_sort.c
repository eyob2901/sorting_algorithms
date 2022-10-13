#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
* merge_subarr - function that sorts a subarray of integers
* @subarr: subarray of an array of integers to be sorted
* @buff: buffer to store the sorted subarray
* @front: beginning index of the array
* @mid: middle index of the array
* @back: end index of the array
*
* Return: nothing
*/
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t n, m, x = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (n = front, m = mid; n < mid && m < back; x++)
		buff[x] = (subarr[n] < subarr[m]) ? subarr[n++] : subarr[m++];
	for (; n < mid; n++)
		buff[x++] = subarr[n];
	for (; m < back; m++)
		buff[x++] = subarr[m];
	for (n = front, x = 0; n < back; n++)
		subarr[n] = buff[x++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
* merge_sort_recursive - function that impliments the merge sort algorithm
* recursively
* @subarr: subarray of an array of integers to be sorted
* @buff: buffer to store the sorted result
* @front: beginning index of the subarray
* @back: end index of the subarray
*/
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
* merge_sort - function that sorts an array of integers in ascending
* order using the merge sort algorithm
* @array: array of integers to be sorted
* @size: size of the array to be sorted
*/
void merge_sort(int *array, size_t size)
{
	int *buf_size;

	if (array == NULL || size < 2)
		return;

	buf_size = malloc(sizeof(int) * size);
	if (buf_size == NULL)
		return;

	merge_sort_recursive(array, buf_size, 0, size);

	free(buf_size);
}
