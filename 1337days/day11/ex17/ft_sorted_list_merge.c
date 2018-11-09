/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:44:53 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/10 01:24:32 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin, t_list *list2)
{
	t_list *ptr;

	ptr = *begin;
	if (ptr == NULL)
	{
		*begin = list2;
		return ;
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = list2;
}

void	ft_list_sort(t_list **begin, int (*cmp) ())
{
	t_list	*ptr1;
	t_list	*ptr2;
	void	*next;

	if (*begin == NULL)
		return ;
	ptr = *begin;
	while (ptr)
	{
		ptr2 = ptr;
		while (ptr2->next)
		{
			if ((*cmp)(ptr1->data, ptr2->next->data) > 0)
			{
				next = ptr2->data;
				ptr2->data = ptr2->next->data;
				ptr2->next->data = data;
			}
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
			int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}
