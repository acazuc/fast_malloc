/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:03:44 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/15 14:31:09 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAGE_H
# define PAGE_H

# include "block_type.h"

typedef struct		s_page
{
	t_block_type	type;
	void			*addr;
	int				blocks[PAGE_SIZE];
}					t_page;

#endif
