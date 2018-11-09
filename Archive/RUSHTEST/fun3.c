#include <unistd.h>
#include "struc.h"

void	affpos(sudoku *l);

void	affArbre(arbre *a)
{
	sudoku	*tmp;

	while (a)
	{
		tmp = a->debut;
		affpos(tmp);
		a = a->next;
	}
}

int	is_in_square(int t[9][9], int row, int col, int value)
{
	int i;
	int j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (t[i + row][j + col] == value)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_in_row(int t[9][9], int row, int col, int value)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (t[i][col] == value)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_in_col(int t[9][9], int row, int col, int value)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (t[row][i] == value)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
