/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 00:23:46 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/10 00:27:28 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	remove_first(t_list **begin_list)
{
	t_list *ptr;

	if (*begin_list == NULL)
		return ;
	ptr = *begin_list;
	*begin_list = (*begin_list)->next;
	free(ptr);
}

void	ft_list_clear(t_list **begin_list)
{
	while (*begin_list)
		remove_first(begin_list);
}
