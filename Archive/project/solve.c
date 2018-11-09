/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 18:35:21 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/29 19:11:52 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

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
