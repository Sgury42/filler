/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:02:11 by sgury             #+#    #+#             */
/*   Updated: 2019/06/12 15:30:42 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_map_size(t_map *map, char *buffer)
{
	map->x = 0;
	map->y = 0;
	while (ft_isdigit(*buffer) == 0)
	{
//		ft_putchar_fd(*buffer, 2);
		buffer++;
	}
	ft_putstr_fd("*buffer digit = ", 2);
	ft_putchar_fd(*buffer, 2);
	while (ft_isdigit(*buffer))
	{
		map->x = map->x * 10 + *buffer - '0';
		buffer++;
	}
	while (ft_isdigit(*buffer) == 0)
		buffer++;
	while (ft_isdigit(*buffer))
	{
		map->y = map->y * 10 + *buffer - '0';
		buffer++;
	}
	ft_putstr_fd("x = ", 2);
	ft_putnbr_fd(map->x, 2);
	ft_putstr_fd("y = ", 2);
	ft_putnbr_fd(map->y, 2);
	return (0);
}
/*
static int	checkmap(t_map map, char **buffer);
{
	int	i;
	int	j;

	i = 0;
	j - 0;
	while (*buffer != '\0' && *buffer != 'P')
	{
		while (*buffer != '.')
			buffer++;
		while (ft_strchr(".oOxX", *buffer))
		{
			map[i][j++] = *buffer++;
		}
		if (j != map->y)
			return (-1);
		j = 0;
		i++;
	}
	if (i != map->x)
		return (-1);
	return (0);
} */

int		ft_get_map(char *buff)
{
	t_map	map;
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strstr(buff, "Plateau");
//	ft_strdel(buff);
	buff = tmp;
	get_map_size(&map, buff);
//	if (checkmap(map, &buffer) < 0)
//		return (-1);
	return (0);
}
