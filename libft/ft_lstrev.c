/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:28:44 by jcorwin           #+#    #+#             */
/*   Updated: 2018/11/29 21:25:57 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstrev(t_list *lst)
{
	t_list *end;

	end = NULL;
	if (!lst || !(lst->next))
		return (lst);
	if (lst->next->next)
		end = ft_lstrev(lst->next);
	else
		end = lst->next;
	lst->next->next = lst;
	lst->next = NULL;
	return (end);
}
