/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 20:27:59 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/26 21:45:13 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_rot42(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = (((str[i] - 'A') + 42) % 26) + 'A';
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = (((str[i] - 'a') + 42) % 26) + 'a';
		i++;
	}
	return (str);
}