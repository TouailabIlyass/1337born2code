/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 03:44:15 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/07 18:40:53 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_is_legal(char c)
{
	return ((c >= '0' && c <= '9') ||
			(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int		ft_count_of(char *str, char c, int cs)
{
	int		count;
	char	to_cmp;

	count = 0;
	while (*str)
	{
		to_cmp = *str;
		if (!cs)
		{
			if (to_cmp >= 'A' && to_cmp <= 'Z')
				to_cmp += 32;
		}
		if (to_cmp == c)
			count++;
		str++;
	}
	return (count);
}

void	ft_put_base(unsigned int nb, char *base, int base_len)
{
	if (base_len < 2)
		return ;
	if (nb >= (unsigned int)base_len)
		ft_put_base(nb / base_len, base, base_len);
	ft_putchar(*(base + nb % base_len));
}

void	ft_putnbr_base(int nb, char *base)
{
	int				len;
	unsigned int	n;

	len = 0;
	while (*(base + len))
	{
		if (!ft_is_legal(*(base + len)))
			return ;
		if (ft_count_of(base, *(base + len), 0) > 1)
			return ;
		len++;
	}
	if (len < 2)
		return ;
	if (nb < 0)
	{
		ft_putchar('-');
		n = -nb;
	}
	else
		n = nb;
	ft_put_base(n, base, len);
	ft_putchar('\n');
}
