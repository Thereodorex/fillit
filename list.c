/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:49:01 by jcorwin           #+#    #+#             */
/*   Updated: 2018/12/23 17:08:28 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "libft/libft.h"

t_ll	*ll_create(char c)
{
	int		i;
	t_ll	*newn;

	if (!(newn = (t_ll*)malloc(sizeof(t_ll))))
		return (NULL);
	i = 0;
	while (i <= 3)
		(newn->x)[i++] = 0;
	newn->c = c;
	newn->y = 0;
	newn->next = NULL;
	return (newn);
}

t_ll	*ll_del(t_ll *begin)
{
	if (!begin)
		return (NULL);
	begin->next = ll_del(begin->next);
	free(begin);
	return (NULL);
}

t_ll	*ll_pushback(t_ll *begin, char c)
{
	t_ll	*tmp;

	if (!begin)
	{
		if (!(begin = ll_create(c)))
			return (NULL);
	}
	else
	{
		tmp = begin;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = ll_create(c)))
			return (NULL);
	}
	return (begin);
}

void	ll_print(t_ll *begin)
{
	int		i;
	int		j;

	while (begin)
	{
		j = -1;
		while (++j < 4)
		{
			i = -1;
			while (++i < 16)
				ft_putchar((begin->x[j] & (1 << (15 - i))) ? begin->c : '.');
			ft_putchar('\n');
		}
		ft_putchar('\n');
		begin = begin->next;
	}
}
