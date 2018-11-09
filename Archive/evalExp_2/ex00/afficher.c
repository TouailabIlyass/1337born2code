/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 22:13:29 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/05 22:22:44 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"



t_list		*remove_par(t_list *tmp2, t_list **head)
{
	if (tmp2->prev && tmp2->prev->op == '(' && tmp2->next->op == ')')
	{
		tmp2->prev->op = 'x';
		tmp2->next->op = 'x';
		remove_element(head);
	}
	return (tmp2);
}

t_list		*calculer(t_list *tmp2, t_list **head)
{
	t_list		*dr;
	t_list		*dr1;
	int			value;

	value = ft_do_op(tmp2->prev->value, tmp2->next->value, tmp2->op);
	tmp2->prev->value = value;
	tmp2->op = 'x';
	tmp2->next->op = 'x';
	tmp2 = tmp2->prev;
	remove_element(head);
	tmp2 = remove_par(tmp2, head);
	return (tmp2);
}

int			ft_prod(t_list **head, t_list *tmp2, t_list *ptr)
{
	while ((tmp2 && tmp2 != ptr))
	{
		if (tmp2->op == '*' || tmp2->op == '/' || tmp2->op == '%')
		{
			tmp2 = calculer(tmp2, head);
			return (1);
		}
		tmp2 = tmp2->next;
	}
	return (0);
}

int			ft_plus(t_list **head, t_list *tmp2, t_list *ptr)
{
	while ((tmp2 && tmp2 != ptr))
	{
		if (tmp2->op == '+' || tmp2->op == '-')
		{
			tmp2 = calculer(tmp2, head);
			return (1);
		}
		tmp2 = tmp2->next;
	}
	return (0);
}
