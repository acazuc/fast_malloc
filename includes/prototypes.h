/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:48:21 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/22 11:14:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "page.h"
# include "page_list.h"
# include "block_type.h"

void			free(void *ptr);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			show_alloc_mem(void);
void			show_alloc_hex_mem(void);
t_page_list		*alloc_page(t_block_type type, size_t len);
size_t			get_page_size(t_block_type type);
void			push_new_page(t_page_list *page);
t_block_type	get_block_type(size_t len);
void			*get_existing_block(t_block_type type);
size_t			get_block_size(t_block_type type);
void			*create_new_block(t_block_type type, size_t len);
void			putaddrchar(char c);
void			putaddr(size_t addr);
void			remove_page(t_page_list *page);

#endif
