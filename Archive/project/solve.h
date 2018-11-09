/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 18:32:04 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/29 19:11:25 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	is_in_square(int t[9][9], int row, int col, int value);

int	is_in_row(int t[9][9], int row, int col, int value);

int	is_in_col(int t[9][9], int row, int col, int value);

void	affichage(int t[9][9]);

int	reapeat(int t[9][9]);
