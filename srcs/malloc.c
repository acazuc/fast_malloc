/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:39:20 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/16 11:34:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>

t_page_list		*pages = NULL;
pthread_mutex_t	malloc_mutex = PTHREAD_MUTEX_INITIALIZER;

void			*malloc(size_t len)
{
	t_block_type	type;
	void			*addr;

	MALLOC_LOCK();
	if (len == 0)
	{
		MALLOC_UNLOCK();
		return (NULL);
	}
	ft_putendl("Getting block type, checking for existing block");
	type = get_block_type(len);
	if (!(addr = get_existing_block(type)))
	{
		ft_putendl("No block found :(, creating new one");
		if (!(addr = create_new_block(type, len)))
		{
			ft_putendl("Failed to create block :(");
			MALLOC_UNLOCK();
			return (NULL);
		}
		ft_putendl("Created new block :D");
	}
	ft_putendl("Returning addr");
	MALLOC_UNLOCK();
	return (addr);
}
