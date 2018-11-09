/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 21:16:23 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/08 01:17:14 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_stock_par.h"

char    			**ft_split_whitespaces(char *str);
char				*ft_dup(char *str, int *size)
{
	int i;
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
	struct s_stock_par *stock;
	int i;
	int x;

	i = 0;
	ac++;
	stock = (struct s_stock_par*) malloc(ac * sizeof(struct s_stock_par));
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
/*
int main(int ac, char **av)
{
	struct s_stock_par *s;

	s = ft_param_to_tab(ac, av);
	int i = 0;
	int j;
	while (s[i].str)
	{
		printf("##########################\n");
		printf("size_param : %d\n", s[i].size_param);
		printf("str : %s\n",s[i].str);
		printf("copy : %s\n",s[i].copy);
		printf("split : \n");
		j = 0;
		while (s[i].tab[j])
		{
			printf("%s\n", s[i].tab[j]);
			j++;
		}
		printf("##########################\n");
		i++;
	}
	return (0);
}
*/
