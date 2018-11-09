/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 18:19:58 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/31 18:20:04 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	c;

	c = 1;
	i = 1;
	if (nb < 0 || nb > 12)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	while (i <= nb)
	{
		c = c * i;
		i++;
	}
	return (c);
}
