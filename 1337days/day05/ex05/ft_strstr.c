/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 23:50:37 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/06 23:50:39 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *sub)
{
	int		i;
	char	*begin;

	begin = sub;
	if (*str == '\0' || *sub == '\0')
		return ("");
	while (*str != '\0')
	{
		i = 0;
		sub = begin;
		while ((*sub == *(str + i)) && (*sub != '\0' && *(str + i) != '\0'))
		{
			sub++;
			i++;
		}
		if (*sub == '\0')
			return (str);
		str++;
	}
	return (0);
}
