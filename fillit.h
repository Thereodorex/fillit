/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:48:47 by jcorwin           #+#    #+#             */
/*   Updated: 2018/12/23 22:52:28 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

# define USAGE { ft_putstr("usage:\tfillit filename\n"); return (0); }
# define ERROR(list) { list = ll_del(list); ft_putstr("error\n"); return (0); }

unsigned short	g_map[16];
unsigned short	g_len;

typedef struct	s_ll
{
	int				y;
	unsigned short	x[4];
	char			c;
	struct s_ll		*next;
}				t_ll;

t_ll			*ll_create(char c);
t_ll			*ll_del(t_ll *begin);
t_ll			*ll_pushback(t_ll *begin, char c);
void			ll_print(t_ll *begin);

int				tetr_check(t_ll *tetr);
int				tetr_gett(int fd, t_ll **list, int num);
void			tetr_mvup(t_ll *tetr);
void			tetr_mvleft(t_ll *tetr);
int				tetr_mvright(t_ll *tetr);

void			map_rm(t_ll *tetr);
int				map_put(t_ll *tetr);
int				map_fill(t_ll *tetr);
void			map_print(t_ll *list);

#endif
