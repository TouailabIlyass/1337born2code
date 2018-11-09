/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 01:09:23 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/10 00:30:32 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*go_to_last(t_list *begin)
{
	while (begin->next)
		begin = begin->next;
	return (begin);
}

void		ft_list_reverse(t_list **begin_list)
{
	t_list *ptr;
	t_list *ptr2;
	t_list *qu;

	qu = go_to_last(*begin_list);
	ptr = qu;
	while (qu != *begin_list)
	{
		ptr2 = *begin_list;
		while (ptr2->next != qu)
			ptr2 = ptr2->next;
		qu->next = ptr2;
		qu = qu->next;
	}
	qu->next = NULL;
	*begin_list = ptr;
}
