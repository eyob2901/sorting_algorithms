#include "sort.h"

/**
* swap_nodes - function that swaps two nodes in a doubly linked listint_t list
* @h: double head pointer to the doubly linked list
* @n1: double pointer to the first node
* @n2: pointer to the second node
*
* Return: nothing
*/
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
* insertion_sort_list - function that sorts a doubly linked list of
* integers in ascending order using the Insertion sort algorithm
* @list: double pointer to head of list of elements to be sorted
*
* Return: nothing
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *count, *put, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (count = (*list)->next; count != NULL; count = temp)
	{
		temp = count->next;
		put = count->prev;
		while (put != NULL && count->n < put->n)
		{
			swap_nodes(list, &put, count);
			print_list((const listint_t *)*list);
		}
	}
}
