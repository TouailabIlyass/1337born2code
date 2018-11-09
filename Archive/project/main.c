/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 18:28:33 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/29 19:10:49 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "possibilite.h"
#include "sudoku.h"

void	posi(int t[9][9])
{
	
	int		cp;
	t_sudoku	*debut;
	t_arbre	*root;

	while (reapeat(t) == 1)
	{
		
		debut = NULL;
		root = NULL;
		solve_square(t, cp, debut, root);
	}
}

int main(int argc, char **argv)
{
	int t_sudoku[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
					{5, 2, 0, 0, 0, 0, 0, 0, 0},
					{0, 8, 7, 0, 0, 0, 0, 3, 1},
					{0, 0, 3, 0, 1, 0, 0, 8, 0},
					{9, 0, 0, 8, 6, 3, 0, 0, 5},
					{0, 5, 0, 0, 9, 0, 6, 0, 0},
					{1, 3, 0, 0, 0, 0, 2, 5, 0},
					{0, 0, 0, 0, 0, 0, 0, 7, 4},
					{0, 0, 5, 2, 0, 6, 3, 0, 0}};

	posi(t_sudoku);
	affichage(t_sudoku);
	return (0);
}
