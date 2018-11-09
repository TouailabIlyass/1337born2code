/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 17:12:13 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/09 17:12:15 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_lib.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int		ft_atoi(char *str)
{
	unsigned int	number;
	int				negative;

	number = 0;
	negative = 1;
	while (*str == '\n' || *str == '\t' || *str == ' ')
		str++;
	if (*str == '-')
	{
		negative = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		number = number * 10 + *str - '0';
		str++;
	}
	return (number * negative);
}

void	ft_putnbr(int nb)
{
	unsigned int n;

	if (nb < 0)
	{
		ft_putchar('-');
		n = nb * -1;
	}
	else
		n = nb;
	if (n <= 9)
		ft_putchar(n + '0');
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
