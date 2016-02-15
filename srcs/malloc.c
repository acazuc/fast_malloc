/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 13:39:20 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/15 13:52:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page_list		*pages = NULL;

void			*malloc(size_t len)
{
	t_block_type	type;
	void			*addr;

	if (len == 0)
		return (NULL);
	type = get_block_type(len);
	if (!(addr = get_existing_block(type)))
		if (!(addr = create_new_block(type)))
			return (NULL);
	return (addr);
}
