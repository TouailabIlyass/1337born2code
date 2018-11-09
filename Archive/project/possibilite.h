/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibilite.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 18:42:17 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/29 19:28:10 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arbre.h"
#include "solve.h"
#include "sudoku.h"

int check_possibilite(int t[9][9],int i, int j, t_sudoku **debut);

int parcours(t_arbre *root, int value);

t_arbre	*remplir(int t[9][9], int si, int sj, int *cp, t_sudoku **debut);

void    is_unique(int t[9][9], int cp,t_sudoku *debut,t_arbre *root);

void solve_square(int t[9][9], int cp, t_sudoku *debut, t_arbre *root);

t_sudoku	recherche_possibilite(t_arbre *root);
