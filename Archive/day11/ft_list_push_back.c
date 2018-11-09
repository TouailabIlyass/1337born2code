/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 23:14:37 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/08 23:24:06 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *elem;
	t_list *ptr;

	elem = ft_create_elem(data);
	if ((*begin_list) == NULL)
	{
		*begin_list = elem;
		return ;
	}
	ptr = *begin_list;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = elem;
}

