/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_existing_block.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:51:03 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/15 16:20:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page_list		*pages;

static int		get_first_free(t_page *page)
{
	int				i;

	i = 0;
	while (i < PAGE_SIZE)
	{
		ft_putstr("checking block ");
		ft_putnbr(i);
		ft_putchar('\n');
		if (page->blocks[i] == 0)
			return (i);
		ft_putendl("Was used :(");
		i++;
	}
	return (-1);
}

void			*get_existing_block(t_block_type type)
{
	t_page_list		*lst;
	int				i;

	lst = pages;
	while (lst)
	{
		ft_putendl("Checking page..");
		type = lst->page.type;
		ft_putendl("Did it segfault ?");
		if (lst->page.type == type && (i = get_first_free(&lst->page)) != -1)
		{
			ft_putendl("Found unused block");
			lst->page.blocks[i] = 1;
			ft_putendl("Set unused block to used");
			return (lst->page.addr + i * get_page_size(type));
		}
		ft_putendl("Was full :(");
		lst = lst->next;
	}
	return (NULL);
}
