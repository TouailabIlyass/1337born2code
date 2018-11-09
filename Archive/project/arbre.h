/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arbre.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 18:10:15 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/29 19:28:50 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARBRE_H
# define ARBRE_H
# include <stdlib.h>
# include "sudoku.h"
typedef	struct	s_arbre
{
	t_sudoku	*debut;
struct	s_arbre	*next;
}				t_arbre;

t_arbre	*create_arbre(t_sudoku *l);

void	add_arbre(t_arbre **head, t_sudoku *l);

void	supp_arbre(t_arbre *a, int value);

#endif
