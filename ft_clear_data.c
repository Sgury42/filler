/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:31:45 by sgury             #+#    #+#             */
/*   Updated: 2019/06/28 12:24:30 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_clear_data(t_map *map, t_piece *piece)
{
	int	i;

	i = 0;
	while (map->map[i])
		ft_strdel(&map->map[i++]);
	i = 0;
	while (piece->piece[i])
		ft_strdel(&piece->piece[i++]);
	ft_bzero(&piece, sizeof(piece));
}
