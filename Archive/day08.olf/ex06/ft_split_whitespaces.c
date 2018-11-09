/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 20:54:52 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/07 20:54:53 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char	*ft_copy(char **src)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (src[0][len] && !ft_is_space(src[0][len]))
		len++;
	str = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		*(str + i) = src[0][0];
		(*src)++;
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

int		ft_words_count(char *str)
{
	int can_count;
	int count;

	count = 0;
	can_count = 1;
	while (*str)
	{
		if (!ft_is_space(*str) && can_count)
		{
			can_count = 0;
			count++;
		}
		if (ft_is_space(*str))
			can_count = 1;
		str++;
	}
	return (count);
}

char	**ft_array_alloc(char *str)
{
	char	**array;
	int		size;

	size = ft_words_count(str);
	array = (char**)malloc(sizeof(char*) * (size + 1));
	*(array + size) = NULL;
	return (array);
}

char	**ft_split_whitespaces(char *str)
{
	char	**array;
	int		i;
	int		str_count;

	array = ft_array_alloc(str);
	i = 0;
	while (*str)
	{
		if (!ft_is_space(*str))
		{
			*(array + i) = ft_copy(&str);
			i++;
		}
		if (!*str)
			break ;
		str++;
	}
	return (array);
}
