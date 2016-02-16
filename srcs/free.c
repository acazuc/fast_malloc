/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:11:39 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/16 13:31:44 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page_list		*pages;
pthread_mutex_t	malloc_mutex;

void	free(void *addr)
{
	t_page_list	*lst;
	int			item;

	if (!addr)
		return ;
	MALLOC_LOCK();
	lst = pages;
	while (lst)
	{
		if (lst->page.type == LARGE)
		{
			if (addr == lst->page.addr)
			{
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
		lst = lst->next;
	}
	MALLOC_UNLOCK();
}
