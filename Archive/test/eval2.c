/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 04:34:17 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/05 16:54:25 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef	struct	s_list	t_list;
struct	s_list
{
	int		value;
	char	op;
	t_list	*next;
	t_list	*prev;
};

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

void		add_first(t_list **head, int value, char op)
{
	t_list *element;

	element = create_element(value, op);
	if (*head == NULL)
	{
		*head = element;
		return ;
	}
	element->next = *head;
	*head = element;
	element->next->prev = element;
}

void		add_last(t_list **head, int value, char op)
{
	t_list *element;
	t_list *ptr;

	element = create_element(value, op);
	if (*head == NULL)
	{
		*head = element;
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
	if (*head == NULL)
		return ;
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

void		show_list(t_list *head)
{
	while (head)
	{
		if (head->op == '?')
			printf("%d ", head->value);
		else
			printf("%c ", head->op);
		head = head->next;
	}
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
	if (tmp2->prev && tmp2->prev->op == '(' && tmp2->next->op == ')')
	{
		tmp2->prev->op = 'x';
		tmp2->next->op = 'x';
		remove_element(head);
		return (tmp2);
	}
	return (tmp2);
}

void		ch_do_op(t_list *ptr, t_list **head)
{
	t_list		*tmp;
	t_list		*tmp2;

	tmp = ptr;
	while (tmp && tmp->op != '(')
		tmp = tmp->prev;
	tmp2 = tmp;
	while ((tmp2 && tmp2 != ptr))
	{
		if (tmp2->op == '*' || tmp2->op == '/' || tmp2->op == '%')
		{
			tmp2 = calculer(tmp2, head);
			return ;
		}
		tmp2 = tmp2->next;
	}
	tmp2 = tmp;
	while (tmp2 && tmp2 != ptr)
	{
		if (tmp2->op == '+' || tmp2->op == '-')
		{
			tmp2 = calculer(tmp2, head);
			return ;
		}
		tmp2 = tmp2->next;
	}
	tmp = *head;
	while (tmp)
	{
		if (tmp->op != '?')
			tmp->op = 'x';
		tmp = tmp->next;
	}
	remove_element(head);
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
	ptr = *head;
	while (ptr)
	{
		if (ptr->op == '?')
			return (ptr->value);
		ptr = ptr->next;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_list	*head;
	int		x;
	int		i;
	int c;

	head = NULL;
	i = 0;
	add_element(&head, 0, '(');
	while (argv[1][i])
	{	c =0;
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
			add_element(&head, atoi(&argv[1][i]), '?');
			while (argv[1][i] && argv[1][i] >= '0' && argv[1][i] <= '9')
			{
				c = 1;
				i++;
			}
		}
		else if (argv[1][i] != ' ' && argv[1][i + 1] < '0' && argv[1][i + 1] > '9')
			add_element(&head, 0, argv[1][i]);
		else if(argv[1][i + 1] >= '0' && argv[1][i + 1] <= '9')
		   	continue ;
		if (c == 1) i--;
		i++;
	}
	add_element(&head, 0, ')');
	show_list(head);
	printf("%d\n", ft_calc(&head));
	return (0);
}
