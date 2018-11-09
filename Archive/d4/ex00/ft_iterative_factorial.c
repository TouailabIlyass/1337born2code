/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:21:14 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/25 22:51:03 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int i;
	int f;
	
	if (nb < 0)
		return (0);
	i = 0;
	f = 1;
	while (++i <= nb)
	{
		f = f * i;
	}
	return (f);
}