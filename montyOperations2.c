#include "monty.h"

/**
* pop_node - Remove the top node from the stack
* @stack: pointer to the pointer pointing to the top node of the stack
* @line_number: line number of the opcode
*/

void pop_node(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack)
		error_handler2(7, line_number);
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
* print_top - prints the top node of the stack
* @stack: pointer to the pointer pointing to the top node of the stack
* @line_number: line number of the opcode
*/

void print_top(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
		error_handler2(6, line_number);
	printf("%d\n", (*stack)->n);
}

/**
* multiply - multiplies the top two elements of the stack
* @stack: pointer to the pointer pointing to the top of the stack
* @line_number: line number of the opcode
*/

void multiply(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
		error_handler2(8, line_number, "mul");
	*stack = (*stack)->next;
	(*stack)->n *= (*stack)->prev->n;
	free(stack);
}

/**
* modulus - computes the modulus of the top two elements of the stack
* @stack: pointer to the ponter pointing to the top of the stack
* @line_number: line number of the opcode
*/

void modulus(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
		error_handler2(8, line_number, "mod");
	if ((*stack)->n == 0)
		error_handler2(9, line_number);
	*stack = (*stack)->next;
	(*stack)->n %= (*stack)->prev->n;
	free(stack);
}
