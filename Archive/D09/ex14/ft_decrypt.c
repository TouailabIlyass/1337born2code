/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrypt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 05:39:13 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/27 06:50:52 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_perso.h"
#include <stdlib.h>

int	find_next(char *str, int index)
{
	int i;

	i = index;
	while (str[i])
	{
		if (str[i] == '|' || str[i] == ';')
			return (i);
		i++;
	}
	return (i);
}

char	*sub_str(char *str ,int start)
{
	int i;
	char *st;
	int end;

	end = find_next(str, start);
	st=(char*)malloc(end-start)*(sizeof(char));
	i = 0;
	while (str[start] && str[start] != '|' && str[start] != ';')
	{
		st[i] = str[start];
		i++;
		start++;
	}
	return (st);
}

t_perso	**ft_decrypt(char *str)
{
	t_perso **tab_perso;
	int i;
	int count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] == ';')
			count++;
		i++;
	}
	tab_perso = (t_perso**)malloc(count * sizeof(t_perso*));
	i = 0;
	while (i < count)
	{
		tab_perso[i] = (t_perso**)malloc(sizeof(t_perso));
		i++;
	}
	i = 0;
	while (i < count)
	{	
		tab_perso[i].age=;
	}

}
