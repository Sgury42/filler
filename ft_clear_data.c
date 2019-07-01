/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:31:45 by sgury             #+#    #+#             */
/*   Updated: 2019/07/01 12:27:39 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_clear_data(t_map *map, t_piece *piece)
{
	int	i;

	i = 0;
	while (map->map[i])
		ft_strdel(&map->map[i++]);
	if (map->map)
		free(map->map);
	i = 0;
	while (piece->piece[i])
		ft_strdel(&piece->piece[i++]);
	if (piece->piece)
		free(piece->piece);
	ft_bzero(&piece, sizeof(piece));
}
