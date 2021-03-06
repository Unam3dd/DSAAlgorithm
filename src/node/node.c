#include "node.h"
#include <stdlib.h>
#include <stdio.h>

node_t	*create_node(void *data)
{
	node_t *ptr = (node_t *)malloc(sizeof(node_t));
	
	ptr->index = 0;
	ptr->next = NULL;
	ptr->prev = NULL;
	ptr->data = data;

	return (ptr);
}

node_t	*create_nodes(size_t n)
{
	if (!n || n < 0)
		return (NULL);
	
	node_t *ptr = (node_t *)malloc(sizeof(node_t) * n);
	node_t *save = ptr;

	for (int i = 1; i < n; i++) {
		ptr->data = NULL;
		ptr->prev = NULL;
		ptr->next = (node_t *) (ptr + sizeof(node_t) * i);
		ptr = ptr->next;
	}

	return (save);
}

node_t	*nodes_get_by_index(node_t *nodes, size_t index)
{
	while (nodes && nodes->index != index)
		nodes = nodes->next;
	
	return (nodes);
}

node_t	*node_shift(node_t **nodes)
{
	node_t *next = (*nodes)->next;
	next->prev = NULL;
	next->index--;

	free(*nodes);

	*nodes = next;

	return (*nodes);
}

node_t 	*node_append(node_t **nodes, node_t *new)
{
	node_t *actual = *nodes;

	while (actual->next)
		actual = actual->next;
	
	new->next = NULL;
	new->index = actual->index + 1;
	new->prev = actual;

	actual->next = new;

	return (actual->next);
}

size_t	node_get_size(node_t *nodes)
{
	int i = 0;

	while (nodes) {
		nodes = nodes->next;
		i++;
	}

	return (i);
}

bool_t	node_insert(node_t **nodes, node_t *new, size_t index)
{
	node_t *actual = *nodes;
	node_t *next = NULL;

	while (actual && actual->index != index)
		actual = actual->next;
	
	if (!actual)
		return (1);
	
	next = actual;
	new->next = next;
	new->prev = actual->prev;
	actual->prev->next = new;
	next->prev = new;
	new->index = actual->index;
	next->index++;

	return (0);
}

void 	destroy_node(node_t *node)
{
	if (node)
		free(node);
	
	node = NULL;
}

void	free_all_nodes(node_t **nodes, bool_t opt)
{
	if (opt)
		return (destroy_node(*nodes));

	node_t *next = NULL;

	while (*nodes) {
		next = (*nodes)->next;
		free(*nodes);
		*nodes = next;
	}

	*nodes = NULL;
}

///////////////////////////////////////////////
//
//           NODE LIFO FUNCTIONS
//
////////////////////////////////////////////////

void	node_push(node_t **nodes, node_t *new)
{
	new->prev = NULL;
	(*nodes)->index++;
	new->next = *nodes;
	*nodes = new;
}

void	node_pop(node_t **nodes)
{
	node_t *next = (*nodes)->next;

	next->prev = NULL;
	next->index--;

	free(*nodes);

	*nodes = next;
}

void	node_push_back(node_t **nodes, node_t *new)
{
	node_t *actual = *nodes;

	while (actual->next)
		actual = actual->next;
	
	new->next = NULL;
	new->index = actual->index + 1;
	new->prev = actual;
	actual->next = new;
}

void	node_pop_back(node_t **nodes)
{
	node_t *actual = *nodes;

	while (actual->next->next)
		actual = actual->next;
	
	free(actual->next);
	actual->next = NULL;
}

void	node_swap_front(node_t **nodes)
{
	node_t *first = *nodes;
	node_t *next = (*nodes)->next;

	first->prev = next;
	first->next = next->next;
	first->index++;
	next->next = first;
	next->prev = NULL;
	next->index--;

	*nodes = next;
}

void	node_swap_back(node_t **nodes)
{
	node_t *actual = *nodes;
	node_t *first = NULL;
	node_t *next = NULL;


	while (actual->next->next)
		actual = actual->next;
	
	first = actual;
	next = actual->next;
	first->index++;
	first->prev->next = next;
	next->prev = first->prev;
	first->prev = next;
	first->next = next->next;
	next->next = first;
	next->index--;

	actual = next;
}

void	node_reverse(node_t **nodes)
{
	node_t *end = (*nodes)->next;
	node_t *first = *nodes;
	node_t *tmp = NULL;
	node_t *next = NULL;

	if (!end)
		return;

	while (end->next)
		end = end->next;
	
	tmp = end;
	first->prev = first->next;
	first->next = NULL;
	end = first;
	first = tmp;

	tmp = first;
	first->next = first->prev;
	first->index++;

	while (first->next) {
		next = first->next;
		first->next = first->prev;
		first->prev = next;
		first = first->next;
	}

	*nodes = tmp;
}