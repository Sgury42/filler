/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:13:52 by sgury             #+#    #+#             */
/*   Updated: 2019/07/01 11:13:53 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_get_players(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != 'p')
		i++;
	i++;
	if (line[i] == '1')
	{
		map->player = 'O';
		map->enemy = 'X';
	}
	else if (line[i] == '2')
	{
		map->player = 'X';
		map->enemy = 'O';
	}
	else
	{
		ft_strdel(&line);
		return (-1);
	}
	ft_strdel(&line);
	return (0);
}
