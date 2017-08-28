/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_page.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:11:23 by acazuc            #+#    #+#             */
/*   Updated: 2017/08/29 01:14:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

struct page_list *alloc_page(enum block_type type, size_t len)
{
	struct page_list *new;
	size_t size = getpagesize_mult(len + sizeof(*new));
	if (!(new = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	new->page.type = type;
	new->page.len = len;
	new->page.page_len = size;
	new->page.addr = new;
	new->page.addr += sizeof(*new);
	new->next = NULL;
	if (type == TINY || type == SMALL)
		ft_memset(new->page.blocks, 0, sizeof(new->page.blocks));
	return (new);
}
