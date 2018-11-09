/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 04:45:01 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/10 00:37:51 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *ptr;

	ptr = begin_list;
	while (ptr)
	{
		if ((*cmp)(ptr->data, data_ref) == 0)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}
