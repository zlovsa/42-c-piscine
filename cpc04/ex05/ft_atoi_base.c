/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:57:58 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/14 12:58:04 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	int retval;

	retval = 0;
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		retval = 1;
	return (retval);
}

int	check_base2(char *base)
{
	int		retval;
	char	*b;
	char	*c;

	retval = 0;
	b = base;
	while (*b != 0)
	{
		if (*b == '+' || *b == '-' || ft_isspace(*b))
			return (-1);
		c = base;
		while (c != b)
		{
			if (*c == *b)
				return (-1);
			c++;
		}
		retval++;
		b++;
	}
	if (retval < 2)
		return (-1);
	return (retval);
}

int	check_char_in_base(char c, char *base)
{
	int retval;

	retval = 0;
	while (c != *(base + retval) && *(base + retval) != 0)
		retval++;
	if (*(base + retval) == 0)
		return (-1);
	else
		return (retval);
}

int	ft_atoi_base(char *str, char *base)
{
	int b;
	int retval;
	int sign;
	int d;

	b = check_base2(base);
	if (b < 0)
		return (0);
	retval = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (str != 0 && (d = check_char_in_base(*str, base)) > -1)
	{
		retval = retval * b + d;
		str++;
	}
	retval *= sign;
	return (retval);
}
