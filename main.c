#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "dsa.h"

int main(void)
{
	node_t *n = create_node((char *)"hello");
	node_t *n2 = create_node((char *)"world");
	node_t *n3 = create_node((char *)"and im beautiful but lil");
	node_t *n4 = create_node((char *)"test");

	printf("%ld\n", sizeof(node_t) * 17);

	printf("%ld\n", sizeof(node_t));

	node_push_back(&n, n2);
	node_push_back(&n, n3);

	if (node_insert(&n, n4, 1))
		fprintf(stderr, "[-] Error insert nodes !\n");

	node_reverse(&n);

	printf("%d\n", n->next->next->next->next == NULL);

	free_all_nodes(&n, 0);

	return (0);
}