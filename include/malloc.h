/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:26:43 by acazuc            #+#    #+#             */
/*   Updated: 2017/08/29 00:44:14 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# ifndef _GNU_SOURCE
#  define _GNU_SOURCE
# endif
# include <sys/mman.h>
# include <pthread.h>
# include <unistd.h>
# include <stdint.h>
# include <errno.h>

# include "../libft/include/libft.h"

# define PAGE_SIZE 126

# define TINY_SIZE 128
# define SMALL_SIZE 1006

# define MALLOC_LOCK() pthread_mutex_lock(&g_malloc_mutex);
# define MALLOC_UNLOCK() pthread_mutex_unlock(&g_malloc_mutex);

enum						block_type
{
	TINY = 0,
	SMALL,
	LARGE
};

struct page
{
	enum block_type type;
	size_t len;
	size_t page_len;
	void *addr;
	char blocks[PAGE_SIZE];
};

struct page_list
{
	struct page page;
	struct page_list *next;
};

void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void *calloc(size_t count, size_t size);
void show_alloc_mem(void);
void show_alloc_hex_mem(void);
struct page_list *alloc_page(enum block_type type, size_t len);
size_t get_page_size(enum block_type type);
void push_new_page(struct page_list *page);
enum block_type get_block_type(size_t len);
void *get_existing_block(enum block_type type);
size_t get_block_size(enum block_type type);
void *create_new_block(enum block_type type, size_t l);
void putaddrchar(char c);
void putaddr(size_t addr);
void remove_page(struct page_list *page, enum block_type type);
void check_free_pages(enum block_type type);
size_t getpagesize_mult(size_t len);

#endif
