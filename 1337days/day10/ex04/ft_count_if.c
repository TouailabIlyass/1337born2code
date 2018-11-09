/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 17:08:33 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/09 17:09:31 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f) (char*))
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (*(tab + i))
	{
		if ((*f)(*(tab + i)) == 1)
			count++;
		i++;
	}
	return (count);
}