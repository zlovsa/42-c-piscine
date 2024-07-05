/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 11:22:44 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/17 11:22:46 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *rv;
	int retval;

	rv = (void *)0;
	*range = rv;
	if (min >= max)
		return (0);
	rv = (int *)malloc(sizeof(int) * (max - min));
	*range = rv;
	if (rv == (void *)0)
		return (-1);
	retval = max - min;
	while (min < max)
	{
		*rv = min;
		rv++;
		min++;
	}
	return (retval);
}
