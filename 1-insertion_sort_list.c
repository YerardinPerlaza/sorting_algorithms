#include "sort.h"

void swap_nds(listint_t **list, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*list = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}
