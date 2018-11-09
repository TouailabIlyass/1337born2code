/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:01:52 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/25 16:07:52 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_lower_case(char c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

int		is_symbole(char c)
{
	if (c == 43 || c == 95 || c == 45 || c == 32)
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_lower_case(str[i]))
			if (i == 0 || is_symbole(str[i - 1]))
				str[i] = str[i] - 32;
		i++;
	}
}
