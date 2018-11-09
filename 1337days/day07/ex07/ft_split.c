/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 02:15:19 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/08 02:20:03 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_spliter(char c, char *charset)
{
	int i;

	i = 0;
	while (*(charset + i))
	{
		if (*(charset + i) == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_copy(char **src, char *charset)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (src[0][len] && !ft_is_spliter(src[0][len], charset))
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

int		ft_words_count(char *str, char *charset)
{
	int can_count;
	int count;

	count = 0;
	can_count = 1;
	while (*str)
	{
		if (!ft_is_spliter(*str, charset) && can_count)
		{
			can_count = 0;
			count++;
		}
		if (ft_is_spliter(*str, charset))
			can_count = 1;
		str++;
	}
	return (count);
}

char	**ft_array_alloc(char *str, char *charset)
{
	char	**array;
	int		size;

	size = ft_words_count(str, charset);
	array = (char**)malloc(sizeof(char*) * (size + 1));
	*(array + size) = NULL;
	return (array);
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		i;

	array = ft_array_alloc(str, charset);
	i = 0;
	while (*str)
	{
		if (!ft_is_spliter(*str, charset))
		{
			*(array + i) = ft_copy(&str, charset);
			i++;
		}
		if (!*str)
			break ;
		str++;
	}
	return (array);
}
