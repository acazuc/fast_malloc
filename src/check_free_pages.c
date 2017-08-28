/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_free_pages.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 10:38:52 by acazuc            #+#    #+#             */
/*   Updated: 2017/08/29 01:48:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

struct page_list *g_pages[4];

static int is_page_free(struct page *page)
{
	for (uint32_t i = 0; i < PAGE_SIZE; ++i)
	{
		if (page->blocks[i])
			return (0);
	}
	return (1);
}

void check_free_pages(enum block_type type)
{
	char one_free = 0;
	struct page_list *lst = g_pages[type];
	struct page_list *prv = NULL;
	while (lst)
	{
		if (is_page_free(&lst->page))
		{
			if (!one_free)
			{
				one_free = 1;
			}
			else
			{
				if (prv)
					prv->next = lst->next;
				else
					g_pages[type] = lst->next;
				munmap(lst, lst->page.page_len);
				return;
			}
		}
		prv = lst;
		lst = lst->next;
	}
}
