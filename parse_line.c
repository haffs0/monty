#include "monty.h"
/**
 * parse_line - parse line and return the proper instruction
 * @line: the strings
 *
 * Return: a pointer to the instruction
 */
instruction_t *parse_line(char *line)
{
	char *opcode;
	instruction_t *instruction;

	opcode = get_opcode(line);
	instruction = malloc(sizeof(instruction_t));

	if (instruction == NULL)
	{
		fprintf(stdout, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	instruction->opcode = opcode;
	instruction->f = NULL;

	if (instruction->opcode)
	{
		if (strcmp(instruction->opcode, "push") == 0)
			instruction->f = push;
		if (strcmp(instruction->opcode, "pall") == 0)
			instruction->f = pall;
	}
	return (instruction);
}
