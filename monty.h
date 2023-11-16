#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack or queue)
* @next: points to the next element of the stack (or queue)
* Description: doubly linked list node structure
* for stack, queue, LIFO, FIFO
*/

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: fucntion to handle the opcode
* Description: opcode and its function
* for stack, queue, LIFO, FIFO
*/

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void open_and_process_file(char *file_name);
void read_and_process_file(FILE *file);
int parse_line(char *buffer, int line_number, int format);
void find_and_execute_function(char *opcode, char *value, int ln, int format);
void call_required_function(void
(*func)(stack_t **, unsigned int), char *op, char *val, int ln, int format);
void add_node_to_stack(stack_t **stack, unsigned int line_number);
void print_stack_elements(stack_t **stack, unsigned int line_number);
stack_t *create_stack_node(int n);
void free_stack_nodes(void);
void add_node_to_queue(stack_t **new_node, unsigned int line_number);
void error_handler(int error_code, ...);
void error_handler2(int error_code, ...);
void error_handler3(int error_code, ...);
extern stack_t *head;
void call_required_function(void (*func)(stack_t **, unsigned int), char *op,
char
#endif
