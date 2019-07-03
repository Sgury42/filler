/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:02:11 by sgury             #+#    #+#             */
/*   Updated: 2019/07/03 10:02:50 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_map_size(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	map->x = ft_atoi(&line[i]);
	while (line[i] && line[i] != ' ')
		i++;
	map->y = ft_atoi(&line[i]);
	if (map->x == 0 || map->y == 0)
		return (-1);
	ft_strdel(&line);
	return (0);
}

int			parse_line(t_map *map, char *line, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	if ((map->map[i] = ft_strnew(map->y)) == NULL)
		return (-1);
	while (line[k] && !(ft_strchr(".oOxX", line[k])))
		k++;
	while (line[k] && j < map->y && ft_strchr(".oOxX", line[k]))
	{
		if (map->player_xstart == 0 && line[k] == map->player)
			map->player_xstart = i;
		map->map[i][j++] = ft_toupper(line[k++]);
	}
	ft_strdel(&line);
	map->map[i][j] = '\0';
	if (j != map->y)
		return (-1);
	return (0);
}

int			ft_get_map(t_map *map, char *line)
{
	int	length;

	length = 0;
	if (ft_strstr(line, "Plateau") == NULL || get_map_size(map, line) < 0
		|| (map->map = (char **)malloc(sizeof(char *) * (map->x + 1))) == NULL)
	{
		ft_strdel(&line);
		return (-1);
	}
	ft_memset(map->map, 0, sizeof(map->map));
	if ((get_next_line(0, &line)) < 0)
		return (-1);
	ft_strdel(&line);
	while (length < map->x)
	{
		if ((get_next_line(0, &line)) <= 0)
			return (-1);
		if (parse_line(map, line, length) < 0)
			return (-1);
		length++;
	}
	map->map[length] = 0;
	if (length != map->x)
		return (-1);
	return (0);
}
