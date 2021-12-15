#pragma once
#include "types_.h"
#include <stddef.h>

///////////////////////////////////////////////
//
//            TYPEDEFS
//
////////////////////////////////////////////////

typedef	struct	node_t node_t;

///////////////////////////////////////////////
//
//            STRUCTS
//
////////////////////////////////////////////////

struct	node_t
{
	node_t		*next;
	node_t		*prev;
	size_t		index;
	void 		*data;
};

///////////////////////////////////////////////
//
//           NODE FUNCTIONS
//
////////////////////////////////////////////////

node_t	*create_node(void *data);
node_t	*create_nodes(size_t n);
node_t	*nodes_get_by_index(node_t *nodes, size_t index);
node_t	*node_shift(node_t **nodes);
node_t 	*node_append(node_t **nodes, node_t *new);
size_t	node_get_size(node_t *nodes);
void 	destroy_node(node_t *node);
void	free_all_nodes(node_t **nodes, bool_t opt);
void	node_push(node_t **nodes, node_t *new);
void	node_pop(node_t **nodes);
void	node_push_back(node_t **nodes, node_t *new);
void	node_pop_back(node_t **nodes);
void	node_insert(node_t **nodes, node_t *new, size_t index);
void	node_swap_front(node_t **nodes);
void	node_swap_back(node_t **nodes);
void	node_exchange_value(node_t *node_1, node_t *node_2);
void	node_reverse(node_t **nodes);