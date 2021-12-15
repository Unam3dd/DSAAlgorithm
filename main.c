#include <stdlib.h>
#include <stdio.h>
#include "dsa.h"

void	callback_1_say_hello(void *ptr)
{
	printf("Hello\n");
}

void	callback_2_say_hello(void *ptr)
{
	printf("world\n");
}

int main(void)
{
	queue_t *q = create_queue("sayhello", callback_1_say_hello);
	queue_t *new = create_queue("sayhello2", callback_2_say_hello);

	enqueue(&q, new);

	execute_callback(q);

	destroy_queue(&q, 0);

	return (0);
}