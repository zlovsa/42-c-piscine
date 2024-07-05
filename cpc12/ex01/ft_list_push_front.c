/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:18:46 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/23 12:18:47 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *r;

	if (begin_list == NULL)
		return ;
	if ((r = ft_create_elem(data)) == NULL)
		return ;
	r->next = *begin_list;
	*begin_list = r;
}
