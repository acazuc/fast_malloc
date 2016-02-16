/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:11:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/16 14:44:54 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page_list		*pages;
pthread_mutex_t	malloc_mutex;

void	free(void *addr)
{
	t_page_list	*prv;
	t_page_list	*lst;
	int			item;

	if (!addr)
		return ;
	MALLOC_LOCK();
	prv = NULL;
	lst = pages;
	while (lst)
	{
		if (lst->page.type == LARGE)
		{
			if (addr == lst->page.addr)
			{
				if (prv)
					prv->next = lst->next;
				else
					pages = lst->next;
				munmap(lst, lst->page.len);
				MALLOC_UNLOCK();
				return ;
			}
		}
		else if (addr >= lst->page.addr && addr <= lst->page.addr + get_page_size(lst->page.type))
		{
			item = (addr - lst->page.addr) / get_block_size(lst->page.type);
			if (lst->page.addr + get_block_size(lst->page.type) * item == addr)
				lst->page.blocks[item] = 0;
			lst->page.blocks[item] = 0;
			MALLOC_UNLOCK();
			return ;
		}
		prv = lst;
		lst = lst->next;
	}
	MALLOC_UNLOCK();
}
