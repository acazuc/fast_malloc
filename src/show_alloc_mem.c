/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:23:47 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/29 16:48:23 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page_list		*g_pages;
pthread_mutex_t	g_malloc_mutex;

static void			print_block(size_t start, size_t end, size_t len)
{
	ft_putstr("0x");
	putaddr(start);
	ft_putstr(" - 0x");
	putaddr(end);
	ft_putstr(" : ");
	ft_putnbr(len);
	ft_putendl(" octets");
}

static void			c_e(void **start, void *end, size_t *total)
{
	*total += end - *start;
	print_block((size_t)*start, (size_t)end, (size_t)(end - *start));
	*start = NULL;
}

static void			print_page(t_page *page, size_t *total)
{
	void	*start;
	void	*end;
	int		i;

	if (page->type == LARGE)
	{
		*total += page->len - sizeof(t_page_list);
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

static t_page_list	*try_push(size_t min)
{
	t_page_list		*lowest;
	t_page_list		*lst;
	size_t			lowest_val;

	lowest = NULL;
	lst = g_pages;
	lowest_val = -1;
	while (lst)
	{
		if ((lowest_val == 0 || (size_t)lst < lowest_val) && (size_t)lst > min)
		{
			lowest = lst;
			lowest_val = (size_t)lowest;
		}
		lst = lst->next;
	}
	return (lowest);
}

void				show_alloc_mem(void)
{
	t_page_list		*tmp;
	size_t			total;

	MALLOC_LOCK();
	total = 0;
	tmp = NULL;
	while (1)
	{
		if (!(tmp = try_push((size_t)tmp)))
			break ;
		if (tmp->page.type == TINY)
			ft_putstr("TINY");
		else
			ft_putstr(tmp->page.type == SMALL ? "SMALL" : "LARGE");
		ft_putstr(" : 0x");
		putaddr((size_t)tmp->page.addr);
		ft_putchar('\n');
		print_page(&tmp->page, &total);
	}
	ft_putstr("Total: ");
	ft_putul(total);
	ft_putchar('\n');
	MALLOC_UNLOCK();
}
