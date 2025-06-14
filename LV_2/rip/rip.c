#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	min_removals(char *input, size_t inputLen, size_t *rem_l, size_t *rem_r)
{
	size_t balance = 0;
	size_t i = 0;

	while (i < inputLen)
	{
		if (input[i] == '(')
			balance++;
		else if (input[i] == ')')
		{
			if (balance == 0)
				(*rem_r)++;
			else
				balance--;
		}
		i++;
	}
	*rem_l = balance;
}

void	rip(char *input, size_t i, char *result, size_t rm_open, size_t rm_close, int open)
{
	// finish
	if (input[i] == '\0')
	{
		if (rm_open == 0 && rm_close == 0 && open == 0)
		{
			result[i] = '\0';
			printf("%s\n", result);
		}
		return ;
	}
	// not a para
	if (input[i] != '(' && input[i] != ')')
	{
		result[i] = input[i];
		rip(input, i + 1, result, rm_open, rm_close, open);
		return ;
	}
	// remove
	if (input[i] == '(' && rm_open > 0)
	{
		result[i] = ' ';
		rip(input, i + 1, result, rm_open - 1, rm_close, open);
	}
	if (input[i] == ')' && rm_close > 0)
	{
		result[i] = ' ';
		rip(input, i + 1, result, rm_open, rm_close - 1, open);
	}
	// keep
	if (input[i] == '(')
	{
		result[i] = '(';
		rip(input, i + 1, result, rm_open, rm_close, open + 1);
	}
	if (input[i] == ')' && open > 0)
	{
		result[i] = ')';
		rip(input, i + 1, result, rm_open, rm_close, open - 1);
	}
}

int main(int ac, char *av[])
{
	if (ac != 2)
		return 1;
	char *input = av[1];
	size_t inputLen = strlen(input);
	char result[255] = {0};
	// char *result = malloc(strlen(input) + 1);
	size_t rm_open = 0;
	size_t rm_close = 0;

	min_removals(input, inputLen, &rm_open, &rm_close);

	rip(input, 0, result, rm_open, rm_close, 0);
	// free(result);
}