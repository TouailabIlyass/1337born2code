/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 23:07:51 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/01 23:09:20 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned char	c1;
	unsigned char	c2;
	int				i;

	i = 0;
	c1 = (unsigned char)s1[0];
	c2 = (unsigned char)s2[0];
	while (c1 == c2 && i < n)
	{
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;
		if (c1 == '\0')
			break ;
		i++;
	}
	return (c1 - c2);
}
