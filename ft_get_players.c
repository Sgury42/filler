/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:13:52 by sgury             #+#    #+#             */
/*   Updated: 2019/06/24 11:36:53 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_get_players(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i] != 'p')
		i++;
	i++;
	if (line[i] == '1')
	{
		map->player = 'O';
		map->enemy = 'X';
	}
	if (line[i] == '2')
	{
		map->player = 'X';
		map->enemy = 'O';
	}
	ft_strdel(&line);
	return (0);
}
