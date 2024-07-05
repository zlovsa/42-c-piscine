/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:22:49 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/23 12:22:50 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_rf_dswap(t_list *a, t_list *b)
{
	void *tdata;

	tdata = a->data;
	a->data = b->data;
	b->data = tdata;
}

int		ft_list_rf_check(t_list *begin_list)
{
	t_list *b;

	if (!begin_list || !begin_list->next)
		return (-1);
	b = begin_list->next;
	if (!b->next)
	{
		ft_list_rf_dswap(begin_list, b);
		return (-1);
	}
	return (0);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list *prev;
	t_list *cprev;
	t_list *t;
	t_list *b;

	if (ft_list_rf_check(begin_list) < 0)
		return ;
	b = begin_list->next;
	prev = b;
	b = b->next;
	cprev = prev;
	while (b->next)
	{
		t = b->next;
		b->next = prev;
		prev = b;
		b = t;
	}
	ft_list_rf_dswap(begin_list, b);
	cprev->next = b;
	begin_list->next = prev;
}
