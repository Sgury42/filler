/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:13:52 by sgury             #+#    #+#             */
/*   Updated: 2019/06/16 12:11:59 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*ft_get_players(t_map *map, char *buff)
{
	if ((buff = ft_strchr(buff, 'p')) == NULL)
		return (NULL);
	buff++;
	if (*buff == '1')
	{
		map->player = 'O';
		map->enemy = 'X';
	}
	if (*buff == '2')
	{
		map->player = 'X';
		map->enemy = 'O';
	}
	else
		return (NULL);
	return (buff);
}
