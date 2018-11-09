/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:32:50 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/10 01:23:17 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *elem;
	t_list *ptr;

	elem = ft_create_elem(data);
	ptr = *begin_list;
	if (ptr == NULL)
	{
		*begin_list = elem;
		return ;
	}
	while (ptr && (*cmp)(data, ptr->data) > 0)
		ptr = ptr->next;
	elem->next = ptr->next;
	ptr->next = elem;
}
