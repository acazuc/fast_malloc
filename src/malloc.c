/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:39:20 by acazuc            #+#    #+#             */
/*   Updated: 2017/08/29 01:55:15 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

struct page_list *g_pages[4] = {NULL, NULL, NULL, NULL};
pthread_mutex_t g_malloc_mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;

void *malloc(size_t len)
{
	MALLOC_LOCK();
	void *addr;
	enum block_type type = get_block_type(len);
	if (type == LARGE || !(addr = get_existing_block(type)))
	{
		if (!(addr = create_new_block(type, len)))
		{
			MALLOC_UNLOCK();
			errno = ENOMEM;
			return (NULL);
		}
	}
	MALLOC_UNLOCK();
	return (addr);
}
