/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 11:24:50 by acazuc            #+#    #+#             */
/*   Updated: 2017/08/29 01:01:25 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void *create_new_block(enum block_type type, size_t len)
{
	struct page_list *new;
	if (!(new = alloc_page(type, type == LARGE ? len : get_page_size(type))))
		return (NULL);
	new->page.blocks[0] = 1;
	push_new_page(new);
	return (new->page.addr);
}
