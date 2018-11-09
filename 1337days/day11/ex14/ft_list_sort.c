/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 05:54:25 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/10 01:20:06 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	swap(t_list *p1, t_list *p2)
{
	void *tmp;

	tmp = p1->data;
	p1->data = p2->data;
	p2->data = tmp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *ptr;
	t_list *ptr2;

	ptr = *begin_list;
	while (ptr)
	{
		ptr2 = ptr->next;
		while (ptr2)
		{
			if ((*cmp)(ptr->data, ptr2->data) > 0)
				swap(ptr, ptr2);
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
}
