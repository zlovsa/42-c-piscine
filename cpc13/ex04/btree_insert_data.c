/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 09:23:02 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/25 09:23:03 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

void	rec_ins(t_btree *node, void *item, int (*cmpf)(void *, void *))
{
	if ((*cmpf)(item, node->item) < 0)
	{
		if (node->left)
			rec_ins(node->left, item, cmpf);
		else
			node->left = btree_create_node(item);
	}
	else
	{
		if (node->right)
			rec_ins(node->right, item, cmpf);
		else
			node->right = btree_create_node(item);
	}
}

void	btree_insert_data(t_btree **root, void *item,
			int (*cmpf)(void *, void *))
{
	if (!root)
		return ;
	if (!*root)
		*root = btree_create_node(item);
	else
		rec_ins(*root, item, cmpf);
}
