/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_existing_block.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:51:03 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/15 13:59:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page_list		*pages;

static int		is_full(t_page *page)
{
	int				i;

	i = 0;
	while (i < PAGE_SIZE)
	{
		if (page->blocks[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

void			*get_existing_block(t_block_type type)
{
	t_page_list		*lst;
	int				i;

	lst = pages;
	while (lst)
	{
		if (lst->page->type == typw && !(is_full(lst->page)))
		{
			i = get_first_free(lst->page);
			return (lst->page->addr + i * get_page_size(type));
		}
		lst = lst->next;
	}
	return (NULL);
}
