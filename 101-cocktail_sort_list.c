#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shake);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shake);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Function swap node in a listint_t doubly linked list
 * @list: Pointer to the head of doubly linked list
 * @tail: Pointer to the tail of doubly linked list
 * @shake: Pointer to the current swapping node of cocktail shaker algorithm
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shake)
{
	listint_t *tmp = (*shake)->next;

	if ((*shake)->prev != NULL)
		(*shake)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shake)->prev;
	(*shake)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shake;
	else
		*tail = *shake;
	(*shake)->prev = tmp;
	tmp->next = *shake;
	*shake = tmp;
}

/**
 * swap_node_behind - Function that swap node in a listint_t doubly linked
 * list with node behind
 * @list: Point to the head of listint_t double linked list
 * @tail: Points to the tail of listint_t doubly linked list
 * @shake: Points to the current swapping node
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shake)
{
	listint_t *tmp = (*shake)->prev;

	if ((*shake)->next != NULL)
		(*shake)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shake)->next;
	(*shake)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shake;
	else
		*list = *shake;
	(*shake)->next = tmp;
	tmp->prev = *shake;
	*shake = tmp;
}

/**
 * cocktail_sort_list - Function that sort a doubly linked list
 * @list: Point to the head of listint_t doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shake;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list) == NULL)
		return;
	for (tail = *list; tail->next != NULL;)
		tail = tail->next;
	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shake = *list; shake != tail; shake = shake->next)
		{
			if (shake->n > shake->next->n)
			{
				swap_node_ahead(list, &tail, &shake);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shake = shake->prev; shake != *list; shake = shake->prev)
		{
			if (shake->n < shake->prev->n)
			{
				swap_node_behind(list, &tail, &shake);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
