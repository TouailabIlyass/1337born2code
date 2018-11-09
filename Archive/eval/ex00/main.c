/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 02:00:54 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/04 06:30:46 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

typedef	struct	s_list t_list;
struct s_list
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

void	add_element(t_list **head, int value, char op)
{
	t_list *element;
	t_list *ptr;

	element = create_element(value, op);
	if (*head == NULL)
	{
		*head = element;
		element->prev = *head;
		return ;
	}
	ptr = *head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = element;
	element->prev = ptr;
}

void	remove_element(t_list **head, int p)
{
	int i;
	t_list *ptr;

	i = 0;
	ptr = *head;
	while (ptr && i < p)
	{
		i++;
		ptr = ptr->next;
	}
}
int		calcp(t_list *head)
{
	int c;

	c = 0;
	while (head)
	{
		if (head->op == ')')
		{

		}
		head = head->next;
	}

}
void	show_list(t_list *head)
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

void	ft_calc(t_list *head)
{
	
}

int		main(int argc, char **argv)
{
	t_list *head;
	int x;
	int i;
	head = NULL;
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
		//	x = argv[1][i] - '0';
			add_element(&head,atoi(&argv[1][i]), '?');
		}
		else if (argv[1][i] != ' ')
			add_element(&head, 0, argv[1][i]);
		i++;
	}
	show_list(head);
	return (0);
}
