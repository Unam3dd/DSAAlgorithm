#include "node.h"
#include <stdlib.h>

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
		ptr->next = NULL;
		ptr->prev = NULL;
		ptr->next = (node_t *) (ptr + sizeof(node_t) * i);
		ptr = ptr->next;
	}

	return (save);
}

node_t	*nodes_get_by_index(node_t **nodes, size_t index);
node_t	*node_shift(node_t **nodes);
node_t 	*node_append(node_t **nodes);
size_t	node_get_size(node_t **nodes);

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

void	node_push(node_t **nodes, node_t *new);
void	node_pop(node_t **nodes);
void	node_push_back(node_t **nodes, node_t *new);
void	node_pop_back(node_t **nodes);
void	node_insert(node_t **nodes, node_t *new, size_t index);
void	node_swap_front(node_t **nodes);
void	node_swap_back(node_t **nodes);
void	node_exchange_value(node_t *node_1, node_t *node_2);
void	node_reverse(node_t **nodes);