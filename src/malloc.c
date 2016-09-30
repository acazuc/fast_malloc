/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:39:20 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/30 12:16:20 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page_list		*g_pages = NULL;
pthread_mutex_t	g_malloc_mutex = PTHREAD_MUTEX_INITIALIZER;

static void		*return_enomem(void *ptr)
{
	if (ptr == NULL)
		errno = ENOMEM;
	MALLOC_UNLOCK();
	return (ptr);
}

void			*malloc(size_t len)
{
	t_block_type	type;
	void			*addr;

	MALLOC_LOCK();
	if (len == 0)
		return (return_enomem(NULL));
	type = get_block_type(len);
	if (type == LARGE || !(addr = get_existing_block(type)))
	{
		if (!(addr = create_new_block(type, len)))
			return (return_enomem(NULL));
	}
	return (return_enomem(addr));
}
