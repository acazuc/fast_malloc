/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_page.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:11:23 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/21 15:57:14 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>

static void		init_0(t_page *page)
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

	if (!(new = mmap(0, len + sizeof(*new),  PROT_READ | PROT_WRITE
					, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	printf("Allocating %lu bytes (%lu bytes from len, %lu bytes from new)\n", len + sizeof(*new), len, sizeof(*new));
	new->page.type = type;
	new->page.len = len + sizeof(*new);
	new->page.addr = new;
	new->page.addr += sizeof(*new);
	new->next = NULL;
	if (type == TINY || type == SMALL)
		init_0(&new->page);
	return (new);
}
