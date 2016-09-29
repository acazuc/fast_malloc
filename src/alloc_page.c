/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_page.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:11:23 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/29 16:25:50 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void			init_0(t_page *page)
{
	int		i;

	i = 0;
	while (i < PAGE_SIZE)
	{
		page->blocks[i] = 0;
		i++;
	}
}

t_page_list			*alloc_page(t_block_type type, size_t len)
{
	t_page_list	*new;

	if (!(new = mmap(0, getpagesize_mult(len + sizeof(*new))
					, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	new->page.type = type;
	new->page.len = len + sizeof(*new);
	new->page.addr = new;
	new->page.addr += sizeof(*new);
	new->next = NULL;
	if (type == TINY || type == SMALL)
		init_0(&new->page);
	return (new);
}
