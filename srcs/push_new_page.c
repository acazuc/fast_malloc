/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_new_page.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 15:10:28 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/16 11:28:31 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page_list		*pages;

void	push_new_page(t_page_list *new)
{
	t_page_list		*lst;

	if (!pages)
		pages = new;
	else
	{
		lst = pages;
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
}
