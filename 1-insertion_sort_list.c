#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
void swap(listint_t *temp1, listint_t *temp2)
{
        temp1->next = temp2->next;
        if (temp2->next != NULL)
                temp2->next->prev = temp1;
        temp2->next = temp1;
        temp2->prev = temp1->prev;
        if (temp2->prev != NULL)
                temp2->prev->next = temp2;
        temp1->prev = temp2;
}
/**
 * main - Entry point
 *
 * Return: Always 0
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	current = *list;
	temp = (*list)->next;

	while(temp != NULL)
	{
		if (current != NULL && current->n > temp->n)
		{
			swap(current, temp);
			current = temp->prev;
			if (current == NULL)
				*list = temp;
			print_list(*list);
			while(current != NULL && current->n > temp->n)
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
