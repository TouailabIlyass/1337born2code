/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:12:40 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/05 22:29:33 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void		add_element(t_list **head, int value, char op);
t_list		*remove_par(t_list *tmp2, t_list **head);
int			ft_prod(t_list **head, t_list *tmp2, t_list *ptr);
int			ft_plus(t_list **head, t_list *tmp2, t_list *ptr);
int			ft_atoi(char *str);

void		ch_do_op(t_list *ptr, t_list **head)
{
	t_list		*tmp;
	t_list		*tmp2;

	tmp = ptr;
	while (tmp && tmp->op != '(')
		tmp = tmp->prev;
	tmp2 = tmp;
	if (ft_prod(head, tmp2, ptr))
		return ;
	tmp2 = tmp;
	if (ft_plus(head, tmp2, ptr))
		return ;
	tmp = *head;
	while (tmp)
	{
		tmp = remove_par(tmp, head);
		tmp = tmp->next;
	}
}

int			ft_get_value(t_list **head)
{
	t_list	*ptr;

	ptr = *head;
	while (ptr)
	{
		if (ptr->op == '?')
			return (ptr->value);
		ptr = ptr->next;
	}
	return (0);
}

int			ft_calc(t_list **head)
{
	t_list		*ptr;
	int			d;

	d = 1;
	while (d)
	{
		d = 0;
		ptr = *head;
		while (ptr)
		{
			if (ptr->op == ')')
			{
				ch_do_op(ptr, head);
				d = 1;
			}
			ptr = ptr->next;
		}
	}
	return (ft_get_value(head));
}

int			ft_is_oper(char c)
{
	if (c == '+' || c == '-' || c == '*'
			|| c == '/' || c == '%' || c == '(' || c == ')')
		return (1);
	return (0);
}

void		ft_put_into_list(t_list **head, char *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		if (str[i + 1] >= '0' && str[i + 1] <= '9'
				&& (str[i] == '+' || str[i] == '-'))
		{
			add_element(head, ft_atoi(str + i), '?');
			if (str[i + 1])
				i++;
			while (str[i] && str[i] != ' ' && !ft_is_oper(str[i]))
				i++;
			if (ft_is_oper(str[i]))
				i--;
		}
		else if (ft_is_oper(str[i]))
			add_element(head, 0, *(str + i));
		else if (str[i] != ' ')
		{
			add_element(head, ft_atoi(str + i), '?');
		}
		if (str[i])
			i++;
	}
}
