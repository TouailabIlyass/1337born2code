/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 17:15:31 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/09 17:15:58 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **s1, char **s2)
{
	char *c;

	c = *s1;
	*s1 = *s2;
	*s2 = c;
}

void	ft_advanced_sort_wordtab(char **tab, int (*cmp) (char *, char *))
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if ((*cmp)(tab[i], tab[j]) > 0)
				swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}
