/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:23:55 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/19 16:24:04 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_char_in_str(char c, char *str)
{
	while (*str != 0)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_dup_from_b_to_s(char *b, char *s)
{
	char *rv;
	char *w;

	w = (char *)malloc((s - b) * sizeof(char));
	rv = w;
	while (b != s)
	{
		*w = *b;
		w++;
		b++;
	}
	*w = 0;
	return (rv);
}

char	**ft_alloc_for_split(char *s, char *charset)
{
	int wcnt;
	int pstate;
	int state;

	wcnt = 0;
	pstate = 1;
	while (*s != 0)
	{
		state = ft_char_in_str(*s, charset);
		if (pstate == 1 && state == 0)
			wcnt++;
		pstate = state;
		s++;
	}
	return ((char **)malloc((wcnt + 1) * sizeof(char *)));
}

char	**ft_split(char *str, char *charset)
{
	int		wcnt;
	int		pstate;
	int		state;
	char	*b;
	char	**r;

	if ((r = ft_alloc_for_split(str, charset)) == NULL)
		return (NULL);
	wcnt = 0;
	pstate = 1;
	while (*str != 0)
	{
		state = ft_char_in_str(*str, charset);
		if (pstate == 1 && state == 0)
			b = str;
		else if (pstate == 0 && state == 1)
			if ((r[wcnt++] = ft_dup_from_b_to_s(b, str)) == NULL)
				return (NULL);
		pstate = state;
		str++;
	}
	if (pstate == 0 && (r[wcnt++] = ft_dup_from_b_to_s(b, str)) == NULL)
		return (NULL);
	r[wcnt] = (void *)0;
	return (r);
}
