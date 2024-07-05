/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:20:30 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/23 12:20:31 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *prev;
	t_list *t;
	t_list *b;

	if (begin_list == NULL)
		return ;
	b = *begin_list;
	prev = b;
	b = b->next;
	prev->next = NULL;
	while (b != NULL)
	{
		t = b->next;
		b->next = prev;
		prev = b;
		b = t;
	}
	*begin_list = prev;
}
