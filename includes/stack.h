#pragma once
#include <stdint.h>
#include <stddef.h>

///////////////////////////////////////////////
//
//            TYPEDEFS
//
////////////////////////////////////////////////

typedef uint8_t bool_t;
typedef	struct	stack_t stack_t;

///////////////////////////////////////////////
//
//            STRUCTS
//
////////////////////////////////////////////////

struct	stack_t
{
	stack_t *next;
	char *data;
	int key;
};

///////////////////////////////////////////////
//
//           STACKS FUNCTIONS
//
////////////////////////////////////////////////

stack_t	*create_void_stack(void);
stack_t *create_few_stack(int n);
stack_t *create_stack(char *data);
stack_t *get_stack(stack_t *stack, int key);
stack_t *set_element_in_stack(stack_t *stack, char *data, int key);
size_t	get_stack_size(stack_t *stack);
void	free_stack(stack_t **stack, bool_t opt);
void	print_stack(stack_t *stack);

void	stack_push(stack_t **stack, stack_t *new);
void	stack_pop(stack_t **stack);
void	stack_push_back(stack_t **stack, stack_t *new);
void	stack_pop_back(stack_t **stack);