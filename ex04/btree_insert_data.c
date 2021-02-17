/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuel <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 00:10:44 by manuel            #+#    #+#             */
/*   Updated: 2021/02/17 01:13:19 by manuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

#include <stdio.h>

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	int	res;

	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	res = cmpf(item, (*root)->item);
	printf("%d\n", res);
   	
		/*
	if ((*root)->left )
	else
	{
		btree_insert_data(&((*root)->left), item, cmpf);
		btree_insert_data(&((*root)->right), item, cmpf);
	}*/
}

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	btree_apply_suffix(root->left, applyf);
	btree_apply_suffix(root->right, applyf);
	applyf(root->item);
}
