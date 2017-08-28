/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpagesize_mult.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 14:35:30 by acazuc            #+#    #+#             */
/*   Updated: 2017/08/29 00:46:26 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t getpagesize_mult(size_t len)
{
	size_t page_size = getpagesize();
	size_t mod = len % page_size;
	if (!mod)
		return (len);
	return (len - mod + page_size);
}
