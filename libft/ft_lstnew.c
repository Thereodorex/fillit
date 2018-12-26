/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:33:03 by jcorwin           #+#    #+#             */
/*   Updated: 2018/11/29 21:52:28 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content_size || !content)
		new->content = NULL;
	else
	{
		if (!(new->content = (void *)malloc(1 * content_size)))
		{
			free(new);
			return (NULL);
		}
		ft_memcpy((void*)(new->content), (const void *)content, content_size);
	}
	new->next = NULL;
	new->content_size = content ? content_size : 0;
	return (new);
}
