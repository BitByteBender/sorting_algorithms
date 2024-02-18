#include "sort.h"
#include <stdlib.h>

void nodesSwapper(listint_t **, listint_t **, listint_t *);
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
	nodesSwapper(list, &insert, thisNode);
	print_list((const listint_t *)*list);
	insert = thisNode->prev;
	}
	thisNode = thisNode->next;
	}
}

/**
 * nodesSwapper - swaps nodes in a doubly linked list
 * @head: pointer to doubly linked list head
 * @first: pointer to the first node to be swapped
 * @second: pointer to the second node to be swapped
 * swaps 2 nodes in a listint_t
 */
void nodesSwapper(listint_t **head, listint_t **first, listint_t *second)
{

	if (*first == NULL)
		exit(EXIT_FAILURE);

	(*first)->next = second->next;

	if (second->next != NULL)
		second->next->prev = (*first);

	second->prev = (*first)->prev;
	second->next = (*first);

	if ((*first)->prev == NULL)
		*head = second;
	else
		(*first)->prev->next = second;

	(*first)->prev = second;
	(*first) = second->prev;

}
