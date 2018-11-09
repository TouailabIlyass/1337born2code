/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:12:27 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/22 15:11:37 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
void	ft_putchar(char c){
write(1,&c,1);
}


void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0' - 1;
	while (++a <= '9')
	{
		b = a;
		while (++b <= '9')
		{
			c = b;
			while (++c <= '9')
			{
				ft_putchar(a);
				ft_putchar(b);
				ft_putchar(c);
				if (a != '7' || b != '8' || c != '9')
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}

int main()
{
	ft_print_comb();
	return 0;
}
