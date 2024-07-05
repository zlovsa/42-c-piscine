/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 16:52:33 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/12 16:52:36 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_char_is_alphanumeric(char c)
{
	int retval;

	retval = 0;
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')
		|| ('0' <= c && c <= '9'))
		retval = 1;
	return (retval);
}

char	*ft_strcapitalize(char *str)
{
	char	*retval;
	int		wordbegin;

	retval = str;
	wordbegin = 1;
	while (*str != 0)
	{
		if (wordbegin == 1 && ft_char_is_alphanumeric(*str) == 1)
		{
			if ('a' <= *str && *str <= 'z')
				*str = 'A' - 'a' + *str;
			wordbegin = 0;
		}
		else if (wordbegin == 0 && 'A' <= *str && *str <= 'Z')
			*str = 'a' - 'A' + *str;
		else if (wordbegin == 0 && ft_char_is_alphanumeric(*str) == 0)
			wordbegin = 1;
		str++;
	}
	return (retval);
}
