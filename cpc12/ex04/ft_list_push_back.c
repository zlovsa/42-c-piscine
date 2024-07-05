/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:19:30 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/23 12:19:32 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *r;
	t_list *b;

	if (begin_list == NULL)
		return ;
	if ((r = ft_create_elem(data)) == NULL)
		return ;
	b = *begin_list;
	if (b == NULL)
		*begin_list = r;
	else
	{
		while (b->next != NULL)
			b = b->next;
		b->next = r;
	}
}
