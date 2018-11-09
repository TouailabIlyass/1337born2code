/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 17:14:27 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/09 17:14:28 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_doop.h"
#include "ft_lib.h"

int		ft_doop(int a, int b, char op)
{
	int	(*f[5])(int a, int b);

	f[0] = &ft_add_i;
	f[1] = &ft_sub_i;
	f[2] = &ft_mult_i;
	f[3] = &ft_div_i;
	f[4] = &ft_mod_i;
	if (op == '+')
		return (f[0](a, b));
	if (op == '-')
		return (f[1](a, b));
	if (op == '*')
		return (f[2](a, b));
	if (op == '/')
		return (f[3](a, b));
	if (op == '%')
		return (f[4](a, b));
	return (0);
}

int		ft_is_op(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str != '-' && *str != '+' &&
			*str != '/' && *str == '%' && *str == '*')
			return (0);
		str++;
		i++;
	}
	return (i == 1);
}

int		ft_is_int(char *str)
{
	int count;

	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	count = 0;
	while (*str >= '0' && *str <= '9')
	{
		count++;
		str++;
	}
	return (count != 0);
}

void	ft_print_error(char c, int *can_calc)
{
	if (c == '/')
	{
		ft_putstr("Stop : division by zero");
		*can_calc = 0;
	}
	else if (c == '%')
	{
		ft_putstr("Stop : modulo by zero");
		*can_calc = 0;
	}
}

int		main(int argc, char **argv)
{
	int	vals[3];

	if (argc != 4)
		return (0);
	vals[2] = 1;
	if (ft_is_op(argv[2]) && (ft_is_int(argv[1]) || ft_is_int(argv[3])))
	{
		if (ft_is_int(argv[1]) && !ft_is_int(argv[3]))
			ft_putnbr(ft_atoi(argv[1]));
		else if (!ft_is_int(argv[1]) && ft_is_int(argv[3]))
			ft_putnbr(ft_atoi(argv[3]));
		else
		{
			vals[0] = ft_atoi(argv[1]);
			vals[1] = ft_atoi(argv[3]);
			if (vals[1] == 0)
				ft_print_error(argv[2][0], &vals[2]);
			if (vals[2])
				ft_putnbr(ft_doop(vals[0], vals[1], argv[2][0]));
		}
	}
	else
		ft_putchar('0');
	ft_putchar('\n');
	return (0);
}
