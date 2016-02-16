/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:32:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/16 11:37:14 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>

int		main(void)
{
	char	**str;
	char	*tmp;
	int		i;

	if (!(str = malloc(sizeof(*str) * 256)))
		exit(1);
	printf("%p\n", str);
	i = 0;
	while (i < 256)
	{
		if (!(tmp = malloc(sizeof(**str) * 2)))
			exit(1);
		printf("%p\n", tmp);
		str[i] = tmp;
		str[i][0] = i;
		str[i][1] = '\0';
		i++;
	}
	i = 0;
	while (i < 256)
	{
		printf("%s\n", str[i]);
		i++;
	}
	return (0);
}
