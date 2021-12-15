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
	queue_t *q = create_few_queue(2);

	q->key = "test1";
	q->cb = callback_1_say_hello;

	set_queue(q->next,"test2", NULL, callback_2_say_hello);

	execute_callback(q);

	destroy_queue(&q, 1);

	return (0);
}