/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_page_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 14:57:30 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/15 15:18:42 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t		get_page_size(t_block_type type)
{
	if (type == TINY)
		return (TINY_SIZE * PAGE_SIZE);
	return (SMALL_SIZE * PAGE_SIZE);
}
