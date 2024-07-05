/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:05:46 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/15 12:05:48 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int retval;

	if (power < 0)
		return (0);
	retval = 1;
	while (power > 0)
	{
		retval *= nb;
		power--;
	}
	return (retval);
}
