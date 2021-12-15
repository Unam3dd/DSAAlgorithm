#include <stdio.h>
#include "dsa.h"


int main(void)
{
	circular_queue_t *cq = create_circular_queue("hello", "world");
	circular_queue_t *new_q = create_circular_queue("hello2", "world2");

	circular_enqueue(&cq, new_q);

	printf("%s\n%s\n", cq->data, cq->next->next->data);

	circular_destroy_queue(&cq, 0, 2);

	return (0);
}