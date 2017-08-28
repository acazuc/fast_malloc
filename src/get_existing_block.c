/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_existing_block.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:51:03 by acazuc            #+#    #+#             */
/*   Updated: 2017/08/28 23:14:47 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

struct page_list *g_pages[3];

static int32_t get_first_free(struct page *page)
{
	for (int32_t i = 0; i < PAGE_SIZE; ++i)
	{
		if (page->blocks[i] == 0)
			return (i);
	}
	return (-1);
}

void *get_existing_block(enum block_type type)
{
	if (type != TINY && type != SMALL)
		ft_putstr("invalid get_existing_block type !\n");
	int32_t i;
	struct page_list *lst = g_pages[type];
	while (lst)
	{
		if ((i = get_first_free(&lst->page)) != -1)
		{
			lst->page.blocks[i] = 1;
			return (lst->page.addr + i * get_block_size(type));
		}
		lst = lst->next;
	}
	return (NULL);
}
