/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 23:53:24 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/07 06:01:29 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned char c1;
	unsigned char c2;

	c1 = (unsigned char)s1[0];
	c2 = (unsigned char)s2[0];
	while (c1 == c2 && n)
	{
		c1 = *s1++;
		c2 = *s2++;
		if (c1 == '\0')
			break ;
		n--;
	}
	return (c1 - c2);
}
