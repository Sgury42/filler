/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:00:08 by sgury             #+#    #+#             */
/*   Updated: 2019/06/24 11:36:56 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	get_piece_size(t_piece *piece, char *line)
{
	int	i;

	i = 0;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	piece->x = ft_atoi(&line[i]);
	while (line[i] && line[i] != ' ')
		i++;
	piece->y = ft_atoi(&line[i]);
}

int			ft_get_piece(t_piece *piece, char *line)
{
	int	length;
	int	i;
	int	j;

	length = 0;
	i = 0;
	j = 0;
	get_piece_size(piece, line);
	ft_strdel(&line);
	if ((piece->piece = (char **)malloc(sizeof(char *) * (piece->x + 1))) == NULL)
		return (-1);
	while (length < piece->x)
	{
		if ((get_next_line(0, &line)) < 0)
			return (-1);
		if ((piece->piece[i] = ft_strnew(piece->y)) == NULL)
			return (-1);
		while(line[j] && j < piece->y)
		{
			piece->piece[i][j] = line[j];
			j++;
		}
		ft_strdel(&line);
		j = 0;
		i++;
		length++;
	}
	piece->piece[i] = 0;
	return (0);
}
