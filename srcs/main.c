/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:32:46 by acazuc            #+#    #+#             */
/*   Updated: 2016/02/16 13:38:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>

int		main(void)
{
	char	**str;
	char	*tmp;
	int		i;

	if (!(str = malloc(sizeof(*str) * 8000)))
		exit(1);
	printf("%p\n", str);
	i = 0;
	while (i < 8000)
	{
		if (!(tmp = malloc(sizeof(**str) * 2)))
			exit(1);
		//printf("%p\n", tmp);
		tmp[0] = i;
		tmp[1] = '\0';
		str[i] = tmp;
		//free(tmp);
		i++;
	}
	/*i = 0;
	while (i < 1024)
	{
		printf("%s\n", str[i]);
		i++;
	}*/
	return (0);
}
