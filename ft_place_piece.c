/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 10:15:42 by sgury             #+#    #+#             */
/*   Updated: 2019/06/24 15:32:14 by sgury            ###   ########.fr       */
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

static void get_score(t_map *map, t_piece *piece, t_solution *solution)
{
	int	i;
	int	j;
	int	badspot;
	int touch;
	int	new_score;

	i = 0;
	j = 0;
	badspot = 0;
	new_score = 0;
	touch = 0;
	while (i < piece->x)
	{
		while (j < piece->y)
		{
			if (piece->piece[i][j] == '*' && map->map[solution->i + i][solution->j + j] == map->enemy)
			{
				badspot = 1;
				break;
			}
			if (piece->piece[i][j] == '*' && map->map[solution->i + i][solution->j + j] == map->player)
				touch++;
			if (piece->piece[i][j] == '*' && ft_isdigit(map->map[solution->i + i][solution->j + j]))
				new_score += map->map[solution->i + i][solution->j + j] - '0';
			j++;
		}
		if (badspot)
			break;
		j = 0;
		i++;
	}
	if ((new_score < solution->score || solution->score == 0) && touch == 1 && badspot == 0)
	{
		solution->x = solution->i;
		solution->y = solution->j;
		solution->score = new_score;
	}
}

void		ft_place_piece(t_map *map, t_piece *piece)
{
	t_solution	solution;

	ft_bzero(&solution, sizeof(t_solution));
	while (solution.i + piece->x < map->x)
	{
		while (solution.j + piece->y < map->y)
		{
			get_score(map, piece, &solution);
			solution.j++;
		}
		solution.j = 0;
		solution.i++;
	}
	send_solution(solution.x, solution.y);
}
