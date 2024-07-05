/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:27:52 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/13 15:27:55 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int found;
	int i;

	if (*to_find == 0)
		return (str);
	found = 0;
	while (*str != 0)
	{
		i = 0;
		while (*(str + i) == *(to_find + i)
			&& *(str + i) != 0 && *(to_find + i) != 0)
			i++;
		if (*(to_find + i) == 0)
		{
			found = 1;
			break ;
		}
		str++;
	}
	if (found == 0)
		return ((void *)0);
	else
		return (str);
}
