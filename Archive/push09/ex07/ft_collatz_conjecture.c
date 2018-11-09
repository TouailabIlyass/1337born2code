/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 22:38:36 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/26 23:05:32 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
unsigned int	ft_collatz_conjecture(unsigned int base)
{ 
	if (base == 1)
		return (0);
	if (base % 2 == 0)
		return ft_collatz_conjecture(base / 2)+1;
	else
		return ft_collatz_conjecture(3 * base + 1)+1;
}

int main()
{
	printf("%u\n",ft_collatz_conjecture(10));
	return 0;
}
