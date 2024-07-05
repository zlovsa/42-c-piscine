/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 10:45:43 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/11 10:50:16 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strncpy(char *dest, char *src, unsigned int n);

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char *retval;

	retval = dest;
	while (n > 0)
	{
		*dest = *src;
		dest++;
		if (*src != 0)
			src++;
		n--;
	}
	return (retval);
}
