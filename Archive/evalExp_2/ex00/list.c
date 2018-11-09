/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:07:40 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/05 21:37:35 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

int			ft_do_op(int nb1, int nb2, char op)
{
	if (op == '+')
		return (nb1 + nb2);
	if (op == '-')
		return (nb1 - nb2);
	if (op == '*')
		return (nb1 * nb2);
	if (op == '/')
		return (nb1 / nb2);
	if (op == '%')
		return (nb1 % nb2);
	return (0);
}

t_list		*create_element(int value, char op)
{
	t_list *element;

	element = (t_list*)malloc(sizeof(t_list));
	element->value = value;
	element->op = op;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

void		add_element(t_list **head, int value, char op)
{
	t_list *element;
	t_list *ptr;

	element = create_element(value, op);
	if (*head == NULL)
	{
		*head = element;
		element->prev = NULL;
		return ;
	}
	ptr = *head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = element;
	element->prev = ptr;
}

void		remove_head(t_list **head)
{
	t_list *ptr;

	ptr = *head;
	if (ptr->next == NULL)
	{
		free(ptr);
		*head = NULL;
		return ;
	}
	*head = ptr->next;
	ptr->next->prev = NULL;
	free(ptr);
}

void		remove_element(t_list **head)
{
	t_list *ptr;
	t_list *ptr2;

	ptr2 = *head;
	if ((*head)->op == 'x')
	{
		remove_head(head);
		return ;
	}
	while (ptr2)
	{
		ptr = *head;
		while (ptr->next && ptr->op != 'x')
			ptr = ptr->next;
		if (ptr->op == 'x')
		{
			if (ptr->prev != NULL)
				ptr->prev->next = ptr->next;
			if (ptr->next != NULL)
				ptr->next->prev = ptr->prev;
			free(ptr);
		}
		ptr2 = ptr2->next;
	}
}
