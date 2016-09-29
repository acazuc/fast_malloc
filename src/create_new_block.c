/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 11:24:50 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/29 16:27:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*create_new_block(t_block_type type, size_t len)
{
	t_page_list		*new;

	if (!(new = alloc_page(type, type == LARGE ? len : get_page_size(type))))
		return (NULL);
	new->page.blocks[0] = 1;
	push_new_page(new);
	return (new->page.addr);
}
