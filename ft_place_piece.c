/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 10:15:42 by sgury             #+#    #+#             */
/*   Updated: 2019/06/25 15:52:22 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"filler.h"

static void	send_solution(int x, int y)
{
	char	solution[50];

	ft_bzero(solution, sizeof(solution));
	ft_strcat(solution, ft_itoa(x));
	ft_strcat(solution, " ");
	ft_strcat(solution, ft_itoa(y));
	ft_strcat(solution, "\n");
	ft_putstr_fd(solution, 1);
}

static int	valid_spot(t_map *map, t_piece *piece, int x, int y)
{
	int	i;
	int	j;
	int	touch;
	int	score;

	i = 0;
	j = 0;
	touch = 0;
	score = 0;
	while (i < piece->x)
	{
		while (j < piece->y)
		{
			if (piece->piece[i][j] == '*' && map->map[x + i][y + j] == map->enemy)
				return (-1);
			if (piece->piece[i][j] == '*' && map->map[x + i][y + j] == map->player)
				touch++;
			if (piece->piece[i][j] == '*' && ft_isdigit(map->map[x + i][y + j]))
				score += map->map[x + i][y + j] - '0';
			j++;
		}
		j = 0;
		i++;
	}
	if (touch == 1)
		return (score);
	else
		return (-1);
}

void		ft_place_piece(t_map *map, t_piece *piece)
{
	t_solution	sol;
	int			x;
	int			y;
	int			score;

	ft_bzero(&sol, sizeof(t_solution));
	x = 0;
	y = 0;
	while (x + piece->x < map->x)
	{
		while (y + piece->y < map->y)
		{
			if ((score = valid_spot(map, piece, x, y)) > 0 && (score < sol.score || sol.score == 0))
			{
				sol.x = x;
				sol.y =y;
				sol.score = score;
			}
			y++;
		}
		y = 0;
		x++;
	}
	send_solution(sol.x, sol.y);
}
