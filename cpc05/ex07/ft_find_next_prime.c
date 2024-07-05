/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:53:30 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/15 13:53:32 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime2(int nb)
{
	long d;

	if (nb < 2)
		return (0);
	d = 2;
	while (d * d <= nb)
	{
		if (nb % d == 0)
			return (0);
		d += 1;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (ft_is_prime2(nb) == 0)
		nb++;
	return (nb);
}
