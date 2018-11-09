/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptrfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 21:20:51 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/08 06:40:21 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_X(int x, int y)
{
	return x+y;
}

int main(void)
{
	void (*ft)(char ) = NULL;
	ft = &ft_putchar;
	ft('x');	
	int (*Z)(int, int) = &ft_X;
	int x=Z(2,4);
	printf("%djj\nj",x);
	return (0);
}
