/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 10:49:17 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/30 12:15:45 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page_list		*g_pages;
pthread_mutex_t	g_malloc_mutex;

static void	*return_enomem(void *addr)
{
	if (addr == NULL)
		errno = ENOMEM;
	return (addr);
}

void		*realloc_large(t_page_list *lst, void *ptr, size_t len)
{
	size_t	i;
	void	*addr;

	if (!(addr = create_new_block(LARGE, len)))
	{
		MALLOC_UNLOCK();
		return (return_enomem(NULL));
	}
	i = 0;
	while (i < len && i < lst->page.len - sizeof(*lst))
	{
		((unsigned char*)addr)[i] = ((unsigned char*)ptr)[i];
		i++;
	}
	remove_page(lst);
	munmap(lst, lst->page.len);
	MALLOC_UNLOCK();
	return (return_enomem(addr));
}

void		*realloc_small_tiny(t_page_list *lst, void *ptr, size_t len)
{
	size_t	i;
	void	*addr;

	if (len <= get_block_size(lst->page.type))
	{
		MALLOC_UNLOCK();
		return (return_enomem(ptr));
	}
	if (!(addr = create_new_block(get_block_type(len), len)))
	{
		MALLOC_UNLOCK();
		return (return_enomem(NULL));
	}
	i = 0;
	while (i < len && i < lst->page.len - sizeof(*lst))
	{
		((unsigned char*)addr)[i] = ((unsigned char*)ptr)[i];
		i++;
	}
	free(ptr);
	MALLOC_UNLOCK();
	return (return_enomem(addr));
}

void		*realloc(void *addr, size_t len)
{
	t_page_list	*lst;
	int			item;

	if (addr == NULL)
		return (malloc(len));
	MALLOC_LOCK();
	lst = g_pages;
	while (lst)
	{
		if (lst->page.type == LARGE && addr == lst->page.addr)
			return (realloc_large(lst, addr, len));
		else if (lst->page.type != LARGE && addr >= lst->page.addr
				&& addr <= lst->page.addr + get_page_size(lst->page.type))
		{
			item = (addr - lst->page.addr) / get_block_size(lst->page.type);
			if (lst->page.addr + get_block_size(lst->page.type) * item == addr)
				return (realloc_small_tiny(lst, addr, len));
			return (return_enomem(NULL));
		}
		lst = lst->next;
	}
	MALLOC_UNLOCK();
	return (return_enomem(NULL));
}
