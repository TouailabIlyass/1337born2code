/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 17:15:03 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/10 00:50:44 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **a, char **b)
{
	char *x;

	x = *a;
	*a = *b;
	*b = x;
}

int		ft_strcmp(char *s1, char *s2)
{
	char c1;
	char c2;

	c1 = s1[0];
	c2 = s2[0];
	while (c1 == c2)
	{
		c1 = *s1++;
		c2 = *s2++;
		if (c1 == '\0')
			break ;
	}
	return (c1 - c2);
}

void	ft_sort_wordtab(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				swap(&tab[i], &tab[j]);
			}
			j++;
		}
		i++;
	}
}
