/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:18:09 by sgury             #+#    #+#             */
/*   Updated: 2019/06/13 15:52:59 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main()
{
	char	*buff;
	char	*line;
	int		ret;
	t_map	*map;
	t_piece *piece;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		ft_strcat(buff, line);
		ft_strdel(&line);
	}
	if (ret < 0)
		return (-1);
	if ((map = (t_map *)malloc(sizeof(t_map))) == NULL)
		return (-1);
	ft_bzero(map, sizeof(t_map));
	if ((buff = ft_get_map(map, buff)) == NULL)
		return (-1);
	display_mapstruct(map);
	if ((piece = (t_piece *)malloc(sizeof(t_piece))) == NULL)
		return (-1);
	ft_bzero(piece, sizeof(t_piece));
	if (ft_get_piece(piece, buff) < 0)
		return (-1);
	display_piece_struct(piece);
//	return (ft_place_piece(&buffer, piece));

	return (0);
}
