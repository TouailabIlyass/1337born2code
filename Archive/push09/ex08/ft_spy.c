/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 23:53:22 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/27 01:38:23 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char		*to_lower(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char		*remove_espace(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

int			ft_strcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	str1 = to_lower(str1);
	str1 = remove_espace(str1);
	while (str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] != '\0')
		return (0);
	return (1);
}

int			main(int argc, char *argv[])
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "president"))
			write(1, "Alert!!!\n", 9);
		else if (ft_strcmp(argv[i], "attack"))
			write(1, "Alert!!!\n", 9);
		else if (ft_strcmp(argv[i], "bauer"))
			write(1, "Alert!!!\n", 9);
		i++;
	}
	return (0);
}
