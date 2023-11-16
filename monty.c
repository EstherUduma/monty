#include "monty.h"

/**
* main - the entry point of the program
* @argc: the number of command line arguments
* @argv: an array of strings of command line arguments
* Return: 0 if successful
*/

int main(int argc, char *argv[])
{
	if (!(argc == 2))
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_and_process_file(argv[1]);
	free_stack_nodes();

	return (0);
}
