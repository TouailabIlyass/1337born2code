/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 06:04:03 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/07 17:00:00 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	min(unsigned int x, unsigned int y)
{
	if (x < y)
		return (x);
	return (y);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	strs_count;
	unsigned int	i;

	i = 0;
	while (*(dest + i))
		i++;
	strs_count = i;
	i = 0;
	while (*(src + i) && strs_count + i < size - 1)
	{
		*(dest + strs_count + i) = *(src + i);
		i++;
	}
	*(dest + strs_count + i) = '\0';
	i = 0;
	while (*(src + i))
		i++;
	return (min(strs_count, size) + i);
}
