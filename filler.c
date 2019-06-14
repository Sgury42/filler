/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:18:09 by sgury             #+#    #+#             */
/*   Updated: 2019/06/14 16:04:15 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	*get_buffer(char *buffer)
{
	char	*line;
	int		ret;

	ft_bzero(buffer, sizeof(buffer));
	while ((ret = get_next_line(0, &line)) > 0)
	{
		ft_strcat(buffer, line);
		ft_strdel(&line);
	}
	if (ret < 0)
		return (NULL);
	return (buffer);
}

int			main()
{
	char	buffer[4096];
	char	*buff;
	t_map	map;
	t_piece piece;

	if ((buff = get_buffer(buffer)) == NULL)
		return (-1);
	if (*buff == '$')
		if ((buff = ft_get_players(&map, buff)) == NULL)
			return (-1);
	if ((buff = ft_get_map(&map, buff)) == NULL)
		return (-1);
	display_mapstruct(&map);
	if (ft_get_piece(&piece, buff) < 0)
		return (-1);
	display_piece_struct(&piece);
//	return (ft_place_piece(buff, piece));
	ft_clear_data(map.map, piece.piece); 
	return (0);
}
