/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_block_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:40:56 by acazuc            #+#    #+#             */
/*   Updated: 2017/08/29 01:48:59 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

enum block_type get_block_type(size_t len)
{
	if (len <= TINY_SIZE)
		return (TINY);
	if (len <= SMALL_SIZE)
		return (SMALL);
	if (len <= MEDIUM_SIZE)
		return (MEDIUM);
	return (LARGE);
}
