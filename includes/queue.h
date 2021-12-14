#pragma once
#include "types_.h"
#include <stddef.h>


///////////////////////////////////////////////
//
//            TYPEDEFS
//
////////////////////////////////////////////////

typedef	struct	queue_t queue_t;

///////////////////////////////////////////////
//
//            STRUCT
//
////////////////////////////////////////////////

struct	queue_t
{
	queue_t	*next;
	char	*key;
	callback_t cb;
};

///////////////////////////////////////////////
//
//           QUEUE FUNCTIONS
//
////////////////////////////////////////////////

queue_t	*create_queue(char *key, callback_t cb);
queue_t	*create_void_queue(void);
queue_t *create_few_queue(size_t n);
void	enqueue(queue_t **queue, queue_t *new);
void	dequeue(queue_t **queue);
void	destroy_queue(queue_t **queue, bool_t opt);