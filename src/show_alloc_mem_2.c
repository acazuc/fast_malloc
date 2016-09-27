/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 10:45:57 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/22 10:47:34 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		putaddrchar(char c)
{
	if (c > 9)
		ft_putchar(c - 10 + 'a');
	else
		ft_putchar(c + '0');
}

void		putaddr(size_t addr)
{
	if ((size_t)addr > 15)
	{
		putaddr(addr / 16);
		putaddr(addr % 16);
	}
	else
		putaddrchar((char)(addr % 16));
}
