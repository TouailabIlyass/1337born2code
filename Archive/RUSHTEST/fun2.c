#include <stdlib.h>
#include <stdio.h>
#include "struc.h"
void    supp_posibilite(sudoku **head, int value);

void	affpos(sudoku *l)
{
	while (l)
	{
		printf("%d |", l->value);
		l = l->next;
	}
}

void	viderList(sudoku **l)
{
	sudoku *tmp;

	if ((*l) == NULL)
	{
		free(l);
		return ;
	}
	tmp = *l;
	while (l)
	{
		tmp = *l;
		*l = (*l)->next;
		free(tmp);
	}
}

int	count_list(sudoku *l)
{
	int c;

	c = 0;
	while (l)
	{
		c++;
		l = l->next;
	}
	return (c);
}

void	suppArbre(arbre *a, int value)
{
	while (a)
	{
		supp_posibilite(&(a->debut), value);
		a = a->next;
	}
}

sudoku	Union(arbre *a)
{
	sudoku	l1;
	sudoku	*l2;
	sudoku	*l3;
	int		cp;
	arbre	*tmp;
	int		trouve;

	tmp = a;
//	l1= {0, NULL,'n', -1, -1};
	while (a)
	{
		l3 = a->debut;
		trouve = 0;
		while (l3)
		{
			tmp = a->next;
			trouve = 0;
			while (tmp)
			{
				l2 = tmp->debut;
				while (l2)
				{
					if (l3->value == l2->value)
					{
						trouve = 1;
						suppArbre(a, l2->value);
						break ;
					}
					l2 = l2->next;
				}
				if (trouve == 1)
				{
					break ;
				}
				tmp = tmp->next;
			}
			if (trouve == 0)
			{
				l1 = *l3;
				return (l1);
			}
			l3 = l3->next;
		}
		a = a->next;
	}
	return (l1);
}