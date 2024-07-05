/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:57:19 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/12 15:57:24 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strupcase(char *str);

char	*ft_strupcase(char *str)
{
	char *retval;

	retval = str;
	while (*str != 0)
	{
		if ('a' <= *str && *str <= 'z')
			*str = 'A' - 'a' + *str;
		str++;
	}
	return (retval);
}
