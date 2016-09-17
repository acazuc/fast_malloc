/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 13:55:08 by acazuc            #+#    #+#             */
/*   Updated: 2016/09/17 13:57:23 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

#define M (1024 * 1024)

int		test3(void)
{
	char	*addr1;
	char	*addr2;
	char	*addr3;

	addr1 = malloc(16 * M);
	ft_strcpy(addr1, "Bonjours\n");
	ft_putstr(addr1);
	addr2 = malloc(16 * M);
	addr3 = realloc(addr1, 128 * M);
	addr3[127 * M] = 42;
	ft_putstr(addr3);
	return (0);
}

int		test4(void)
{
	char	*addr;

	addr = malloc(16);
	free(NULL);
	free((void*)addr + 5);
	if (realloc((void *)addr + 5, 10) == NULL)
		ft_putstr("Bonjours\n");
	return (0);
}

int		test5(void)
{
	malloc(1024);
	malloc(1024 * 32);
	malloc(1024 * 1024);
	malloc(1024 * 1024 * 16);
	malloc(1024 * 1024 * 128);
	show_alloc_mem();
	return (0);
}
