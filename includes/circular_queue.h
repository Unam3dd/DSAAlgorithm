#pragma once
#include "types_.h"
#include <stddef.h>


///////////////////////////////////////////////
//
//            TYPEDEFS
//
////////////////////////////////////////////////

typedef	struct	circular_queue_t circular_queue_t;

///////////////////////////////////////////////
//
//            STRUCT
//
////////////////////////////////////////////////

struct	circular_queue_t
{
	circular_queue_t	*next;
	char				*key;
	char				*data;
};

///////////////////////////////////////////////
//
//           CIRCULAR QUEUE FUNCTIONS
//
////////////////////////////////////////////////

circular_queue_t	*create_circular_queue(char *key, char *data);
circular_queue_t	*create_circular_void_queue(void);
circular_queue_t	*create_circular_few_queue(size_t n);
circular_queue_t	*get_circular_queue(circular_queue_t *queue, char *key);
void				circular_enqueue(circular_queue_t **queue, circular_queue_t *new);
void				circular_dequeue(circular_queue_t **queue);
void				circular_destroy_queue(circular_queue_t **queue, bool_t opt, size_t n);