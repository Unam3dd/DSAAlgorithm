#include "stack.h"
#include "writef.h"
#include <stdlib.h>


///////////////////////////////////////////////
//
//           FUNCTION STACK UTILS
//
////////////////////////////////////////////////

stack_t	*create_void_stack(void)
{
	stack_t *ptr = (stack_t *)malloc(sizeof(stack_t));

	ptr->data = NULL;
	ptr->next= NULL;
	ptr->key = 0;

	return (ptr);
}

stack_t *create_few_stack(size_t n)
{
	if (!n || n < 0)
		return (NULL);
	
	stack_t *ptr = (stack_t *)malloc(sizeof(stack_t) * n);
	stack_t *save = ptr;

	for (int i = 1; i < n; i++) {
		ptr->data = NULL;
		ptr->key = 0;
		ptr->next = (stack_t *) (ptr + i * sizeof(stack_t));
		ptr = ptr->next;
	}

	return (save);
}

stack_t *create_stack(char *data)
{
	stack_t *ptr = (stack_t *)malloc(sizeof(stack_t));

	ptr->data = data;
	ptr->next = NULL;
	ptr->key = 0;

	return (ptr);
}

stack_t *get_stack(stack_t *stack, int key)
{
	while (stack && key != stack->key)
		stack = stack->next;
	
	return (stack);
}

stack_t *set_element_in_stack(stack_t *stack, char *data, int key)
{
	while (stack && stack->key != key)
		stack = stack->next;
	
	if (!stack)
		return (NULL);
	
	stack->data = data;
	
	return (stack);
}

size_t	get_stack_size(stack_t *stack)
{
	size_t i = 0;
	
	while (stack)
		stack = stack->next;
	
	return (i);
}

void	free_stack(stack_t **stack, bool_t opt)
{
	if (opt) {
		free(*stack);
		*stack = NULL;
		return;
	}

	stack_t *next = NULL;

	while (*stack) {
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}

	*stack = NULL;
}

void	print_stack(stack_t *stack)
{
	while (stack) {
		writef("Key : %d : Data : %s\n", stack->key, stack->data);
		stack = stack->next;
	}
}

void	stack_push(stack_t **stack, stack_t *new)
{
	(*stack)->key++;
	new->next = *stack;
	*stack = new;
}

void	stack_pop(stack_t **stack)
{
	stack_t *next = (*stack)->next;
	next->key--;
	free(*stack);
	*stack = next;
}

void	stack_push_back(stack_t **stack, stack_t *new)
{
	stack_t *actual = *stack;

	while (actual->next)
		actual = actual->next;
	
	new->key = actual->key + 1;
	new->next = NULL;
	actual->next = new;
}

void	stack_pop_back(stack_t **stack)
{
	stack_t *actual = *stack;

	while (actual->next->next)
		actual = actual->next;
	
	free(actual->next);
	
	actual->next = NULL;
}