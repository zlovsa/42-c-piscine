/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:52:25 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/13 15:52:29 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*s;
	unsigned int	n;

	n = 0;
	while (*dest != 0)
	{
		dest++;
		n++;
	}
	s = src;
	while (n + s - src + 1 < size && *s != 0)
	{
		*dest = *s;
		dest++;
		s++;
	}
	if (size > 0 && n <= size)
		*dest = 0;
	while (*s != 0)
		s++;
	if (n > size)
		n = size;
	n += s - src;
	return (n);
}
