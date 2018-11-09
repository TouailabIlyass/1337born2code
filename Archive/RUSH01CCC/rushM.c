/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushpush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:56:51 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/29 16:46:24 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct sudoku	sudoku;
		struct	sudoku
{
	int		value;
	sudoku	*next;
	char	is_const;
	int		i;
	int		j;
};

typedef	struct arbre	arbre;
		struct	arbre
{
	sudoku	*debut;
	arbre	*next;
};

arbre	*create_arbre(sudoku *l)
{
	arbre	*element;

	element = (arbre*)malloc(sizeof(arbre));
	element->debut = l;
	element->next = NULL;
	return (element);
}

void	add_arbre(arbre **head, sudoku *l)
{
	arbre *tmp;
	arbre *elem;

	tmp = *head;
	elem = create_arbre(l);
	if (*head == NULL)
	{
		*head = elem;
		return ;
	}
	*head = elem;
	elem->next = tmp;
}

sudoku	*create_posibilite(int value, int i, int j)
{
	sudoku *element;

	element = (sudoku*)malloc(sizeof(sudoku));
	element->value = value;
	element->next = NULL;
	element->is_const = 'n';
	element->i = i;
	element->j = j;
	return (element);
}



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



int main(int argc, char **argv)
{
	int Sudoku[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
					{5, 2, 0, 0, 0, 0, 0, 0, 0},
					{0, 8, 7, 0, 0, 0, 0, 3, 1},
					{0, 0, 3, 0, 1, 0, 0, 8, 0},
					{9, 0, 0, 8, 6, 3, 0, 0, 5},
					{0, 5, 0, 0, 9, 0, 6, 0, 0},
					{1, 3, 0, 0, 0, 0, 2, 5, 0},
					{0, 0, 0, 0, 0, 0, 0, 7, 4},
					{0, 0, 5, 2, 0, 6, 3, 0, 0}};

	posi(Sudoku);
	affichage(Sudoku);
	return (0);
}
