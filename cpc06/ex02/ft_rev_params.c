/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 09:48:48 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/16 09:48:51 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	char	*c;

	if (argc < 1)
		return (1);
	i = argc - 1;
	while (i > 0)
	{
		c = argv[i];
		while (*c != 0)
		{
			write(1, c, 1);
			c++;
		}
		i--;
		write(1, "\n", 1);
	}
	return (0);
}
