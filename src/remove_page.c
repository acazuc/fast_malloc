/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_page.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 11:09:43 by acazuc            #+#    #+#             */
/*   Updated: 2017/08/29 01:50:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

struct page_list *g_pages[4];

void remove_page(struct page_list *page, enum block_type type)
{
	struct page_list *prv = NULL;
	struct page_list *lst = g_pages[type];
	while (lst)
	{
		if (lst == page)
		{
			if (!prv)
				g_pages[type] = lst->next;
			else
				prv->next = lst->next;
			return;
		}
		prv = lst;
		lst = lst->next;
	}
}
