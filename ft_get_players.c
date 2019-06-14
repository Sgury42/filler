/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_players.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:13:52 by sgury             #+#    #+#             */
/*   Updated: 2019/06/14 15:20:38 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*ft_get_players(t_map *map, char *buff)
{
	ft_bzero(map, sizeof(t_map));
	if ((buff = ft_strchr(buff, 'p')) == NULL)
		return (NULL);
	buff++;
	if (*buff == '1')
	{
		ft_strcat(map->player, "oO");
		ft_strcat(map->enemy, "xX");
	}
	if (*buff == '2')
	{
		ft_strcat(map->player, "xX");
		ft_strcat(map->enemy, "oO");
	}
	else
		return (NULL);
	return (buff);
}
