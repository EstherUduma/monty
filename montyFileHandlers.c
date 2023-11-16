#include "monty.h"

/**
* open_and_process_file - opens and processes file
* @file_name: the name of the file
* Return: void
*/

void open_and_process_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (fd == NULL || file_name == NULL)
		error_handler(2, file_name);
	read_and_process_file(fd);
	fclose(fd);
}

/**
* read_and_process_file - this reads and process the file
* @file: a pointer to the fd
* Return: void
*/

void read_and_process_file(FILE *file)
{
	int line_number = 1, format = 0;
	char *line_buffer = NULL;
	size_t buffer_length = 0;

	while (getline(&line_buffer, &buffer_length, file) != -1)
	{
		fomat = parse_line(line_buffer, line_number++, format);
	}
	free(line_buffer);
}

/**
* parse_line - parses a line from the file and determine its operations
* @buffer: the line from the file to parse
* @line_number: the line number
* @format: 0 for stack, 1 for queue
* Return: 0 for stack, 1 for queue
*/

int parse_line(char *buffer, int line_number, int format)
{
	char *value;
	const char *delimeters = "\n ";
	char *opcode = strtok(buffer, delimeters);

	if (buffer == NULL)
	{
		error_handler(4);
		return (format);
	}
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delimeters);
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	find_and_execute_function(opcode, value, line_number, format);

	return (format);
}

/**
* find_and_execute_function  - finds and executes the function
* @opcode: opcode to be worked on
* @value: the argument passed
* @ln: the line number where the opcode is
* @format: 0 for stack, 1 for queue
* Return: void
*/

void find_and_execute_function(char *opcode, char *value, int ln, int format)
{
	int found = 1, a;

	instruction_t function_list[] = {
		{"push", add_node_to_stack},
		{"pall", print_stack_elements},
		{"pint", print_top},
		{"pop", pop_node},
		{"nop", no_operation},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", subtract_nodes},
		{"div", divide_nodes},
		{"mul", multiply_nodes},
		{"mod", modulus_nodes},
		{"pchar", print_char},
		{"pstr", print_string},
		{"rotl", rotate_left},
		{"rotr", rotate_right},
		{NULL, NULL}};

	if (opcode[0] == '#')
		return;
	for (a = 0; function_list[a].opcode != NULL; a++)
	{
		if (strcmp(opcode, function_list[a].opcode) == 0)
		{
			call_required_function(function_list[a].f, opcode, value, ln, format);
			found = 0;
			break;
		}
	}
	if (found)
		error_handler(3, ln, opcode);
}

/**
* call_required_function - calls the required function
* @func: pointer
* @op: string rep of opcode
* @val: string representing a numeric value
* @ln: line number
* @format: 0 for stack 1 for queue
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
			error_handler(5, ln);  /**error handler*/
		for (a = 0; val[a] != '\0'; a++)
		{
			if (!isdigit(val[a]))
				error_handler(5, ln);
		}
		node = create_stack_node(atoi(val) multiplier);
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
