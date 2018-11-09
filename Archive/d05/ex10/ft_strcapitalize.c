/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 23:57:07 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/06 23:57:09 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	int		can_modify;
	char	*start;

	start = str;
	can_modify = 1;
	while (*str != '\0')
	{
		*str = ft_tolower(*str);
		if ((*str < ' ' || *str > '/') && can_modify)
		{
			*str = ft_toupper(*str);
			can_modify = 0;
		}
		else if (*str >= ' ' && *str <= '/')
			can_modify = 1;
		str++;
	}
	return (start);
}
