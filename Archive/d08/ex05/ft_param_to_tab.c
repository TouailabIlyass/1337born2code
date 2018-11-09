/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 21:16:23 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/08 02:02:09 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

char				**ft_split_whitespaces(char *str);

char				*ft_dup(char *str, int *size)
{
	int		i;
	char	*copie;

	i = 0;
	while (str[i])
		i++;
	copie = (char*)malloc(i * sizeof(char));
	i = 0;
	while (str[i])
	{
		copie[i] = str[i];
		i++;
	}
	copie[i] = '\0';
	*size = i;
	return (copie);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	struct s_stock_par	*stock;
	int					i;
	int					x;

	i = 0;
	ac++;
	stock = (struct s_stock_par*)malloc(ac * sizeof(struct s_stock_par));
	stock[ac - 1].str = NULL;
	while (i < ac - 1)
	{
		stock[i].str = av[i];
		stock[i].copy = ft_dup(av[i], &x);
		stock[i].size_param = x;
		stock[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	return (stock);
}
