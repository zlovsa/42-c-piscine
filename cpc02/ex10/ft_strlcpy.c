/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 16:58:35 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/12 16:58:38 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char			*s;
	unsigned int	n;

	s = src;
	n = size;
	if (n != 0)
	{
		n--;
		while (n != 0 && *s != 0)
		{
			*dest = *s;
			dest++;
			s++;
			n--;
		}
		*dest = 0;
	}
	while (*s != 0)
		s++;
	return (s - src);
}
