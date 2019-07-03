/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:31:45 by sgury             #+#    #+#             */
/*   Updated: 2019/07/03 10:02:45 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_clear_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map != NULL)
	{
		while (map->map[i])
			ft_strdel(&map->map[i++]);
		if (map->map)
			free(map->map);
	}
}

void	ft_clear_piece(t_piece *piece)
{
	int	i;

	i = 0;
	if (piece->piece != NULL)
	{
		while (piece->piece[i])
			ft_strdel(&piece->piece[i++]);
		if (piece->piece)
			free(piece->piece);
	}
}

void	ft_clear_data(t_map *map, t_piece *piece)
{
	ft_clear_map(map);
	ft_clear_piece(piece);
}
