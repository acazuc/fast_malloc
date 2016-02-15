/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:04:31 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/15 15:44:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAGE_LIST_H
# define PAGE_LIST_H

# include "page.h"

typedef struct s_page_list	t_page_list;

struct				s_page_list
{
	t_page			page;
	t_page_list		*next;
};

#endif
