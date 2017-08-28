/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:11:39 by acazuc            #+#    #+#             */
/*   Updated: 2017/08/29 01:48:28 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

struct page_list *g_pages[4];
pthread_mutex_t g_malloc_mutex;

static int check_page_type_large(void *addr, struct page_list *lst)
{
	struct page_list *prv = NULL;
	while (lst)
	{
		if (addr == lst->page.addr)
		{
			if (prv)
				prv->next = lst->next;
			else
				g_pages[LARGE] = lst->next;
			munmap(lst, lst->page.page_len);
			MALLOC_UNLOCK();
			return (1);
		}
		prv = lst;
		lst = lst->next;
	}
	return (0);
}

static int check_page_type(void *addr, struct page_list *lst, enum block_type type)
{
	size_t page_size = get_page_size(type);
	size_t block_size = get_block_size(type);
	size_t item;
	while (lst)
	{
		if (addr >= lst->page.addr && addr <= lst->page.addr + page_size)
		{
			item = (addr - lst->page.addr) / block_size;
			if ((addr - lst->page.addr) % block_size == 0)
			{
				lst->page.blocks[item] = 0;
				check_free_pages(lst->page.type);
			}
			MALLOC_UNLOCK();
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

void free(void *addr)
{
	if (!addr)
		return;
	MALLOC_LOCK();
	if (check_page_type(addr, g_pages[TINY], TINY))
		goto end;
	if (check_page_type(addr, g_pages[SMALL], SMALL))
		goto end;
	if (check_page_type_large(addr, g_pages[LARGE]))
		goto end;
end:
	MALLOC_UNLOCK();
}
