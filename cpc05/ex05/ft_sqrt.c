/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 12:37:26 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/15 12:37:28 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long rv;

	if (nb <= 0)
		return (0);
	rv = 1;
	while (rv * rv < nb)
		rv++;
	if (rv * rv == nb)
		return ((int)rv);
	else
		return (0);
}