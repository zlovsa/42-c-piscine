/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 09:14:24 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/17 09:14:26 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char *rv;
	char *retval;
	long i;

	i = 0;
	while (*(src + i) != 0)
		i++;
	rv = (char *)malloc((i + 1) * sizeof(char));
	if (rv == (void *)0)
		return (rv);
	retval = rv;
	while (*src != 0)
	{
		*rv = *src;
		rv++;
		src++;
	}
	*rv = 0;
	return (retval);
}
