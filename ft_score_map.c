/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:30:22 by sgury             #+#    #+#             */
/*   Updated: 2019/06/16 11:44:43 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_score_map(t_map *map)
{
	int	i;
	int	j;
	int	score;

	i = 0;
	j = 0;
	score = 1;
	while (map->map[i])
	{
		while (map->map[i][j])
		{
			if (map->map[i][j + 1] == 
		}
	}
}
