/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:37:03 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/12 15:40:39 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_str_is_uppercase(char *str);

int	ft_str_is_uppercase(char *str)
{
	int retval;

	retval = 1;
	while (*str != 0)
	{
		if (!('A' <= *str && *str <= 'Z'))
		{
			retval = 0;
			break ;
		}
		str++;
	}
	return (retval);
}
