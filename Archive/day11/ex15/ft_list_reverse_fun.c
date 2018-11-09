/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 06:38:14 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/10 01:21:17 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_count_list(t_list *begin)
{
	int c;

	c = 0;
	while (begin)
	{
		c++;
		begin = begin->next;
	}
	return (c);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*ptr;
	int		count;
	int		i;
	int		j;
	void	*tmp_data;

	count = ft_count_list(begin_list);
	i = 1;
	while (i < count)
	{
		j = i;
		ptr = begin_list;
		while (ptr->next && j < count)
		{
			tmp_data = ptr->next->data;
			ptr->next->data = ptr->data;
			ptr->data = tmp_data;
			ptr = ptr->next;
			j++;
		}
		i++;
	}
}
