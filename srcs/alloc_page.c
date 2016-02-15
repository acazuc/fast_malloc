/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_page.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:11:23 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/15 15:14:44 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

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

t_page			alloc_page(t_block_type type)
{
	t_page	page;

	page.type = type;
	if (type == TINY || type == SMALL)
		init_0(&page);
	return (page);
}
