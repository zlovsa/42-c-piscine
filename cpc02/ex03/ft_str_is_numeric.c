/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 12:01:26 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/11 12:02:47 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_str_is_numeric(char *str);

int	ft_str_is_numeric(char *str)
{
	int retval;

	retval = 1;
	while (*str != 0)
	{
		if (!(('0' <= *str) && (*str <= '9')))
		{
			retval = 0;
			break ;
		}
		str++;
	}
	return (retval);
}
