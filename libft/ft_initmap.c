/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:40:54 by jcorwin           #+#    #+#             */
/*   Updated: 2018/12/23 19:09:50 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_initmap(int len, int height, char c)
{
	char	**mapchar;
	int		i;
	int		j;

	mapchar = (char**)malloc(sizeof(char*) * (height + 1));
	i = -1;
	while (++i < (height + 1))
		mapchar[i] = (char*)malloc(sizeof(char) * (len + 1));
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < len)
			mapchar[i][j] = c;
		mapchar[i][j] = '\0';
	}
	mapchar[i][0] = '\0';
	return (mapchar);
}
