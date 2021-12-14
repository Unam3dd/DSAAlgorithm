#include "queue.h"
#include <stdlib.h>

///////////////////////////////////////////////
//
//           QUEUE FUNCTIONS
//
////////////////////////////////////////////////

queue_t	*create_queue(char *key, callback_t cb)
{
	queue_t *ptr = (queue_t *)malloc(sizeof(queue_t));

	ptr->next = NULL;
	ptr->key = key;
	ptr->cb = cb;

	return (ptr);
}

queue_t	*create_void_queue(void)
{
	queue_t *ptr = (queue_t *)malloc(sizeof(queue_t));

	ptr->next = NULL;
	ptr->key = NULL;
	ptr->cb = NULL;

	return (ptr);
}

queue_t *create_few_queue(size_t n)
{
	if (!n || n < 0)
		return (NULL);
	
	queue_t *ptr = (queue_t *)malloc(sizeof(queue_t) * n);

	for (int i = 1; i < n; i++) {
		ptr->next = (queue_t *) (ptr + i * sizeof(queue_t));
		ptr = ptr->next;
	}

	return (ptr);
}


void	enqueue(queue_t **queue, queue_t *new)
{
	new->next = *queue;
	*queue = new;
}

void	dequeue(queue_t **queue)
{
	queue_t *actual = *queue;

	while (actual->next->next)
		actual = actual->next;

	free(actual->next);
	actual->next = NULL;
}

void	destroy_queue(queue_t **queue, bool_t opt)
{
	queue_t *next = NULL;
	
	while (*queue) {
		next = (*queue)->next;
		free(*queue);
		*queue = next;
	}

	*queue = NULL;
}