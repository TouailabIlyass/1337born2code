/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 02:15:08 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/08 05:02:43 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_to_int(char nbr, char *base_from)
{
	int index;

	index = 0;
	while (*(base_from + index))
	{
		if (nbr == *(base_from + index))
			return (index);
		index++;
	}
	return (-1);
}

char	*ft_factory(int nbr, int base_len, char *base, int sign)
{
	int		i;
	int		j;
	char	str[1024];
	char	*result;

	if (!nbr)
		return ("0");
	i = 0;
	while (nbr != 0)
	{
		str[i++] = *(base + nbr % base_len);
		nbr /= base_len;
	}
	if (sign == 1)
		str[i++] = '-';
	str[i] = '\0';
	result = (char*)malloc(sizeof(char) * i--);
	j = 0;
	while (i >= 0)
		*(result + j++) = *(str + i--);
	*(result + j) = '\0';
	return (result);
}

int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (*(str + count))
		count++;
	return (count);
}

int		ft_is_valide(char *base)
{
	int	i;
	int j;
	int count;

	i = -1;
	while (*(base + ++i))
	{
		j = -1;
		count = 0;
		if (!((base[i] >= '0' && base[i] <= '9') ||
			(base[i] >= 'a' && base[i] <= 'z') ||
			(base[i] >= 'A' && base[i] <= 'Z')))
			return (0);
		while (*(base + ++j))
			if (*(base + j) == *(base + i))
				count++;
		if (count > 1)
			return (0);
	}
	if (i <= 1)
		return (0);
	return (1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int lens[3];
	int index;
	int power;
	int nbr_int;

	if (!ft_is_valide(base_from) || !ft_is_valide(base_to))
		return (NULL);
	lens[0] = ft_strlen(base_from);
	power = 1;
	nbr_int = 0;
	lens[2] = *nbr == '-';
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	lens[1] = ft_strlen(nbr);
	while (lens[1] > 0)
	{
		index = ft_to_int(*(nbr + lens[1] - 1), base_from);
		if (index == -1)
			return (NULL);
		nbr_int += index * power;
		power *= lens[0];
		lens[1]--;
	}
	return (ft_factory(nbr_int, ft_strlen(base_to), base_to, lens[2]));
}
