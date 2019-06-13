/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:08:59 by sgury             #+#    #+#             */
/*   Updated: 2019/06/13 15:47:35 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include "utils/get_next_line.h"

typedef struct	s_map
{
	char	player[2];
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
char			*ft_get_map(t_map *map, char *buff);
int				ft_get_piece(t_piece *piece, char *buff);
//char			*ft_strcat(char *s1, const char *s2);



/*			FONCTIONS FOR TESTS			*/

void			ft_put_wrd_tab_fd(char **tab, char *separator, int fd);
void			display_mapstruct(t_map *map);
void			display_piece_struct(t_piece *piece);

#endif
