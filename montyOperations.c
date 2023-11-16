#include "monty.h"

/**
* no_operation - perform no operation
* @stack: pointer pointing to the top of the stack
* @line_number: line number of the opcode (unused)
*/

void no_operation(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
* swap_nodes - swaps the two top element of the stack
* @stack: pointer to a pointer to the top of the stack
* @line_number: line number of the opcode
*/

void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
		error_handler2(8, line_number, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;

	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
* add_nodes - adds the top two elements of the stack
* @stack: pointer to a pointer to the top of the stack
* @line_number: line number of the opcode
*/

void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (!stack || !*stack || !(*stack)->next)
		error_handler2(8, line_number, "add");
	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
* subtract_nodes - subtract the top two elements of the stack
* @stack: pointer to a pointer to the top of the stack
* @line_number: line number of the opcode
*/

void subtract_nodes(stack_t **stack, unsigned int line_number)
{
	int difference;

	if (!stack || !*stack || !(*stack)->next)
		error_handler2(8, line_number, "sub");
	(*stack) = (*stack)->next;
	difference = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = difference;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
* divide_nodes - divides the top two elements of the stack
* @stack: pointer to the pointer to the node at the top of the stack
* @line_number: line number of the opcode
*/

void divide_nodes(stack_t **stack, unsigned int line_number)
{
	int quotient;

	if (!stack || !*stack || !(*stack)->next)
		error_handler2(8, line_number, "div");
	if ((*stack)->n == 0)
		error_handler2(9, line_number);
	(*stack) = (*stack)->next;
	quotient = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = quotient;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
