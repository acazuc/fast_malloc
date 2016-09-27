/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_new_page.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:10:28 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/22 10:11:21 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page_list		*g_pages;

void	push_new_page(t_page_list *new)
{
	t_page_list		*lst;

	if (!g_pages)
		g_pages = new;
	else
	{
		lst = g_pages;
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
}
