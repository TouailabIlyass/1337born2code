/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 14:20:18 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/25 17:14:42 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size)
{
	unsigned int len;

	len = size;
	while (*src && size-- > 1)
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return (len);
}
