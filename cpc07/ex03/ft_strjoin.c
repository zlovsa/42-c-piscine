/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 12:16:02 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/17 12:16:03 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long	ft_strlen(char *s)
{
	long i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_stpcpy(char *dest, char *src)
{
	while (*src != 0)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (dest);
}

char	*ft_alloc_for_join(int size, char **strs, char *sep)
{
	long	totlen;
	int		i;

	totlen = 0;
	i = 0;
	while (i < size)
	{
		totlen += ft_strlen(strs[i]);
		i++;
	}
	if (size > 1)
		totlen += (size - 1) * ft_strlen(sep);
	return ((char *)malloc((totlen + 1) * sizeof(char)));
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*r;
	char	*s;

	r = ft_alloc_for_join(size, strs, sep);
	if (r == (void *)0)
		return (r);
	s = r;
	i = 0;
	while (i < size)
	{
		s = ft_stpcpy(s, strs[i]);
		if (i < size - 1)
			s = ft_stpcpy(s, sep);
		i++;
	}
	*s = 0;
	return (r);
}
