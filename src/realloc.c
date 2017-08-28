/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 10:49:17 by acazuc            #+#    #+#             */
/*   Updated: 2017/08/29 00:27:23 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

struct page_list *g_pages[3];
pthread_mutex_t g_malloc_mutex;

static size_t min(size_t a, size_t b)
{
	return (a < b ? a : b);
}

static void *realloc_large(struct page_list *lst, void *ptr, size_t len)
{
	void *addr;
	if (!(addr = create_new_block(LARGE, len)))
	{
		MALLOC_UNLOCK();
		errno = ENOMEM;
		return (NULL);
	}
	ft_memmove(addr, ptr, min(len, lst->page.len));
	remove_page(lst, LARGE);
	MALLOC_UNLOCK();
	return (addr);
}

static void *realloc_small_tiny(struct page_list *lst, void *ptr, size_t len)
{
	void	*addr;
	if (len <= get_block_size(lst->page.type))
	{
		MALLOC_UNLOCK();
		errno = 0;
		return (ptr);
	}
	if (!(addr = create_new_block(get_block_type(len), len)))
	{
		MALLOC_UNLOCK();
		errno = ENOMEM;
		return (NULL);
	}
	ft_memmove(addr, ptr, min(len, lst->page.len));
	free(ptr);
	MALLOC_UNLOCK();
	return (addr);
}

static void *realloc_test_large(void *addr, size_t len)
{
	struct page_list *lst = g_pages[LARGE];
	while (lst)
	{
		if (addr == lst->page.addr)
			return (realloc_large(lst, addr, len));
		lst = lst->next;
	}
	return (NULL);
}

static void *realloc_test_tiny_small(void *addr, size_t len, enum block_type type)
{
	size_t page_size = get_page_size(type);
	size_t block_size = get_block_size(type);
	struct page_list *lst = g_pages[type];
	while (lst)
	{
		if (addr >= lst->page.addr && addr <= lst->page.addr + page_size)
		{
			if ((addr - lst->page.addr) % block_size == 0)
				return (realloc_small_tiny(lst, addr, len));
		}
		lst = lst->next;
	}
	return (NULL);
}

void *realloc(void *addr, size_t len)
{
	if (!addr)
		return (malloc(len));
	if (addr && !len)
	{
		free(addr);
		return (NULL);
	}
	MALLOC_LOCK();
	void *ret;
	if ((ret = realloc_test_large(addr, len)))
		goto end;
	if ((ret = realloc_test_tiny_small(addr, len, TINY)))
		goto end;
	if ((ret = realloc_test_tiny_small(addr, len, SMALL)))
		goto end;
	ret = NULL;
end:
	MALLOC_UNLOCK();
	return (ret);
}
