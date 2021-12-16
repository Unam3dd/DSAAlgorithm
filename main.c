#include <stdio.h>
#include "dsa.h"

int main(void)
{
	node_t *n = create_node((char *)"hello");
	node_t *n2 = create_node((char *)"world");
	node_t *n3 = create_node((char *)" and im beautiful but lil");
	node_t *n4 = create_node((char *)"test");

	node_push_back(&n, n2);
	node_push_back(&n, n3);

	node_swap_back(&n);

	if (node_insert(&n, n4, 1))
		fprintf(stderr, "[-] Error insert nodes !\n");

	printf("%ld\n", n->next->next->index);

	free_all_nodes(&n, 0);

	return (0);
}