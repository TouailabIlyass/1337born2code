/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 01:29:56 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/07 01:29:58 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_count;

	src_count = 0;
	while (*src && src_count < size - 1)
	{
		*dest++ = *src++;
		src_count++;
	}
	*dest = '\0';
	while (*src)
	{
		src++;
		src_count++;
	}
	return (src_count);
}
