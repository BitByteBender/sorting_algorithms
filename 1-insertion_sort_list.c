#include "sort.h"
#include <stdlib.h>
/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: pointer to head of doubly linked list listint_t
 * Sorts a doubly linked list of integers using
 * insertion sort and prints list after ea swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *thisNode = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		exit(EXIT_FAILURE);

	thisNode = (*list)->next;

	while (thisNode != NULL)
	{
	listint_t *insert = thisNode->prev;

	while (insert != NULL && (thisNode->n < insert->n))
	{
	listint_t *temp;

	if (insert->prev != NULL)
		insert->prev->next = thisNode;
	else
		*list = thisNode;

	if (thisNode->next != NULL)
		thisNode->next->prev = insert;

	temp = insert->prev;
	insert->prev = thisNode;
	insert->next = thisNode->next;
	thisNode->prev = temp;
	thisNode->next = insert;

	print_list(*list);
	insert = thisNode->prev;
	}
	thisNode = thisNode->next;
	}
}
