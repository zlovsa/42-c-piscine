/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:24:38 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/11 11:27:21 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_str_is_alpha(char *str);

int	ft_str_is_alpha(char *str)
{
	int retval;

	retval = 1;
	while (*str != 0)
	{
		if (!((('a' <= *str) && (*str <= 'z'))
					|| (('A' <= *str) && (*str <= 'Z'))))
		{
			retval = 0;
			break ;
		}
		str++;
	}
	return (retval);
}
