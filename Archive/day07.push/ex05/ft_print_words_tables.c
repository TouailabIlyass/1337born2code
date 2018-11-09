/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 02:14:59 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/08 02:15:00 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_words_tables(char **tab)
{
	char *str;

	while (*tab != NULL)
	{
		str = *tab;
		while (*str)
		{
			ft_putchar(*str);
			str++;
		}
		ft_putchar('\n');
		tab++;
	}
}
