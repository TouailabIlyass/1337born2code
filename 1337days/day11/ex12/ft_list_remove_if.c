/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 04:56:20 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/10 01:17:32 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	int d;

	d = 1;
	while (d)
	{
		ft_remove(begin);
		d = 0;
	}
}

void	ft_remove(t_list **begin)
{
	t_list *list_ptr;
	t_list *ptr;

	list_ptr = *begin_list;
	if (list_ptr == NULL)
		return ;
	if ((*cmp)(list_ptr->data, data_ref) == 0)
	{
		ptr = list_ptr;
		list_ptr = list_ptr->next;
		free(ptr);
	}
	if (ptr->next == NULL)
		return ;
	while (list_ptr->next->next && (*cmp)(list_ptr->next->data, data_ref) != 0)
		list_ptr = list_ptr->next;
	if ((*cmp)(list_ptr->next->data, data_ref) == 0)
	{
		ptr = list_ptr->next;
		list_ptr->next = list_ptr->next->next;
		free(ptr);
	}
}
