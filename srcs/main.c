/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:32:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/22 11:43:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>

# define SIZE 1000

int		test0(void)
{
	int		i;

	i = 0;
	while (i < 1024)
	{
		i++;
	}
	return (0);
}

int		test1(void)
{
	int		i;
	char	*addr;

	i = 0;
	while (i < 1024)
	{
		addr = malloc(1024);
		addr[0] = 42;
		i++;
	}
	return (0);
}

int		test2(void)
{
	int		i;
	char	*addr;

	i = 0;
	while (i < 1024)
	{
		addr = malloc(1024);
		addr[0] = 42;
		free(addr);
		i++;
	}
	return (0);
}

# define M (1024 * 1024)

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

int		main(void)
{
	test3();
	/*char	**str;
	char	*tmp;
	int		i;

	if (!(str = malloc(sizeof(*str) * SIZE)))
		exit(1);
	i = 0;
	while (i < SIZE)
	{
		if (!(tmp = malloc(sizeof(**str) * 2)))
			exit(1);
		tmp[0] = i;
		tmp[1] = '\0';
		str[i] = tmp;
		//free(tmp);
		i++;
	}
	i = 0;

	while (i < SIZE)
	{
		if (i % 2)
			free(str[i]);
		i++;
	}
	show_alloc_mem();
	return (0);*/
}
