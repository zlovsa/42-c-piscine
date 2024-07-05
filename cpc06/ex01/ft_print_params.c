/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 09:43:46 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/16 09:43:53 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	char	*c;

	if (argc < 1)
		return (1);
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
