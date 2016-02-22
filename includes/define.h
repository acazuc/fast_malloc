/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:42:52 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/22 10:10:22 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define PAGE_SIZE 128

# define TINY_SIZE 128
# define SMALL_SIZE 1024

# define MALLOC_LOCK() pthread_mutex_lock(&g_malloc_mutex)
# define MALLOC_UNLOCK() pthread_mutex_unlock(&g_malloc_mutex)

#endif
