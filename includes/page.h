/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:03:44 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/02 17:06:55 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAGE_H
# define PAGE_H

# include "block_type.h"

typedef struct		s_page
{
	t_block_list	*blocks;
	t_block_type	type;
	char			full;
}					t_page;

#endif
