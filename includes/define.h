/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:42:52 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/02 17:09:49 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define TINY_SIZE 32
# define TINY_PAGE_SIZE 4096
# define SMALL_SIZE 4096
# define SMALL_PAGE_SIZE 524288
# define MALLOC_LOCK() pthread_mutex_lock(&malloc_mutex)
# define MALLOC_UNLOCK() pthread_mutex_unlock(&malloc_mutex)

#endif
