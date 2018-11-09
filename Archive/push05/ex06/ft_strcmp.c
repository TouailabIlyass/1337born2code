/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 23:12:54 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/01 23:07:05 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char c1;
	unsigned char c2;

	c1 = (unsigned char)s1[0];
	c2 = (unsigned char)s2[0];
	while (c1 == c2)
	{
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		if (c1 == '\0')
			break ;
	}
	return (c1 - c2);
}
