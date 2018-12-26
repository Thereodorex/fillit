/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:02:46 by jcorwin           #+#    #+#             */
/*   Updated: 2018/11/28 22:17:16 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static t_list	*add(t_list *lst, t_list *tocopy)
{
	t_list	*new;
	t_list	*last;

	if (!(new = ft_lstnew((void const *)tocopy->content, tocopy->content_size)))
		return (lst);
	if (!(lst))
		lst = new;
	else
	{
		last = lst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	return (lst);
}

static void		del(t_list *lst)
{
	t_list	*prev;
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		prev = tmp;
		tmp = tmp->next;
		free(prev->content);
		free(prev);
	}
	if (lst)
		free(lst);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newl;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	newl = NULL;
	while (lst)
	{
		tmp = f(lst);
		if (tmp)
		{
			if (!(newl = add(newl, tmp)))
			{
				del(newl);
				return (NULL);
			}
		}
		lst = lst->next;
	}
	return (newl);
}
