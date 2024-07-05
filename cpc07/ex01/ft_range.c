/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 10:45:40 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/17 10:45:42 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *rv;
	int *retval;

	if (min >= max)
		return ((void *)0);
	rv = (int *)malloc(sizeof(int) * (max - min));
	if (rv == (void *)0)
		return (rv);
	retval = rv;
	while (min < max)
	{
		*rv = min;
		rv++;
		min++;
	}
	return (retval);
}
