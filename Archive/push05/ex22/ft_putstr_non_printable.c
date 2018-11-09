/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 14:30:07 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/24 17:12:17 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	c[1];
	i = 0;
	while (str[i])
	{
		if(str[i] >= 0 && str[i] <= 31)
		{
			ft_putchar('\\');
			ft_putchar('0');
			sprintf(c,"%x",str[i]);
			ft_putchar(c[0]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
