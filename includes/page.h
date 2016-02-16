/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:03:44 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/16 13:24:58 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAGE_H
# define PAGE_H

# include "block_type.h"

typedef struct		s_page
{
	t_block_type	type;
	size_t			len;
	void			*addr;
	int				blocks[PAGE_SIZE];
}					t_page;

#endif
