#include "sort.h"

/**
 * swap - function swap
 * @temp1: node1
 * @temp2: node2
 * @list: list
 * Return: nothing
 */
void swap(listint_t *temp1, listint_t *temp2, listint_t **list)
{
	listint_t *aux_1 = temp1->prev, *aux_2 = temp2->next;

	if (aux_1 != NULL)
	{	aux_1->next = temp2;
	}
	else
	{	*list = temp2;
	}
	if (aux_2 != NULL)
	aux_2->prev = temp1;

	temp2->prev = aux_1;
	temp1->next = aux_2;
	temp2->next = temp1;
	temp1->prev = temp2;
}

/**
 * cocktail_sort_list - The coctail sort
 * Description: an addition of the bubble sort algorithm
 * @list: list to sort
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL, *tail = NULL;
	int flag = 1;

	if (!list || !*list || !(*list)->next)
		return;
	current = *list;
	while (flag != 0)
	{	flag = 0;
		while (current && current->next)
		{
			if (current->n > current->next->n)
			{	swap(current, current->next, list);
				print_list(*list);
				flag = 1;
				if (current->next)
					continue;
			}
			if (!current->next)
				break;
			current = current->next;
		}
		if (flag == 0)
			break;
		tail = current;
		while (tail && tail->prev)
		{
			if (tail->prev->n > tail->n)
			{	swap(tail->prev, tail, list);
				print_list(*list);
				flag = 1;
				if (tail->prev)
					continue;
			}
			if (!tail->prev)
				break;
			tail = tail->prev;
		}
		current = tail;
	}
}
