/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:46:14 by jcorwin           #+#    #+#             */
/*   Updated: 2018/12/23 23:04:37 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "fillit.h"

int		tetr_check(t_ll *tetr)
{
	int				i;
	int				j;
	int				counter;

	tetr_mvup(tetr);
	tetr_mvleft(tetr);
	counter = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if ((tetr->x)[i] & (1 << (15 - j)))
				++counter;
		if (!((tetr->x)[i] ^ (5 << 13)) || !((tetr->x)[i] ^ (11 << 12)) ||
			!((tetr->x)[i] ^ (5 << 12)) || !((tetr->x)[i] ^ (13 << 12)) ||
			!((tetr->x)[i] ^ (9 << 12)))
			return (-1);
		if (i < 3 && (tetr->x)[i + 1] && !((tetr->x)[i + 1] & (tetr->x)[i]))
			return (-1);
	}
	return (counter == 4 ? 0 : -1);
}

int		tetr_gett(int fd, t_ll **list, int num)
{
	char	buf[21];
	int		i;
	t_ll	*last;

	if ((i = read(fd, buf, 21)) < 20)
		return (i == 0 ? 0 : -1);
	*list = ll_pushback(*list, 'A' + num);
	num = i;
	last = *list;
	while (last->next)
		last = last->next;
	if (i == 21 && buf[--i] != '\n')
		return (-1);
	while (i--)
		if ((i + 1) % 5)
		{
			if (buf[i] == '#')
				(last->x)[i / 5] = (last->x)[i / 5] | (1 << (15 - i % 5));
			else if (buf[i] != '.')
				return (-1);
		}
		else if (buf[i] != '\n')
			return (-1);
	return (tetr_check(last) ? -1 : num);
}

void	tetr_mvup(t_ll *tetr)
{
	int		i;
	int		j;

	j = 3;
	while ((tetr->x)[0] == 0 && j--)
	{
		i = -1;
		while (++i < 3)
		{
			(tetr->x)[i] = (tetr->x)[i + 1];
			(tetr->x)[i + 1] = 0;
		}
	}
}

void	tetr_mvleft(t_ll *tetr)
{
	int		j;

	j = 15;
	while ((tetr->x)[0] < (1 << 15) &&
			(tetr->x)[1] < (1 << 15) &&
			(tetr->x)[2] < (1 << 15) &&
			(tetr->x)[3] < (1 << 15) && j--)
	{
		(tetr->x)[0] = (tetr->x)[0] << 1;
		(tetr->x)[1] = (tetr->x)[1] << 1;
		(tetr->x)[2] = (tetr->x)[2] << 1;
		(tetr->x)[3] = (tetr->x)[3] << 1;
	}
}

int		tetr_mvright(t_ll *tetr)
{
	int		i;

	i = -1;
	while (++i < 4)
		if (((tetr->x)[i] >> 1) & (1 << (15 - g_len)))
		{
			tetr_mvleft(tetr);
			(tetr->y)++;
			if (g_len - tetr->y < 4 && (tetr->x)[g_len - tetr->y])
			{
				tetr_mvleft(tetr);
				tetr->y = 0;
				return (0);
			}
			return (1);
		}
	i = -1;
	while (++i < 4)
		(tetr->x)[i] = ((tetr->x)[i] >> 1);
	return (1);
}
