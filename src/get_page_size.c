/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_page_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:57:30 by acazuc            #+#    #+#             */
/*   Updated: 2017/08/28 23:15:44 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t get_page_size(enum block_type type)
{
	if (type != TINY && type != SMALL)
		ft_putstr("Invalid get_page_size type !\n");
	if (type == TINY)
		return (TINY_SIZE * PAGE_SIZE);
	return (SMALL_SIZE * PAGE_SIZE);
}
