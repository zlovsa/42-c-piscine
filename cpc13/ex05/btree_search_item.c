/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 09:40:39 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/25 09:40:41 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
			int (*cmpf)(void *, void *))
{
	t_btree *f;

	if (!root)
		return (NULL);
	if (f = btree_search_item(root->left, data_ref, cmpf))
		return (f);
	if ((*cmpf)(root->item, data_ref) == 0)
		return (root);
	return (btree_search_item(root->right, data_ref, cmpf));
}
