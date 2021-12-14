#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "dsa.h"

int main(void)
{
	stack_t *s = create_stack("hello");
	stack_t *new = create_stack("world");

	stack_push_back(&s, new);

	printf("%s\n%s\n", s->data, s->next->data);

	if (!set_element_in_stack(s, "toto", 0))
		fprintf(stderr, "[-] Error set element !\n");

	printf("\n%s\n%s\n", s->data, s->next->data);

	free_stack(&s, 0xF);

	return (0);
}