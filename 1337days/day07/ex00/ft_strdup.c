/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 02:14:02 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/08 02:14:06 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*str;

	len = 0;
	while (*(src + len))
		len++;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	len = 0;
	while (*(src + len))
	{
		*(str + len) = *(src + len);
		len++;
	}
	*(str + len) = '\0';
	return (str);
}
