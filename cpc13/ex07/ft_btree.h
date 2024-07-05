/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarolee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 08:39:01 by mcarolee          #+#    #+#             */
/*   Updated: 2020/09/25 08:39:02 by mcarolee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H
# include <stdlib.h>

typedef struct	s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}				t_btree;

typedef struct	s_list
{
	struct s_list	*next;
	t_btree			*node;
	int				level;
}				t_list;

t_btree			*btree_create_node(void *item);
void			btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
					int current_level, int is_first_elem));

#endif
