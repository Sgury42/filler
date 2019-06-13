/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:02:11 by sgury             #+#    #+#             */
/*   Updated: 2019/06/13 15:06:30 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	*get_player(t_map *map, char *buff)
{
	if ((buff = ft_strchr(buff, 'p')) == NULL)
		return (NULL);
	buff++;
	if (*buff == '1')
		ft_strcat(map->player, "oO");
	else if (*buff == '2')
		ft_strcat(map->player, "xX");
	else
		return (NULL);
	return (buff);
}

static char	*get_map_size(t_map *map, char *buff)
{
	if ((buff = ft_strstr(buff, "Plateau")) == NULL)
		return (NULL);
	while (ft_isdigit(*buff) == 0)
		buff++;
	while (ft_isdigit(*buff))
	{
		map->x = map->x * 10 + *buff - '0';
		buff++;
	}
	while (ft_isdigit(*buff) == 0)
		buff++;
	while (ft_isdigit(*buff))
	{
		map->y = map->y * 10 + *buff - '0';
		buff++;
	}
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
	while (*buff != '\0' && *buff != 'P')
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
	if (i != map->x)
		return (NULL);
	return (buff);
} 

char		*ft_get_map(t_map *map, char *buff)
{
	if (*buff == '$')
		if ((buff = get_player(map, buff)) == NULL)
			return (NULL);
	if ((buff = get_map_size(map, buff)) == NULL)
		return (NULL);
	if ((buff = checkmap(map, buff)) == NULL)
		return (NULL);
	return (buff);
}
