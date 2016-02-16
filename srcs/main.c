/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:32:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/16 15:35:23 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>

# define SIZE 100000

int		main(void)
{
	char	**str;
	char	*tmp;
	int		i;

	if (!(str = malloc(sizeof(*str) * SIZE)))
		exit(1);
	printf("%p\n", str);
	i = 0;
	while (i < SIZE)
	{
		if (!(tmp = malloc(sizeof(**str) * 2)))
			exit(1);
		tmp[0] = i;
		tmp[1] = '\0';
		str[i] = tmp;
		ft_putnbr(i);
		ft_putchar('\n');
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
	return (0);
}
