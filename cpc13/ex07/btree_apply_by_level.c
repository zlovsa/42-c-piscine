/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 09:23:58 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/25 09:23:59 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

void	rec_tr2list(t_list **list, t_btree *node, int level)
{
	t_list *prev;
	t_list *b;
	t_list *n;

	if (!node)
		return ;
	prev = NULL;
	b = *list;
	while (b && b->level <= level)
	{
		prev = b;
		b = b->next;
	}
	if (!(n = (t_list *)malloc(sizeof(t_list))))
		return ;
	n->node = node;
	n->level = level;
	if (prev)
		prev->next = n;
	else
		*list = n;
	n->next = b;
	rec_tr2list(list, node->left, level + 1);
	rec_tr2list(list, node->right, level + 1);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
							int current_level, int is_first_elem))
{
	t_list	**list;
	t_list	*b;
	t_list	*t;
	int		plev;

	t = NULL;
	list = &t;
	rec_tr2list(list, root, 0);
	b = *list;
	plev = -1;
	while (b)
	{
		(*applyf)(b->node->item, b->level, (plev == b->level) ? 0 : 1);
		plev = b->level;
		t = b->next;
		free(b);
		b = t;
	}
}
