/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_existing_block.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:51:03 by acazuc            #+#    #+#             */
/*   Updated: 2017/08/29 01:35:30 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

struct page_list *g_pages[3];

void *get_existing_block(enum block_type type)
{
	struct page_list *lst = g_pages[type];
	while (lst)
	{
		for (size_t i = 0; i < PAGE_SIZE; ++i)
		{
			if (!lst->page.blocks[i])
			{
				lst->page.blocks[i] = 1;
				return (lst->page.addr + i * get_block_size(type));
			}
		}
		lst = lst->next;
	}
	return (NULL);
}
