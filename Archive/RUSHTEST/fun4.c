#include <stdio.h>
#include "struc.h"

void    add_posibilite(sudoku **head, int value, int i, int j);
void    add_arbre(arbre **head, sudoku *l);
int	is_in_col(int t[9][9], int row, int col, int value);
int	is_in_row(int t[9][9], int row, int col, int value);
int	is_in_square(int t[9][9], int row, int col, int value);
sudoku	Union(arbre *a);

void	affichage(int t[9][9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			printf("%d | ", t[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	reapeat(int t[9][9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (t[i][j] == 0)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

arbre	*remplir(int t[9][9], int si, int sj, int *cp, sudoku **debut)
{
	arbre	*a;
	int		i;
	int		j;
	int		k;

	a = NULL;
	i = si - 3;
	while (i < si)
	{
		j = sj - 3;
		while (j < sj)
		{
			if (t[i][j] == 0)
			{
				k = 1;
				*cp = 0;
				*debut = NULL;
				while (k <= 9)
				{
					if (!is_in_square(t, i - i % 3, j - j % 3, k))
					{
						if (!is_in_row(t, i, j, k))
						{
							if (!is_in_col(t, i, j, k))
							{
								add_posibilite(debut, k, i, j);
								*cp = *cp + 1;
							}
						}
					}
					k++;
				}
				add_arbre(&a, *debut);
			}
			j++;
		}
		i++;
	}
	return (a);
}

void	posi(int t[9][9])
{
	int		si;
	int		sj;
	int		l;
	int		c;
	int		cp;
	sudoku	*debut;
	arbre	*a;

	while (reapeat(t) == 1)
	{
		l = 0;
		si = 0;
		sj = 0;
		debut = NULL;
		a = NULL;
		while (l < 3)
		{
			c = 0;
			si += 3;
			sj = 0;
			while (c < 3)
			{
				sj += 3;
				a = remplir(t, si, sj, &cp, &debut);
				if (cp != 1)
				{
					sudoku x;
					x = Union(a);
					if (x.value != 0)
					{
						t[x.i][x.j] = x.value;
					}
				}
				else if (cp == 1 && debut)
				{
					sudoku x;
					x = *debut;
					t[x.i][x.j] = x.value;
				}
				a = NULL;
				c++;
			}
			l++;
		}
	}
}