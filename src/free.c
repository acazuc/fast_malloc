/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:11:39 by acazuc            #+#    #+#             */
/*   Updated: 2017/08/29 01:00:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

struct page_list *g_pages[3];
pthread_mutex_t g_malloc_mutex;

static int case_large(void *addr, struct page_list *prv, struct page_list *lst)
{
	if (addr == lst->page.addr)
	{
		if (prv)
			prv->next = lst->next;
		else
			g_pages[LARGE] = lst->next;
		//munmap(lst, lst->page.page_len);
		MALLOC_UNLOCK();
		return (1);
	}
	return (0);
}

static void case_else(void *addr, struct page_list *lst)
{
	size_t block_size = get_block_size(lst->page.type);
	uint32_t item = (addr - lst->page.addr) / block_size;
	if (lst->page.addr + block_size * item == addr)
	{
		lst->page.blocks[item] = 0;
		check_free_pages(lst->page.type);
	}
	MALLOC_UNLOCK();
}

static int check_page_type_large(void *addr, struct page_list *lst)
{
	struct page_list *prv = NULL;
	while (lst)
	{
		if (case_large(addr, prv, lst))
			return (1);
		prv = lst;
		lst = lst->next;
	}
	return (0);
}

static int check_page_type(void *addr, struct page_list *lst, enum block_type type)
{
	size_t page_len = get_page_size(type);
	while (lst)
	{
		if (addr >= lst->page.addr && addr <= lst->page.addr + page_len)
		{
			case_else(addr, lst);
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
