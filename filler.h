/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:08:59 by sgury             #+#    #+#             */
/*   Updated: 2019/06/24 15:32:12 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct	s_map
{
	char	player;
	char	enemy;
	int	x;		//height
	int 	y;		//width
	char	**map;
}				t_map;

typedef struct	s_piece
{
	int 	x;
	int 	y;
	char	**piece;
}				t_piece;

typedef struct	s_solution
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		score;
}				t_solution;

int				ft_get_players(t_map *map, char *buff);
int				ft_get_map(t_map *map, char *buff);
int				ft_get_piece(t_piece *piece, char *buff);
void			ft_clear_data(char **map, char **piece);
void			ft_score_map(t_map *map);
void			ft_place_piece(t_map *map, t_piece *piece);


/*			FONCTIONS FOR TESTS			*/

void			ft_put_wrd_tab_fd(char **tab, char *separator, int fd);
void			display_mapstruct(t_map *map);
void			display_piece_struct(t_piece *piece);

#endif
