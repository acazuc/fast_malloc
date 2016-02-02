/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:30:55 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/02 17:08:12 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCK_LIST_H
# define BLOCK_LIST_H

typedef struct s_block_list	t_block_list;

struct				s_block_list
{
	void			*addr;
	char			used;
	t_block_list	*next;
};

#endif
