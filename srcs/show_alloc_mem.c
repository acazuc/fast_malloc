/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:23:47 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/22 10:46:42 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page_list		*g_pages;
pthread_mutex_t	g_malloc_mutex;

static void		print_block(size_t start, size_t end, size_t len)
{
	ft_putstr("0x");
	putaddr(start);
	ft_putstr(" - 0x");
	putaddr(end);
	ft_putstr(" : ");
	ft_putnbr(len);
	ft_putendl(" octets");
}

static void		c_e(void **start, void *end, size_t *total)
{
	*total += end - *start;
	print_block((size_t)*start, (size_t)end, (size_t)(end - *start));
	*start = NULL;
}

static void		print_page(t_page *page, size_t *total)
{
	void	*start;
	void	*end;
	int		i;

	if (page->type == LARGE)
	{
		print_block((size_t)page->addr, (size_t)(page->addr + page->len)
				, page->len);
		return ;
	}
	start = NULL;
	end = NULL;
	i = -1;
	while (++i < PAGE_SIZE)
	{
		if (page->blocks[i] == 1 && !start)
			start = page->addr + i * get_block_size(page->type);
		else if (page->blocks[i] == 0 && start)
			c_e(&start, page->addr + i * get_block_size(page->type), total);
	}
	if (start)
		c_e(&start, page->addr + i * get_block_size(page->type), total);
}

void			show_alloc_mem(void)
{
	t_page_list		*lst;
	size_t			total;

	MALLOC_LOCK();
	total = 0;
	lst = g_pages;
	while (lst)
	{
		if (lst->page.type == TINY)
			ft_putstr("TINY");
		else
			ft_putstr(lst->page.type == SMALL ? "SMALL" : "LARGE");
		ft_putstr(" : 0x");
		putaddr((size_t)lst->page.addr);
		ft_putchar('\n');
		print_page(&lst->page, &total);
		lst = lst->next;
	}
	ft_putstr("Total: ");
	ft_putul(total);
	ft_putchar('\n');
	MALLOC_UNLOCK();
}
