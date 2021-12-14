#include <stdlib.h>
#include <stdio.h>
#include "dsa.h"

void	say_hello(void *args)
{
	printf("%s\n", (char *) args);
	
	return;
}

int main(void)
{
	queue_t *q = create_queue("sayhello", say_hello);

	q->cb((char *) "hello");

	free(q);

	return (0);
}