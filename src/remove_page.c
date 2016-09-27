/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_page.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 11:09:43 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/22 11:13:27 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page_list	*g_pages;

void	remove_page(t_page_list *page)
{
	t_page_list	*prv;
	t_page_list	*lst;

	prv = NULL;
	lst = g_pages;
	while (lst)
	{
		if (lst == page)
		{
			if (!prv)
				g_pages = lst->next;
			else
				prv->next = lst->next;
			return ;
		}
		prv = lst;
		lst = lst->next;
	}
}
