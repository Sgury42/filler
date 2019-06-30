/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:18:09 by sgury             #+#    #+#             */
/*   Updated: 2019/06/30 10:30:13 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	char	*line;
	t_map	map;
	t_piece piece;
//	int		ret;

	ft_bzero(&map, sizeof(t_map));
	if ((get_next_line(0, &line)) < 0)
		return (-1);
	if (ft_strstr(line, "$$$"))
		if (ft_get_players(&map, line) < 0)
			return (-1);
	while ((get_next_line(0, &line)) > 0)
	{
//		display_mapstruct(&map);
//		display_piece_struct(&piece);
//		if ((ret = get_next_line(0, &line)) <= 0)
//		{
//			ft_putstr_fd("ret = ", 2);
//			ft_putnbr_fd(ret, 2);
//			ft_putchar_fd('\n', 2);
//			return (-1);
//		}
		if (ft_strstr(line, "Plateau"))
		{
			if (ft_get_map(&map, line) < 0)
				return (-1);
			get_next_line(0, &line);
		}
		if (ft_strstr(line, "Piece"))
			if (ft_get_piece(&piece, line) < 0)
				return (-1);
//		display_mapstruct(&map);
//		display_piece_struct(&piece);
		ft_score_map(&map);
//		display_mapstruct(&map);
		if (ft_place_piece(&map, &piece) == 0)
		{
			ft_clear_data(&map, &piece);
			break;
		}
		ft_clear_data(&map, &piece); 
	}
	ft_bzero(&map, sizeof(t_map));
	return (0);
}
