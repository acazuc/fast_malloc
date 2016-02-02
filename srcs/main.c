/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:32:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/02 17:00:41 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

pthread_mutex_t	malloc_mutex = PTHREAD_MUTEX_INITIALIZER;

int		main(void)
{
	MALLOC_LOCK();
	MALLOC_UNLOCK();
	MALLOC_LOCK();
	MALLOC_UNLOCK();
	return (0);
}
