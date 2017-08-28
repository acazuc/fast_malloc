/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:39:20 by acazuc            #+#    #+#             */
/*   Updated: 2017/08/28 21:42:21 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page_list		*g_pages = NULL;
pthread_mutex_t	g_malloc_mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;

void			*malloc(size_t len)
{
	t_block_type	type;
	void			*addr;

	MALLOC_LOCK();
	type = get_block_type(len);
	if (type == LARGE || !(addr = get_existing_block(type)))
	{
		if (!(addr = create_new_block(type, len)))
		{
			ft_putstr("malloc enomem\n");
			errno = ENOMEM;
			MALLOC_UNLOCK();
			return (NULL);
		}
	}
	MALLOC_UNLOCK();
	return (addr);
}
