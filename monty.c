#include "monty.h"
int SQ = 1;
/**
 * main - entry level function
 * @argc: argument count
 * @argv: array of argument strings
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	FILE *file_in;
	char *line;
	stack_t *top = NULL;
	instruction_t *instruction = NULL;
	unsigned int line_count;
	size_t bufsize = 0;

	if (argc != 2)
	{
		fprintf(stdout, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &bufsize, file_in) != -1)
	{
		line_count++;
		instruction = parse_line(line);

		if (!(instruction->opcode) || instruction->opcode[0] == '#')
		{
			free(instruction);
			if (line)
				free(line);
			line = NULL;
			continue;
		}

		if (instruction->f)
			instruction->f(&top, line_count);
		else
		{
			fprintf(stdout, "L%d: unknown instruction %s\n", line_count, instruction->opcode);
			if (line)
				free(line);
			if (top)
				free_stack(top);
			free(instruction);
			fclose(file_in);
			exit(EXIT_FAILURE);
		}

		if (line)
			free(line);
		line = NULL;
		free(instruction);
	}

	if (line)
		free(line);
	free_stack(top);
	fclose(file_in);

	return (0);
}
