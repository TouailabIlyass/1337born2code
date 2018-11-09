/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 18:20:28 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/29 19:09:43 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H
# include <stdlib.h>

typedef struct	s_sudoku
{
	int			value;
	struct s_sudoku		*next;
	char		is_const;
	int			i;
	int			j;
}				t_sudoku;

t_sudoku	*create_posibilite(int value, int i, int j);

void		add_posibilite(t_sudoku **head, int value, int i, int j);

void		supp_posibilite(t_sudoku **head, int value);

void		vider_list(t_sudoku **l);

int			count_list(t_sudoku *l);

#endif
