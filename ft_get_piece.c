/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:00:08 by sgury             #+#    #+#             */
/*   Updated: 2019/06/25 09:27:44 by sgury            ###   ########.fr       */
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
	ft_strdel(&line);
}

static int	parse_line(t_piece *piece, char *line, int i)
{
	int	j;

	j = 0;
	if ((piece->piece[i] = ft_strnew(piece->y)) == NULL)
		return (-1);
	while (line[j] && j < piece->y)
	{
		piece->piece[i][j] = line[j];
		j++;
	}
	ft_strdel(&line);
	return (0);
}

int			ft_get_piece(t_piece *piece, char *line)
{
	int	length;

	length = 0;
	get_piece_size(piece, line);
	if ((piece->piece = (char **)malloc(sizeof(char *) * (piece->x + 1)))
			== NULL)
		return (-1);
	while (length < piece->x)
	{
		if ((get_next_line(0, &line)) < 0)
			return (-1);
		if (parse_line(piece, line, length) < 0)
			return (-1);
		length++;
	}
	piece->piece[length] = 0;
	return (0);
}
