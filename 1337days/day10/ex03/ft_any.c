/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 17:06:55 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/09 17:07:07 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (*(tab + i))
	{
		if ((*f)(*(tab + i)) == 1)
			return (1);
		i++;
	}
	return (0);
}
