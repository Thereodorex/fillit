/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:20:12 by jcorwin           #+#    #+#             */
/*   Updated: 2018/12/26 17:29:37 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "fillit.h"

void	map_rm(t_ll *tetr)
{
	int		i;

	i = -1;
	while (++i < 4)
		g_map[i + tetr->y] ^= (tetr->x)[i];
}

int		map_put(t_ll *tetr)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if ((g_map[tetr->y + i] & (tetr->x)[i]) ||
		((tetr->x)[i] & (1 << (15 - g_len))) ||
		(g_len - tetr->y < 4 && (tetr->x)[g_len - tetr->y]))
		{
			if (!tetr_mvright(tetr))
				return (0);
			else
				return (map_put(tetr));
		}
	}
	i = -1;
	while (++i < 4)
		g_map[tetr->y + i] |= (tetr->x)[i];
	return (1);
}

int		map_fill(t_ll *tetr)
{
	t_ll	*next;

	if (!tetr)
		return (1);
	next = tetr->next;
	while (map_put(tetr))
	{
		if (map_fill(next))
			return (1);
		map_rm(tetr);
		if (!tetr_mvright(tetr))
			break ;
	}
	return (0);
}

void	map_print(t_ll *list)
{
	char	**mapchar;
	int		i;
	int		j;

	mapchar = ft_initmap(g_len, g_len, '.');
	while (list)
	{
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while (++j < g_len)
				if ((list->x)[i] & (1 << (15 - j)))
					mapchar[i + list->y][j] = list->c;
		}
		list = list->next;
	}
	ft_putmap(mapchar);
	ft_delmap(mapchar, g_len);
}
