/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 09:51:39 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/16 09:51:41 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	int retval;

	retval = 0;
	while (retval == 0)
	{
		retval = (unsigned char)*s1 - (unsigned char)*s2;
		if (*s1 == 0 || *s2 == 0)
			break ;
		s1++;
		s2++;
	}
	return (retval);
}

void	ft_sort_str_tab(char *str[], int size)
{
	int		i;
	int		j;
	char	*t;

	if (size > 1)
	{
		i = 1;
		while (i < size)
		{
			j = 0;
			while (j < size - i)
			{
				if (ft_strcmp(str[j], str[j + 1]) > 0)
				{
					t = str[j];
					str[j] = str[j + 1];
					str[j + 1] = t;
				}
				j++;
			}
			i++;
		}
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	char	*c;

	if (argc < 1)
		return (1);
	ft_sort_str_tab(&argv[1], argc - 1);
	i = 1;
	while (i < argc)
	{
		c = argv[i];
		while (*c != 0)
		{
			write(1, c, 1);
			c++;
		}
		i++;
		write(1, "\n", 1);
	}
	return (0);
}
