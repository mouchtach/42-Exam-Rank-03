#include <unistd.h>
#include <stdlib.h>


void put_bnr(int nb)
{
    char c;

    if(nb >= 10)
    {
        put_bnr (nb / 10);
        c = (nb % 10 ) + '0';
        write(1, &c, 1);
    }
    else
    {
        c = nb  + '0';
        write(1, &c, 1);
    }
}

void print_solution(int *positions, int n)
{
    char c;
	int i = 0;

	while(i < n)
	{
        put_bnr(positions[i]);
        write(1, " ", 1);
        i++;
	}
    write(1, "\n", 1);
}

int is_safe(int *positions, int current_col, int current_row)
{
	int prev_col = 0;
	int prev_row ;

	while(prev_col < current_col)
	{
		prev_row = positions[prev_col];
        if (prev_row == current_row ||
            prev_row - prev_col == current_row - current_col ||
            prev_row + prev_col == current_row + current_col)
            return 0;

		prev_col++;
	}
    return 1;
}

void solve_n_queens(int *positions, int current_col, int n)
{
    if (current_col == n)
    {
        print_solution(positions, n);
        return;
    }
    int row = 0;
	while(row < n)
	{
		if (is_safe(positions, current_col, row))
        {
            positions[current_col] = row;
            solve_n_queens(positions, current_col + 1, n);
        }
		row++;
	}
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return (1);
    
    int n = atoi(argv[1]);
    if (n <= 0)
        return (1);
    
    int *positions = malloc(n * sizeof(int));
    if (!positions)
        return (1);
    
    solve_n_queens(positions, 0, n);
    
    free(positions);
    return (0);
}