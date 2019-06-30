/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:30:22 by sgury             #+#    #+#             */
/*   Updated: 2019/06/30 14:02:19 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	place_score(t_map *map, int i, int j, char score)
{
	if (j + 1 < map->y && map->map[i][j + 1] == '.')
		map->map[i][j + 1] = score;
	if (i + 1 < map->x && map->map[i + 1][j] == '.')
		map->map[i + 1][j] = score;
	if (j - 1 >= 0 && map->map[i][j - 1] == '.')
		map->map[i][j - 1] = score;
	if (i - 1 >= 0 && map->map[i - 1][j] == '.')
		map->map[i - 1][j] = score;
	if (i + 1 < map->x && j + 1 < map->y && map->map[i + 1][j + 1] == '.')
		map->map[i + 1][j + 1] = score;
	if (i + 1 < map->x && j - 1 >= 0 && map->map[i + 1][j - 1] == '.')
		map->map[i + 1][j - 1] = score;
	if (i - 1 >= 0 && j + 1 < map->y && map->map[i - 1][j + 1] == '.')
		map->map[i - 1][j + 1] = score;
	if (i - 1 >= 0 && j - 1 >= 0 && map->map[i - 1][j - 1] == '.')
		map->map[i - 1][j - 1] = score;
}

static void	zero_cross(t_map *map)
{
	int	i;
	int	j;
	int	middle;

	i = 0;
	j = 0;
	while (i < map->x)
	{
		if (map->map[i][map->y / 2] == '.')
			map->map[i][map->y / 2] = '3';
		i++;
	}
	middle = map->x / 2;
	if (map->player_xstart < middle && map->x > 15)
		middle /= 2;
	else if (map->player_xstart > middle && map->x > 15)
		middle += middle / 2 - 1;
	while (j < map->y)
	{
		if (map->map[middle][j] == '.')
			map->map[middle][j] = '+';
		j++;
	}
}

static void	set_zero(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->x)
	{
		while (j < map->y)
		{
			if (map->map[i][j] == map->enemy)
			{
				place_score(map, i, j, '0');
			}
			j++;
		}
		i++;
		j = 0;
	}
	zero_cross(map);
}

static int	map_not_full(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->x)
	{
		y = 0;
		while (y < map->y)
		{
			if (map->map[x][y] == '.')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}

static void	fullfillmap(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->x)
	{
		y = 0;
		while (y < map->y)
		{
			if (map->map[x][y] == '.')
				map->map[x][y] = 126;
			y++;
		}
		x++;
	}
}

void		ft_score_map(t_map *map)
{
	int		i;
	int		j;
	char	score;

	score = '1';
	set_zero(map);
	while (map_not_full(map) && score < 126)
	{
		i = 0;
		while (i < map->x)
		{
			j = 0;
			while (j < map->y)
			{
				if (!(ft_strchr(".XO", map->map[i][j])) && score - 1 == map->map[i][j])
					place_score(map, i, j, score);
				j++;
			}
			i++;
		}
		score++;
		if (ft_strchr("XO", score))
			score++;
	}
	fullfillmap(map);
}
