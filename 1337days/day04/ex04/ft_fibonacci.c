/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 18:21:34 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/31 18:21:36 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
	{
		return (-1);
	}
	if (index == 1)
	{
		return (1);
	}
	if (index == 0)
		return (0);
	else
		return ((ft_fibonacci(index - 2)) + (ft_fibonacci(index - 1)));
}
