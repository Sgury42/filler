/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:08:59 by sgury             #+#    #+#             */
/*   Updated: 2019/06/12 15:15:03 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include "utils/get_next_line.h"

typedef struct	s_buff
{
	char	buffer[4096];
}				t_buff;

typedef struct	s_map
{
	int		x;		//height
	int 	y;		//width
	char	**map;
}				t_map;

typedef struct	s_piece
{
	int 	x;
	int 	y;
	char	**piece;
}				t_piece;

//int				get_next_line(const int fd, char **line);
//void			ft_putstr(char *str);
//void			ft_strdel(char **as);
//void			ft_putchar(char c);
//void			ft_putstr_fd(char *str, int fd);
//int				ft_printf(const char *format, ...);
int				ft_get_map(char *buff);
//char			*ft_strcat(char *s1, const char *s2);

#endif
