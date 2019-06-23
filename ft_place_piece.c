/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 10:15:42 by sgury             #+#    #+#             */
/*   Updated: 2019/06/23 18:04:56 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"filler.h"

char	*ft_place_piece(t_map *map, t_piece *piece)
{
	int		x;
	int		y;
	int		i;
	int		j;
	int		common;
//	int		score;
	int		badopt;
	char	solution[50];
	char	*tmp;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	common = 0;
//	score = 0;
	ft_bzero(solution, sizeof(solution));
	while (x < map->x)
	{
		while (y < map->y)
		{
			while (i < piece->x)
			{
				while (j < piece->y)
				{
					if (piece->piece[i][j] == '*' && map->map[x + i][y + j] == map->enemy)
					{
						badopt = 1;
			//			break;
					}
					if (piece->piece[i][j] == '*' && map->map[x + i][y + j] == map->player)
						common++;
//					if (piece->piece[i][j] == '*' && ft_isdigit(map->map[x + i][y + j]))
//						score += map->map[x + i][y + j] - '0';
					j++;
				}
			//	if (badopt == 1)
			//		break;
				j = 0;
				i++;
			}
			if (common == 1 && badopt == 0)
			{
				ft_strcat(solution, ft_itoa(x));
				ft_strcat(solution, " ");
				ft_strcat(solution, ft_itoa(y));
				ft_strcat(solution, "\n");
//				ft_putstr_fd(solution, 1);
				tmp = solution;
				return (tmp);
			}
			badopt = 0;
//			score = 0;
			i = 0;
			j = 0;
			y++;
		}
		y = 0;
		x++;
	}
	return (NULL);
}
