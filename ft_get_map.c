/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:02:11 by sgury             #+#    #+#             */
/*   Updated: 2019/06/14 15:30:49 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	*get_map_size(t_map *map, char *buff)
{
	if ((buff = ft_strstr(buff, "Plateau")) == NULL)
		return (NULL);
	while (*buff && !ft_isdigit(*buff))
		buff++;
	map->x = ft_atoi(buff);
	if ((buff = ft_strchr(buff, ' ')) == NULL)
		return (NULL);
	map->y = ft_atoi(buff);
	return (buff);
}

static char	*checkmap(t_map *map, char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((map->map = (char **)malloc(sizeof(char *) * (map->x + 1))) == NULL)
		return (NULL);
	while (*buff && i < map->x)
	{
		if ((map->map[i] = ft_strnew(map->y)) == NULL)
			return (NULL);
		while (*buff && !(ft_strchr(".oOxX", *buff)))
			buff++;
		while (ft_strchr(".oOxX", *buff))
			map->map[i][j++] = *buff++;
		if (j != map->y)
			return (NULL);
		j = 0;
		i++;
	}
	map->map[i] = 0;
	return (buff);
} 

char		*ft_get_map(t_map *map, char *buff)
{
	if ((buff = get_map_size(map, buff)) == NULL)
		return (NULL);
	if ((buff = checkmap(map, buff)) == NULL)
		return (NULL);
	return (buff);
}
