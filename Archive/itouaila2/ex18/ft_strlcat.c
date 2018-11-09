/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 04:22:20 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/25 17:22:10 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int len;
	unsigned int slen;

	len = 0;
	slen = 0;
	while (src[slen])
		slen++;
	slen = slen - 1;
	while (*dst && size > 0)
	{
		dst++;
		len++;
		size--;
	}
	while (*src && size-- > 1)
		*dst++ = *src++;
	if (size == 1 || *src == 0)
		*dst = '\0';
	return (slen + len);
}
