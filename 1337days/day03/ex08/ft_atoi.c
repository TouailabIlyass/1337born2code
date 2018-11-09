/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:55:21 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/25 16:32:23 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int result;
	int i;
	int j;

	result = 0;
	i = 0;
	j = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		j = i++;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[j] == '-')
		result = result * -1;
	return (result);
}
