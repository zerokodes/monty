#include "monty.h"

/**
 * run_func - run's specified function
 * @cmd: data to pass to function
 */
void run_func(cmd_t *cmd)
{
	instruction_t funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack_mode},
		{"queue", queue_mode},
		{NULL, NULL}
	};
	int i = 0;

	while (funcs[i].opcode)
	{
		if (strcmp(cmd->op, funcs[i].opcode) == 0)
		{
			funcs[i].f(cmd);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", cmd->line_number, cmd->op);
	exit(EXIT_FAILURE);
}
