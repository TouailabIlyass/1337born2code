/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 23:12:54 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/25 15:24:33 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	char	c;
	char	*ptr;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			c = '1';
			ptr = &str[i];
			while (to_find[j] != '\0')
			{
				if (str[i] != to_find[j])
					c = '0';
				j++;
				i++;
			}
			if (c == '1')
				return (ptr);
		}
	}
	return (NULL);
}
