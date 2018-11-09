/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 10:14:32 by itouaila          #+#    #+#             */
/*   Updated: 2018/07/21 16:33:32 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
char g_a = '0' - 1;
char g_b = '0' - 1;
char g_c = '0' - 1;
char g_d = '0' - 1;
int g_tmp = 1;

void	ft_putchar(char c){
	write(1,&c,1);
}

void	disp(void)
{
	ft_putchar(g_a);
	ft_putchar(g_b);
	ft_putchar(' ');
	ft_putchar(g_c);
	ft_putchar(g_d);
	if (g_b != '8' || g_a != '9')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	while (++g_a <= '9')
	{
		g_b = '0' - 1;
		while (++g_b <= '9')
		{
			g_c = g_a - 1;
			while (++g_c <= '9')
			{
				g_d = g_b;
				if (g_b == '9' && g_a != '9' && g_d <'8')
				{
					g_tmp = 0;
					g_d = '9';
				}
				while (++g_d <= '9' || g_tmp == 0)
				{
					disp();
					if (g_b == '9')
					{
						g_tmp = 1;
					}
				}
			}
		}
	}
}

int main(){
 ft_print_comb2();

}
