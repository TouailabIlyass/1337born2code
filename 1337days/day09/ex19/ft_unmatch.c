/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 15:10:02 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/27 15:18:39 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_unmatch(int *tab, int length)
{
	int i;
	int j;
	int count_pair;

	i = 0;
	while (i < length)
	{
		j = 0;
		count_pair = 0;
		while (j < length)
		{
			if (tab[i] == tab[j])
				count_pair++;
			j++;
		}
		if (count_paire % 2 != 0)
			return (i);
		i++;
	}
}
