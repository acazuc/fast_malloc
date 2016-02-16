/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_block_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 10:09:18 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/16 10:09:59 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t	get_block_size(t_block_type type)
{
	if (type == TINY)
		return (TINY_SIZE);
	return (SMALL_SIZE);
}
