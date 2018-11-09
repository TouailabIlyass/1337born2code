/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itouaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 20:52:40 by itouaila          #+#    #+#             */
/*   Updated: 2018/08/02 02:28:59 by itouaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	swap(char **a, char **b)
{
	char *x;

	x = *a;
	*a = *b;
	*b = x;
}

int		ft_strcmp(char *s1, char *s2)
{
	char c1;
	char c2;

	c1 = s1[0];
	c2 = s2[0];
	while (c1 == c2)
	{
		c1 = *s1++;
		c2 = *s2++;
		if (c1 == '\0')
			break ;
	}
	return (c1 - c2);
}

void	tri(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				swap(&argv[i], &argv[j]);
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int	i;
	int j;

	tri(argc, argv);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			ft_putchar(argv[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}
