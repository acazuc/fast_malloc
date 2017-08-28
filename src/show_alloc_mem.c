/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:23:47 by acazuc            #+#    #+#             */
/*   Updated: 2017/08/29 01:50:48 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

struct page_list *g_pages[4];
pthread_mutex_t g_malloc_mutex;
/*
static void print_block(size_t start, size_t end, size_t len)
{
	ft_putstr("0x");
	putaddr(start);
	ft_putstr(" - 0x");
	putaddr(end);
	ft_putstr(" : ");
	ft_putnbr(len);
	ft_putendl(" octets");
}

static void c_e(void **start, void *end, size_t *total)
{
	*total += end - *start;
	print_block((size_t)*start, (size_t)end, (size_t)(end - *start));
	*start = NULL;
}

static void print_page(struct page *page, size_t *total)
{
	if (page->type == LARGE)
	{
		*total += page->len - sizeof(struct page_list);
		print_block((size_t)page->addr, (size_t)(page->addr + page->len)
				, page->len);
		return ;
	}
	void *start = NULL;
	uint32_t i;
	for (i = 0; i < PAGE_SIZE; ++i)
	{
		if (page->blocks[i] == 1 && !start)
			start = page->addr + i * get_block_size(page->type);
		else if (page->blocks[i] == 0 && start)
			c_e(&start, page->addr + i * get_block_size(page->type), total);
	}
	if (start)
		c_e(&start, page->addr + i * get_block_size(page->type), total);
}

static struct page_list *try_push(size_t min)
{
	struct page_list *lowest = NULL;
	struct page_list *lst = g_pages;
	size_t lowest_val = -1;
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
}*/
