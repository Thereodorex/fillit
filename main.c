/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:38:37 by jcorwin           #+#    #+#             */
/*   Updated: 2018/12/23 23:05:12 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "fillit.h"

int				main(int argc, char **argv)
{
	int		i;
	int		num;
	int		fd;
	t_ll	*list;

	i = -1;
	list = NULL;
	if (argc != 2)
		USAGE;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ERROR(list);
	while ((num = tetr_gett(fd, &list, ++i)) == 21)
		if (num == -1 || i > 26)
			ERROR(list);
	if (i < 0 || i > 25 || num != 20)
		ERROR(list);
	g_len = ft_minsqrt(i * 4);
	while (!map_fill(list))
		g_len++;
	map_print(list);
	close(fd);
	list = ll_del(list);
	return (0);
}
