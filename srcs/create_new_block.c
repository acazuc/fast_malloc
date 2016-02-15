/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_block.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:54:28 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/15 16:20:28 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*create_new_block(t_block_type type, size_t len)
{
	t_page		page;
	void		*addr;
	int			i;

	page = alloc_page(type);
	if (!(addr = mmap(0, type == LARGE ? len : get_page_size(type)
					, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	page.addr = addr;
	i = 0;
	while (i < PAGE_SIZE)
	{
		page.blocks[i] = 0;
		i++;
	}
	page.blocks[0] = 1;
	push_new_page(page);
	return (addr);
}
