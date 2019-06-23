/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:18:09 by sgury             #+#    #+#             */
/*   Updated: 2019/06/23 18:29:41 by sgury            ###   ########.fr       */
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
		ft_putnbr_fd(ret, 2);
		ft_strdel(&line);
	}
	ft_putnbr_fd(ret, 2);
	ft_strdel(&line);
	ft_putstr_fd("TEST GNL\n", 2);
	if (ret < 0)
		return (NULL);
	return (buffer);
}

int			main()
{
	char	buffer[10000];
	char	*buff;
	char	*solution;
	t_map	map;
	t_piece piece;

	if ((buff = get_buffer(buffer)) == NULL)
		return (-1);
	ft_putstr_fd("TEST\n", 2);
	if (*buff == '$')
		if ((buff = ft_get_players(&map, buff)) == NULL)
			return (-1);
	ft_putstr_fd("TEST\n", 2);
	if ((buff = ft_get_map(&map, buff)) == NULL)
		return (-1);
	ft_putstr_fd("TEST\n", 2);
//	display_mapstruct(&map);
	if (ft_get_piece(&piece, buff) < 0)
		return (-1);
	ft_putstr_fd("TEST\n", 2);
//	display_piece_struct(&piece);
//	ft_score_map(&map);
//	display_mapstruct(&map);
	solution = ft_place_piece(&map, &piece);
	ft_putstr_fd("TEST\n", 2);
//	ft_place_piece(&map, &piece);
	ft_clear_data(map.map, piece.piece); 
//	ft_putstr_fd(solution, 1);
	return (0);
}
