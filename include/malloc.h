/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:26:43 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/27 11:14:11 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include <unistd.h>
# include <pthread.h>

# include "../libft/includes/libft.h"

# define PAGE_SIZE 128

# define TINY_SIZE 128
# define SMALL_SIZE 1024

# define MALLOC_LOCK() pthread_mutex_lock(&g_malloc_mutex)
# define MALLOC_UNLOCK() pthread_mutex_unlock(&g_malloc_mutex)

typedef enum e_block_type	t_block_type;
typedef struct s_page_list	t_page_list;
typedef struct s_page		t_page;

void						free(void *ptr);
void						*malloc(size_t size);
void						*realloc(void *ptr, size_t size);
void						show_alloc_mem(void);
void						show_alloc_hex_mem(void);
t_page_list					*alloc_page(t_block_type type, size_t len);
size_t						get_page_size(t_block_type type);
void						push_new_page(t_page_list *page);
t_block_type				get_block_type(size_t len);
void						*get_existing_block(t_block_type type);
size_t						get_block_size(t_block_type type);
void						*create_new_block(t_block_type t, size_t l);
void						putaddrchar(char c);
void						putaddr(size_t addr);
void						remove_page(t_page_list *page);
void						check_free_pages(t_block_type type);
int							test3(void);
int							test4(void);
int							test5(void);

enum						e_block_type
{
	TINY,
	SMALL,
	LARGE
};

struct						s_page
{
	t_block_type			type;
	size_t					len;
	void					*addr;
	int						blocks[PAGE_SIZE];
};

struct						s_page_list
{
	t_page					page;
	t_page_list				*next;
};

#endif
