/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_free_pages.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 10:38:52 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/29 16:48:11 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page_list		*g_pages;

static int	is_page_free(t_page *page)
{
	int		i;

	i = 0;
	while (i < PAGE_SIZE)
	{
		if (page->blocks[i])
			return (0);
		++i;
	}
	return (1);
}

void		check_free_pages(t_block_type type)
{
	t_page_list		*lst;
	int				one_free;

	one_free = 0;
	lst = g_pages;
	while (lst)
	{
		if (lst->page.type == type && is_page_free(&lst->page))
		{
			if (!one_free)
				one_free = 1;
			else
			{
				remove_page(lst);
				munmap(lst, get_block_size(lst->page.type));
			}
		}
		lst = lst->next;
	}
}
