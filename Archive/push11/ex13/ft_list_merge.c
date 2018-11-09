/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 05:48:00 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/10 01:19:12 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *ptr;

	ptr = *begin_list1;
	if (ptr == NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = begin_list2;
}
