/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 04:34:17 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/05 22:18:37 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "list.h"

int			ft_do_op(int nb1, int nb2, char op);
t_list		*create_element(int value, char op);
void		add_element(t_list **head, int value, char op);
void		remove_head(t_list **head);
void		remove_element(t_list **head);
t_list		*remove_par(t_list *tmp2, t_list **head);
t_list		*calculer(t_list *tmp2, t_list **head);
int			ft_prod(t_list **head, t_list *tmp2, t_list *ptr);
int			ft_plus(t_list **head, t_list *tmp2, t_list *ptr);
void		ch_do_op(t_list *ptr, t_list **head);
int			ft_get_value(t_list **head);
int			ft_calc(t_list **head);
int			ft_is_oper(char c);
void		ft_put_into_list(t_list **head, char *str);

int			ft_atoi(char *str)
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

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb < 10 && nb >= 0)
		ft_putchar(nb + '0');
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int			eval_expr(char *str)
{
	t_list	*head;
	int		x;
	int		i;

	head = NULL;
	i = 0;
	add_element(&head, 0, '(');
	ft_put_into_list(&head, str);
	add_element(&head, 0, ')');
	return (ft_calc(&head));
}

int			main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
