/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 08:38:47 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/25 08:38:48 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *r;

	r = (t_btree *)malloc(sizeof(t_btree));
	if (!r)
		return (NULL);
	r->item = item;
	r->left = NULL;
	r->right = NULL;
	return (r);
}
