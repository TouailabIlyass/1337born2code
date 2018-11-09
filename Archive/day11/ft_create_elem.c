/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 22:13:28 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/09 20:31:20 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *ptr;

	ptr = (t_list*)malloc(sizeof(t_list));
	ptr->next = NULL;
	ptr->data = data;
	return (ptr);
}
