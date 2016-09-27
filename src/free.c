/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:11:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/27 11:06:42 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page_list		*g_pages;
pthread_mutex_t	g_malloc_mutex;

static int		case_large(void *addr, t_page_list *prv, t_page_list *lst)
{
	if (addr == lst->page.addr)
	{
		if (prv)
			prv->next = lst->next;
		else
			g_pages = lst->next;
		munmap(lst, lst->page.len);
		MALLOC_UNLOCK();
		return (1);
	}
	return (0);
}

static void		case_else(void *addr, t_page_list *lst)
{
	int			item;

	item = (addr - lst->page.addr) / get_block_size(lst->page.type);
	if (lst->page.addr + get_block_size(lst->page.type) * item == addr)
	{
		lst->page.blocks[item] = 0;
		check_free_pages(lst->page.type);
	}
	MALLOC_UNLOCK();
}

void			free(void *addr)
{
	t_page_list	*prv;
	t_page_list	*lst;

	if (!addr)
		return ;
	MALLOC_LOCK();
	prv = NULL;
	lst = g_pages;
	while (lst)
	{
		if (lst->page.type == LARGE && case_large(addr, prv, lst))
			return ;
		else if (lst->page.type != LARGE && addr >= lst->page.addr
				&& addr <= lst->page.addr + get_page_size(lst->page.type))
		{
			case_else(addr, lst);
			return ;
		}
		prv = lst;
		lst = lst->next;
	}
	MALLOC_UNLOCK();
}
