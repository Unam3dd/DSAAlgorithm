#include "queue.h"
#include "utils.h"
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
	ptr->args = NULL;
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
	queue_t *save = ptr;

	for (int i = 1; i < n; i++) {
		ptr->args = NULL;
		ptr->cb = NULL;
		ptr->key = NULL;
		ptr->next = (queue_t *) (ptr + i * sizeof(queue_t));
		ptr = ptr->next;
	}

	return (save);
}

queue_t *get_queue(queue_t *queue, char *key)
{
	while (queue && ft_strcmp(key, queue->key))
		queue = queue->next;
	
	return (queue);
}

queue_t *set_queue(queue_t *queue, char *key, char *args, callback_t cb)
{
	queue->key = key;
	queue->args = args;
	queue->cb = cb;

	return (queue);
}

void	execute_callback(queue_t *queue)
{
	while (queue) {
		queue->cb(queue->args);
		queue = queue->next;
	}
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
	if (opt) {
		free(*queue);
		*queue = NULL;
		return;
	}

	queue_t *next = NULL;
	
	while (*queue) {
		next = (*queue)->next;
		free(*queue);
		*queue = next;
	}

	*queue = NULL;
}