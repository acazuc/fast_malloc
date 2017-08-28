/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_new_page.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:10:28 by acazuc            #+#    #+#             */
/*   Updated: 2017/08/29 01:49:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

struct page_list *g_pages[4];

void push_new_page(struct page_list *new)
{
	enum block_type type = new->page.type;
	if (!g_pages[type])
	{
		g_pages[type] = new;
		return;
	}
	new->next = g_pages[type];
	g_pages[type] = new;
}
