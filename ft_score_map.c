/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:30:22 by sgury             #+#    #+#             */
/*   Updated: 2019/07/01 10:16:11 by sgury            ###   ########.fr       */
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

static int	checkmap_full(t_map *map, int fullfill)
{
	int	x;
	int	y;

	x = -1;
	while (++x < map->x)
	{
		y = -1;
		while (++y < map->y)
		{
			if (map->map[x][y] == '.')
			{
				if (fullfill == 1)
					map->map[x][y] = 126;
				else
					return (1);
			}
		}
	}
	return (0);
}

void		ft_score_map(t_map *map)
{
	int		i;
	int		j;
	char	score;

	score = '1';
	set_zero(map);
	while (checkmap_full(map, 0) && score < 126)
	{
		i = -1;
		while (++i < map->x)
		{
			j = -1;
			while (++j < map->y)
			{
				if (!(ft_strchr(".XO", map->map[i][j]))
						&& score - 1 == map->map[i][j])
					place_score(map, i, j, score);
			}
		}
		score++;
		if (ft_strchr("XO", score))
			score++;
	}
	checkmap_full(map, 1);
}
