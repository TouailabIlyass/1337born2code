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
#include "afficher.h"


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

int            ft_atoi(char *str)
{
    int i;
    int nbr;
    int negative;
    
    nbr = 0;
    negative = 0;
    i = 0;
    while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
           (str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
        i++;
    if (str[i] == '-')
        negative = 1;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
    {
        nbr *= 10;
        nbr += (int)str[i] - '0';
        i++;
    }
    if (negative == 1)
        return (-nbr);
    else
        return (nbr);
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
