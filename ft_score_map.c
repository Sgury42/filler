/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:30:22 by sgury             #+#    #+#             */
/*   Updated: 2019/06/27 14:14:12 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	place_score(t_map *map, int i, int j, char score)
{
//	char	score;

//	if (score_nb > 9)
//		score_nb = 9;
//	score = score_nb + '0';
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
	if (map->player == 'O' && map->x > 6)
		middle /= 2;
	else if (map->player == 'X' && map-> x > 6)
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
	y = 0;
	while (map->map[x])
	{
		while (map->map[x][y])
		{
			if (map->map[x][y] == '.')
				return (1);
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}

static void	fullfillmap(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->map[x])
	{
		y = 0;
		while (map->map[x][y])
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

	i = -1;
	j = -1;
	score = '1';
	set_zero(map);
	while (map_not_full(map) && score < 126)
	{
//		ft_putstr_fd("score = ", 2);
//		ft_putchar_fd(score, 2);
//		ft_putchar_fd('\n', 2);
		while (++i < map->x)
		{
			while (++j < map->y)
			{
				if (!(ft_strchr(".XO", map->map[i][j])) && score - 1 == map->map[i][j])
				{
					place_score(map, i, j, score);
				//	display_mapstruct(map);
				}
			}
			j = -1;
		}
		score++;
		i = -1;
		j = -1;
	}
	fullfillmap(map);
}
