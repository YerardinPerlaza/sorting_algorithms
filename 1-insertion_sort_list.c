#include "sort.h"

/**
 * swap - function swap
 * @temp1: node1
 * @temp2: node2
 * Return: nothing
 */
void swap(listint_t *temp1, listint_t *temp2)
{
	temp1->next = temp2->next;

	if (temp1 == NULL || temp2 == NULL)
		return;

	if (temp2->next != NULL)
		temp2->next->prev = temp1;
	temp2->next = temp1;
	temp2->prev = temp1->prev;
	if (temp2->prev != NULL)
		temp2->prev->next = temp2;
	temp1->prev = temp2;
}
/**
 * insertion_sort_list - insertion sort algorithm
 * @list: a list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	current = *list;
	temp = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (temp != NULL)
	{
		if (current != NULL && current->n > temp->n)
		{
			swap(current, temp);
			current = temp->prev;
			if (current == NULL)
				*list = temp;
			print_list(*list);
			while (current != NULL && current->n > temp->n)
			{
				swap(current, temp);
				current = temp->prev;
				if (current == NULL)
					*list = temp;
				print_list(*list);
			}
		}
		else
		{
			current = temp;
			temp = temp->next;
		}
	}
}
