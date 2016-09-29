/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpagesize_mult.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 14:35:30 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/29 14:36:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t	getpagesize_mult(size_t len)
{
	if (len % getpagesize() == 0)
		return (len);
	return (((len / getpagesize()) + 1) * getpagesize());
}
