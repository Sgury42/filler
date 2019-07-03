/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:13:52 by sgury             #+#    #+#             */
/*   Updated: 2019/07/03 09:44:22 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_get_players(t_map *map, char *line)
{
	int	i;
	int nb;

	i = 0;
	if (ft_strstr(line, "$$$ exec p") == NULL)
		return (-1);
	while (line[i] && line[i] != 'p')
		i++;
	i++;
	nb = ft_atoi(line + i);
	if (nb == 1)
	{
		map->player = 'O';
		map->enemy = 'X';
	}
	else if (nb == 2)
	{
		map->player = 'X';
		map->enemy = 'O';
	}
	else
		return (-1);
	ft_strdel(&line);
	return (0);
}
