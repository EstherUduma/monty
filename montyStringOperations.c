#include "monty.h"

/**
* print_char - prints the ASCII value
* @stack: pointer to the pointr of the top node of the stack
* @line_number: line number of the opcode
*/

void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii_value;

	if (!stack || !*stack)
		error_handler3(11, line_number);
	ascii_value = (*stack)->n;
	if (ascii_value < 0 || ascii_value > 127)
		error_handler3(10, line_number);
	printf("%c\n", ascii_value);
}

/**
* print_string - prints a string
* @stack: pointer to the pointer pointing to the top of the stack
* @line_number: line number of the opcode
*/

void print_string(stack_t **stack, __attribute__((unused))
unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack)
	{
		printf("\n");
		return;
	}
	temp = *stack;
	while (temp != NULL && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
* rotate_left - rotates the first node of the sack to the bottom
* @stack: pointer
* @line_number: line number of the opcode (unused)
*/

void rotate_left(stack_t **stack, __attribute__((unused))
unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
* rotate_right - rootates to the last node of the stack to the top
* @stack: pointer
* @line_number: line number of the opcode (unused)
*/

void rotate_right(stack_t **stack, __attribute__((nused))
unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
