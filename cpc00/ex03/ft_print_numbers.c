/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 13:57:25 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/09 13:57:38 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_numbers(void);

void	ft_print_numbers(void)
{
	char	c;
	int		i;

	c = '0';
	i = 0;
	while (i < 10)
	{
		write(1, &c, 1);
		c++;
		i++;
	}
}