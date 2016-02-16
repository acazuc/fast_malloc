/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:23:47 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/16 15:15:47 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page_list		*pages;
pthread_mutex_t	malloc_mutex;

static void		putaddrchar(char c)
{
	if (c > 9)
		ft_putchar(c - 10 + 'a');
	else
		ft_putchar(c + '0');
}

static void		putaddr(size_t addr)
{
	if ((size_t)addr > 15)
	{
		putaddr(addr / 16);
		putaddr(addr % 16);
	}
	else
		putaddrchar((char)(addr % 16));
}

static void		print_page(t_page *page)
{
	void	*start;
	void	*end;
	int		i;

	if (page->type == LARGE)
	{
		ft_putstr("0x");
		putaddr((size_t)page->addr);
		ft_putstr(" - 0x");
		putaddr((size_t)(page->addr + page->len));
		ft_putstr(" : ");
		ft_putnbr(page->len);
		ft_putendl(" octets");
		return ;
	}
	start = NULL;
	end = NULL;
	i = 0;
	while (i < PAGE_SIZE)
	{
		if (page->blocks[i] == 1)
		{
			if (!start)
				start = page->addr + i * get_block_size(page->type);
		}
		else if (start)
		{
			end = page->addr + i * get_block_size(page->type);
			ft_putstr("0x");
			putaddr((size_t)start);
			ft_putstr(" - 0x");
			putaddr((size_t)end);
			ft_putstr(" : ");
			ft_putnbr(end - start);
			ft_putendl(" octets");
			start = NULL;
		}
		i++;
	}
	if (start)
	{
		end = page->addr + i * get_block_size(page->type);
		ft_putstr("0x");
		putaddr((size_t)start);
		ft_putstr(" - 0x");
		putaddr((size_t)end);
		ft_putstr(" : ");
		ft_putnbr(end - start);
		ft_putendl(" octets");
		start = NULL;
	}
}

void	show_alloc_mem(void)
{
	t_page_list		*lst;

	MALLOC_LOCK();
	lst = pages;
	while (lst)
	{
		if (lst->page.type == TINY)
			ft_putstr("TINY");
		else
			ft_putstr(lst->page.type == SMALL ? "SMALL" : "LARGE");
		ft_putstr(" : 0x");
		putaddr((size_t)lst->page.addr);
		ft_putchar('\n');
		print_page(&lst->page);
		lst = lst->next;
	}
	MALLOC_UNLOCK();
}
