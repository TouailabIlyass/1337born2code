/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 23:46:00 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/06 23:46:02 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	unsigned	int		number;
	int					negative;

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
