/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibilite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 18:45:46 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/29 19:26:53 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sudoku.h"
#include "possibilite.h"
#include "arbre.h"
#include "solve.h"
int check_possibilite(int t[9][9],int i, int j, t_sudoku **debut)
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

int parcours(t_arbre *root, int value)
{
    t_sudoku  *list;
    int     trouve;
    t_arbre   *tmp;
    
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
		        supp_arbre(root, list->value);
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

t_arbre	*remplir(int t[9][9], int si, int sj, int *cp, t_sudoku **debut)
{
	t_arbre	*a;
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

void    is_unique(int t[9][9], int cp,t_sudoku *debut,t_arbre *root)
{
    t_sudoku tmp;

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

void solve_square(int t[9][9], int cp, t_sudoku *debut, t_arbre *root)
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

t_sudoku	recherche_possibilite(t_arbre *root)
{
	t_sudoku	l1= {0, NULL,'n', -1, -1};
	t_sudoku	*l3;
	t_arbre	*tmp;
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
