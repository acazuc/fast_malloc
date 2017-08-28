/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:31:22 by acazuc            #+#    #+#             */
/*   Updated: 2017/08/28 20:55:23 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*calloc(size_t count, size_t size)
{
	char	*addr;

	if (count * size / size != count)
		return (NULL);
	addr = malloc(count * size);
	if (addr)
		ft_bzero(addr, count * size);
	return (addr);
}
