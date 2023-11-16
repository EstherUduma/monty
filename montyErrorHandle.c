#include "monty.h"

/**
* error_handler - handles error display
* (1) => user provided no file or more file to the program
* (2) => provided file cannot be opened or read
* (3) => file contains an invalid instruction
* (4) => failure when allocating memory
* (5) => parameter passed to the push instruction is not an integer
* (6) => attempt to perform pint on an empty stack
* (7) => attempt to perform pop on an empty stack
* (8) => attempt to perform an operation on a stack that is too short
* @error_code: error code to determine error message
* Return: nothing after displaying the error message
*/

void error_handler(int error_code, ...);
void error_handler(int error_code, ...)
{
	va_list args;

	va_start(args, error_code);
	switch (error_code)
	{
		case 1:
		fprintf(stderr, "USAGE: monty file\n");
		break;

		case 2:
		fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
		break;

		case 3:
		fprintf(stderr, "L%d: unknown instruction %s\n", va_arg(args, int),
		va_arg(args, char *));
		break;

		case 4:
		fprintf(stderr, "Error: malloc failed\n");
		break;

		case 5:
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
		break;

		case 6:
		fprintf(stderr, "L%d: can't pint an empty stack\n", va_arg(args, int));
		break;

		case 7:
		fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
		break;

		case 8:
		fprintf(stderr, "L%d: can't %s, stack too short\n", va_arg(args, int),
		va_arg(args, char *));
		break;

		default:
		break;
	}
	va_end(args);
	free_stack_nodes();
	exit(EXIT_FAILURE);
}

/**
* error_handler2 - handle and displays error messages based on error codes
* (6) => an attempt to execute "pint" on an empty stack
* (7) => an attempt to execute "pop" on an empty stack
* (8) => a stack is too short to perform an operation
* (9) => a division by zero error
* @error_code: the error code to determine an error message
* Return: nothing
*/

void error_handler2(int error_code, ...)
{
	va_list args;

	va_start(args, error_code);
	switch (error_code)
	{
		case 6:
		fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
		break;

		case 7:
		fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
		break;

		case 8:
		fprintf(stderr, "L%d: can't %s, stack too short\n", va_arg(args, int),
		va_arg(args, char *));
		break;

		case 9:
		fprintf(stderr, "L%d: division by zero\n", va_arg(args, int));
		break;
	}
	va_end(args);
	free_stack_nodes();
	exit(EXIT_FAILURE);
}

/**
* error_handler3 - handle and display specific error based on error code
* (10) => the number inside the node is outside the ASCII bounds
* (11) => an attempt to execute pchar on an empty stack
* @error_code: the error code determines the error message
* Return: nothing
*/

void error_handler3(int error_code, ...)
{
	va_list args;

	va_start(args, error_code);
	switch (error_code)
	{
		case 10:
		fprintf(stderr, "L%d: can't pchar, value out of range\n", va_arg(args, int));
		break;

		case 11:
		fprintf(stderr, "L%d: can't pchar, stack empty\n", va_arg(args, int));
		break;

		default:
		break;
	}
	va_end(args);
	free_stack_nodes();
	exit(EXIT_FAILURE);
}
