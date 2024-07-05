/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 11:43:10 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/15 11:43:14 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int retval;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	retval = 1;
	while (nb > 1)
	{
		retval *= nb;
		nb--;
	}
	return (retval);
}
