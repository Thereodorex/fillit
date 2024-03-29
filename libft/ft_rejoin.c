/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rejoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:08:49 by jcorwin           #+#    #+#             */
/*   Updated: 2018/12/06 19:14:22 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_rejoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (int)(len1 + len2 + 1))))
		return (NULL);
	str[len1 + len2] = '\0';
	i = 0;
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		str[i] = s2[i - len1];
		i++;
	}
	free(s1);
	return (str);
}
