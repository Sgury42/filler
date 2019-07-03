/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:18:09 by sgury             #+#    #+#             */
/*   Updated: 2019/07/03 10:53:26 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "stdio.h"

static int	filler(t_map *map, t_piece *piece, char *line)
{
	int	ret;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (ft_get_map(map, line) < 0)
			return (-1);
		if (get_next_line(0, &line) < 0)
			return (-1);
		if (ft_get_piece(piece, line) < 0)
			return (-1);
		ft_score_map(map);
		if (ft_place_piece(map, piece) == 0)
		{
			ft_clear_data(map, piece);
			break ;
		}
		ft_clear_data(map, piece);
	}
	return (ret == -1 ? -1 : 0);
}

int			main(void)
{
	char	*line;
	t_map	map;
	t_piece piece;

	ft_bzero(&map, sizeof(t_map));
	ft_bzero(&piece, sizeof(t_piece));
	if ((get_next_line(0, &line)) <= 0)
	{
		perror("");
		return (-1);
	}
	if (ft_get_players(&map, line) < 0)
	{
		ft_strdel(&line);
		perror("");
		return (-1);
	}
	if ((filler(&map, &piece, line)) < 0)
	{
		ft_clear_data(&map, &piece);
		perror("");
		return (-1);
	}
	ft_bzero(&map, sizeof(t_map));
	return (0);
}
