/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 23:46:00 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/10 00:05:33 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	add_first(t_list **begin_list, void *data)
{
	t_list *elem;

	elem = ft_create_elem(data);
	elem->next = *begin_list;
	*begin_list = elem;
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*begin;
	int		i;

	begin = NULL;
	i = 1;
	while (i < ac)
	{
		add_first(&begin, av[i]);
		i++;
	}
	return (begin);
}
