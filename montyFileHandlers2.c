#include "monty.h"

/**
* call_required_function - calls the required function
* @func: pointer
* @op: string rep of opcode
* @val: string rep a numeric value
* @ln: line number
* @format: 0 for stack, 1 for queue
*/

void call_required_function(void (*func)(stack_t **, unsigned int), char *op,
char *val, int ln, int format)
{
	stack_t *node;
	int multiplier = 1, a;

	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val++;
			multiplier = -1;
		}
		if (val == NULL || !isdigit(val[0]))
			error_handler(5, ln);
		for (a = 0; val[a] != '\0'; a++)
		{
			if (!isdigit(val[a]))
				error_handler(5, ln);
		}
		node = create_stack_node(atoi(val) * multiplier);
		if (format == 0)
			func(&node, ln);
		else if (format == 1)
			add_node_to_queue(&node, ln);
	}
	else
	{
		func(&head, ln);
	}
}
