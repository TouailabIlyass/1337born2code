/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 23:30:30 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/10 00:00:36 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int c;

	c = 0;
	while (begin_list)
	{
		c++;
		begin_list = begin_list->next;
	}
	return (c);
}
