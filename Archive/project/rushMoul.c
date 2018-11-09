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

void	add_posibilite(sudoku **head, int value, int i, int j)
{
	sudoku *elem;
	sudoku *tmp;

	elem = create_posibilite(value, i, j);
	if (*head == NULL)
	{
		*head = elem;
		return ;
	}
	tmp = *head;
	*head = elem;
	elem->next = tmp;
}

void	supp_posibilite(sudoku **head, int value)
{
	sudoku *tmp;

	tmp = *head;
	if (*head == NULL || (tmp->value != value && !tmp->next))
	{
		return ;
	}
	if (tmp->value == value)
	{
		*head = tmp->next;
		free(tmp);
		return ;
	}
	while (tmp->next->next && tmp->next->value != value)
	{
		tmp = tmp->next;
	}
	if (tmp->next->value == value)
	{
		sudoku *dp;

		dp = tmp->next;
		tmp->next = tmp->next->next;
		free(dp);
	}
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

int parcours(arbre *root, int value)
{
    sudoku  *list;
    int     trouve;
    arbre   *tmp;
    
    trouve = 0;
    tmp = root->next;
    while (tmp)
    {
        list = tmp->debut;
	    while (list)
        {
	        if (value == list->value)
	        {
		        trouve = 1;
		        suppArbre(root, list->value);
		        break ;
	        }
		    list = list->next;
    	}
    	if (trouve)
    	    return (trouve);
    	tmp = tmp->next;
    }
    return (trouve);
}





sudoku	recherche_possibilite(arbre *root)
{
	sudoku	l1= {0, NULL,'n', -1, -1};
	sudoku	*l3;
	arbre	*tmp;
	int		trouve;

	tmp = root;
	
	while (root)
	{
		l3 = root->debut;
		while (l3)
		{
			trouve = parcours(root,l3->value);
			if (trouve == 0)
			{
				l1 = *l3;
				return (l1);
			}
			l3 = l3->next;
		}
		root = root->next;
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

int check_possibilite(int t[9][9],int i, int j, sudoku **debut)
{
    int k;
    int cp;

    k = 1;
    cp = 0;
    while (k < 10)
    {
        if (!is_in_square(t, i - i % 3, j - j % 3, k))
		{
			if (!is_in_row(t, i, j, k))
			{
				if (!is_in_col(t, i, j, k))
				{
					add_posibilite(debut, k, i, j);
					cp = cp + 1;
				}
			}
		}
	k++;
    }
    return (cp);
}




arbre	*remplir(int t[9][9], int si, int sj, int *cp, sudoku **debut)
{
	arbre	*a;
	int		i;
	int		j;

	a = NULL;
	i = si - 3;
	while (i < si)
	{
		j = sj - 3;
		while (j < sj)
		{
			if (t[i][j] == 0)
			{
				*cp = 0;
				*debut = NULL;
				*cp = check_possibilite(t, i, j, debut);
				add_arbre(&a, *debut);
			}
			j++;
		}
		i++;
	}
	return (a);
}

void    is_unique(int t[9][9], int cp,sudoku *debut,arbre *root)
{
    sudoku tmp;

    if (cp != 1)
	{
		tmp = recherche_possibilite(root);
		if (tmp.value != 0)
		{
			t[tmp.i][tmp.j] = tmp.value;
		}
	}
	else if (cp == 1 && debut)
	{
		tmp = *debut;
		t[tmp.i][tmp.j] = tmp.value;
	}
}

void solve_square(int t[9][9], int cp, sudoku *debut, arbre *root)
{
    int ligne;
    int column;
    int si;
    int sj;

    ligne = 0;
    si = 0;
    sj = 0;
    while (ligne < 3)
	{
		column = 0;
		si += 3;
		sj = 0;
		while (column < 3)
		{
			sj += 3;
			root = remplir(t, si, sj, &cp, &debut);
			is_unique(t, cp, debut , root);
			root = NULL;
			column++;
		}
			ligne++;
    }
}

void	posi(int t[9][9])
{
	
	int		cp;
	sudoku	*debut;
	arbre	*root;

	while (reapeat(t) == 1)
	{
		
		debut = NULL;
		root = NULL;
		solve_square(t, cp, debut, root);
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
