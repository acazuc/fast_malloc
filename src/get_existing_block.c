/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_existing_block.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:51:03 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/29 15:26:04 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page_list		*g_pages;

static int		get_first_free(t_page *page)
{
	int				i;

	i = 0;
	while (i < PAGE_SIZE)
	{
		if (page->blocks[i] == 0)
			return (i);
		i++;
	}
	return (-1);
}

void			*get_existing_block(t_block_type type)
{
	t_page_list		*lst;
	int				i;

	lst = g_pages;
	while (lst)
	{
		if (lst->page.type == type && (i = get_first_free(&lst->page)) != -1)
		{
			lst->page.blocks[i] = 1;
			return (lst->page.addr + i * get_block_size(type));
		}
		lst = lst->next;
	}
	return (NULL);
}
