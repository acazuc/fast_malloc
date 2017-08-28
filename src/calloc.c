/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:31:22 by acazuc            #+#    #+#             */
/*   Updated: 2017/08/29 00:16:54 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*calloc(size_t count, size_t size)
{
	if (count * size / size != count)
		return (NULL);
	void *addr = malloc(count * size);
	if (addr)
		ft_memset(addr, 0, count * size);
	return (addr);
}
