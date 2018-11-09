/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 00:09:04 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/22 22:11:05 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	dessin2(int i, int size, int fl)
{
	int j;

	j = 1;
	while (j < (i * 2) / 2)
	{
		ft_putchar("*");
		j++;
	}
	ft_putchar("|||");
	while (j < (i * 2) - 3)
	{
		ft_putchar("*");
		j++;
	}
	ft_putchar("\\");
	ft_putchar("\n");
}

void	dessin(int i, int size, int fl)
{
	int k;
	int j;

	k = 0;
	while (k < 50 - i)
	{
		ft_putchar(" ");
		k++;
	}
	ft_putchar("/");
	j = 1;
	if (fl != size)
	{
		while (j < i * 2)
		{
			ft_putchar("*");
			j++;
		}
		ft_putchar("\\");
		ft_putchar("\n");
		return ;
	}
}

void	sastantua(int size)
{
	int i;
	int z;
	int cpt;
	int fl;
	int s;

	i = 1;
	z = 0;
	cpt = 1;
	fl = 1;
	s = 1;
	while (++z <= size)
	{
		cpt = 0;
		while (++cpt < z + 3)
		{
			dessin(i, size, fl);
			i++;
		}
		if (++fl % 2 == 0)
			s++;
		i = i + s;
	}
}
