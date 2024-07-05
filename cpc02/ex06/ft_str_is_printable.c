/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 15:48:26 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/12 15:48:49 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_str_is_printable(char *str);

int	ft_str_is_printable(char *str)
{
	int retval;

	retval = 1;
	while (*str != 0)
	{
		if (!(32 <= *str && *str <= 126))
		{
			retval = 0;
			break ;
		}
		str++;
	}
	return (retval);
}
