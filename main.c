#include <stdio.h>
#include "dsa.h"

int main(void)
{
	node_t *n = create_node((char *)"hello");
	node_t *n2 = create_node((char *)"world");
	node_t *n3 = create_node((char *)" and im beautiful but lil");

	node_push_back(&n, n2);
	node_push_back(&n, n3);

	node_swap_back(&n);

	printf("%s\n", (char *)n->next->data);

	free_all_nodes(&n, 0);

	return (0);
}