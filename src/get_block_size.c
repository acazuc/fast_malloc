/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_block_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:09:18 by acazuc            #+#    #+#             */
/*   Updated: 2017/08/28 23:14:54 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t get_block_size(enum block_type type)
{
	if (type != TINY && type != SMALL)
		ft_putstr("invalid get_block_size type !\n");
	if (type == TINY)
		return (TINY_SIZE);
	return (SMALL_SIZE);
}
