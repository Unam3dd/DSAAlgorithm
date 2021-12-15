#include "circular_queue.h"
#include "utils.h"
#include <stdlib.h>

circular_queue_t	*create_circular_queue(char *key, char *data)
{
	circular_queue_t *ptr = (circular_queue_t *)malloc(sizeof(circular_queue_t));

	ptr->next = NULL;
	ptr->data = data;
	ptr->key = key;
	
	return (ptr);
}

circular_queue_t	*create_circular_void_queue(void)
{
	circular_queue_t *ptr = (circular_queue_t *)malloc(sizeof(circular_queue_t));

	ptr->key = NULL;
	ptr->data = NULL;
	ptr->next = NULL;

	return (ptr);
}

circular_queue_t	*create_circular_few_queue(size_t n)
{
	if (!n || n < 0)
		return (NULL);
	
	circular_queue_t *ptr = (circular_queue_t *)malloc(sizeof(circular_queue_t) * n);
	circular_queue_t *save = ptr;

	for (int i = 1; i < n; i++) {
		ptr->data = NULL;
		ptr->key = NULL;
		ptr->next = (circular_queue_t *) (ptr + sizeof(circular_queue_t) * i);
		ptr = ptr->next;
	}

	return (save);
}

circular_queue_t	*get_circular_queue(circular_queue_t *queue, char *key)
{
	while (queue && ft_strcmp(key, queue->key))
		queue = queue->next;
	
	return (queue);
}

void				circular_enqueue(circular_queue_t **queue, circular_queue_t *new)
{
	(*queue)->next = new;
	new->next = (*queue);
	*queue = new;
}

void				circular_dequeue(circular_queue_t **queue)
{
	circular_queue_t *actual = *queue;
	circular_queue_t *save = *queue;

	while (actual->next->next)
		actual = actual->next;
	
	free(actual->next);
	actual->next = save;
}

void				circular_destroy_queue(circular_queue_t **queue, bool_t opt, size_t n)
{
	if (opt) {
		free(*queue);
		*queue = NULL;
		return;
	}

	circular_queue_t *next = NULL;

	for (int i = 0; i < n; i++) {
		next = (*queue)->next;
		free(*queue);
		*queue = next;
	}
	
	*queue = NULL;
}