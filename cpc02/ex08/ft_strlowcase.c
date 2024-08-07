/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 16:45:47 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/12 16:45:51 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char *retval;

	retval = str;
	while (*str != 0)
	{
		if ('A' <= *str && *str <= 'Z')
			*str = 'a' - 'A' + *str;
		str++;
	}
	return (retval);
}
