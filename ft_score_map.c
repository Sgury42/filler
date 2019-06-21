/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:30:22 by sgury             #+#    #+#             */
/*   Updated: 2019/06/21 16:30:39 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	place_score(t_map *map, int i, int j, int score_nb)
{
	char	score;

	if (score_nb > 9)
		score_nb = 9;
	score = score_nb + '0';
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

	i = 0;
	j = 0;
	while (i < map->x)
	{
		if (map->map[i][map->y / 2] == '.')
			map->map[i][map->y / 2] = '0';
		i++;
	}
	while (j < map->y)
	{
		if (map->map[map->x / 2][j] == '.')
			map->map[map->x / 2][j] = '0';
		j++;
	}
}

static void	set_zero(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		while (map->map[i][j])
		{
			if (map->map[i][j] == map->enemy)
			{
				place_score(map, i, j, 0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	zero_cross(map);
}

void	ft_score_map(t_map *map)
{
	int	i;
	int	j;
	int	score;

	i = 0;
	j = 0;
	score = 1;
	set_zero(map);
	while (score < 10)
	{
		while (i < map->x)
		{
			while (j < map->y)
			{
				if (ft_isdigit(map->map[i][j]) && score - 1 == map->map[i][j] - '0')
					place_score(map, i, j, score);
				j++;
			}
			i++;
			j = 0;
		}
		score++;
		i = 0;
		j = 0;
	}
}
