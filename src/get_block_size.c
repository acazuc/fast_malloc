/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_block_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:09:18 by acazuc            #+#    #+#             */
/*   Updated: 2017/08/29 01:48:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t get_block_size(enum block_type type)
{
	if (type == TINY)
		return (TINY_SIZE);
	if (type == SMALL)
		return (SMALL_SIZE);
	return (MEDIUM_SIZE);
}
