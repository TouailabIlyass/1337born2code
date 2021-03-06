/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 03:48:14 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/23 20:42:51 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int i;
	int p;

	if (power < 0)
		return (0);
	i = 0;
	p = 1;
	while (++i <= power)
		p *= nb;
	return (p);
}
