/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 10:15:42 by sgury             #+#    #+#             */
/*   Updated: 2019/06/30 14:19:30 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"filler.h"

static int	send_solution(int x, int y)
{
	char	*solution;

	if ((solution = ft_itoa(x)) == NULL)
		return (-1);
	ft_putstr(solution);
	ft_strdel(&solution);
	ft_putchar(' ');
	if ((solution = ft_itoa(y)) == NULL)
		return (-1);
	ft_putendl(solution);
	ft_strdel(&solution);
	return (0);
}

static int	valid_spot(t_map *map, t_piece *piece, int x, int y)
{
	int	i;
	int	j;
	int	touch;
	int	score;

	i = 0;
	touch = 0;
	score = 0;
	while (i < piece->height)
	{
		j = 0;
		while (j < piece->width)
		{
			if (piece->piece[i][j] == '*' && map->map[x + i][y + j] == map->enemy)
				return (-1);
			else if (piece->piece[i][j] == '*' && map->map[x + i][y + j] == map->player)
				touch++;
			else if (piece->piece[i][j] == '*')
				score += map->map[x + i][y + j];
			j++;
		}
		i++;
	}
	if (touch == 1)
		return (score);
	else
		return (-1);
}

int			ft_place_piece(t_map *map, t_piece *piece)
{
	t_solution	sol;
	int			x;
	int			y;
	int			score;

	ft_bzero(&sol, sizeof(t_solution));
	x = 0;
	while (x + piece->height <= map->x)
	{
		y = 0;
		while (y + piece->width <= map->y)
		{
			if ((score = valid_spot(map, piece, x, y)) > 0 && (score < sol.score || sol.score == 0))
			{
				sol.x = x - piece->empty_lines;
				sol.y = y - piece->empty_col;
				sol.score = score;
				if (sol.x == 0 && sol.y == 0)
					sol.score = 0;
			}
			y++;
		}
		x++;
	}
	if ((send_solution(sol.x, sol.y)) < 0)
		return (-1);
	if (sol.x == 0 && sol.y == 0)
		return (0);
	return (1);
}
