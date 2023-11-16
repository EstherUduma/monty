#include "monty.h"

/**
* create_stack_node - create a new stack node
* @n: the integer value to store in the new node
* Return: a pointer
*/
stack_t *create_stack_node(int n)
{
	stack_t *node;

	do {
		node = malloc(sizeof(stack_t));
		if (node == NULL)
		{
			error_handler(4);
			break;
		}

		node->next = NULL;
		node->prev = NULL;
		node->n = n;
	} while (0);
	return (node);
}

/**
* free_stack_nodes - the function that frees the stack nodes
*
*/

void free_stack_nodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	do {
		temp = head;
		head = head->next;
		free(temp);
	} while (head != NULL)
}

/**
* add_node_to_queue - this function adds node to a queue
* @new_node: the new node of the queue
* @line_number: the line number of the queue
*/

void add_node_to_queue(stack_t **new_node, __attribute__((unusued))
unsigned int line_number)
{
	stack_t *temp;

	if (*new_node == NULL || new_node == NULL)
		error_handler(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *new_node;
	(*new_node)->prev = temp;
}

/**
* add_node_to_stack - adding a node to a stack
* @new_node: pointer to the new node to be added
* @line_number: integer of the line number of the opcode
*/

void add_node_to_stack(stack_t **new_node, __attribute__((unused))
unsigned int line_number)
{
	if (*new_node == NULL || new_node == NULL)
		error_handler(EXIT_ FAILURE);
	(*new_node)->next = head;
	(*new_node)->prev = NULL;
	if (head != NULL)
		head->prev = *new_node;
	head = *new_node;
}

/**
* print_stack_elements - prints tyhe element of the stack
* @stack: pointer to s pointer
* @line_number: integer representing the line number of the opcode
*/

void print_stack_elements(stack_t **stack, __attribute__((unused))
unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || stack == NULL)
		return;
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
