/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:00:08 by sgury             #+#    #+#             */
/*   Updated: 2019/06/30 10:03:18 by sgury            ###   ########.fr       */
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

static void	empty_lines(t_piece *piece, char *buff)
{
	int	i;
	int	count;

	i = 0;
	while (buff[i] && buff[i] == '.')
		i++;
	piece->empty_lines = i / piece->y;
	i = ft_strlen(buff) - 1;
	count = 0;
	while (buff[i] && buff[i--] == '.')
		count++;
	piece->height = piece->x - piece->empty_lines - (count / piece->y);
}

static void	empty_columns(t_piece *piece, char *buff)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	while (++i < piece->y)
	{
		count = 0;
		j = i;
		while (buff[j] && buff[j] == '.')
		{
			j += piece->y;
			count++;
		}
		if (count == piece->x)
			piece->empty_col++;
		else
			break ;
	}
	i = piece->y - 1;
	while (i > 0)
	{
		j = i;
		count = 0;
		while (buff[j] && buff[j] == '.')
		{
			j += piece->y;
			count++;
		}
		if (count == piece->x)
			piece->empty_col_aft++;
		else
			break ;
		i--;
	}
	piece->width = piece->y - piece->empty_col - piece->empty_col_aft;
}

static int	parse_piece(t_piece *piece, char *buff)
{
	int	i;
	int	j;
	int	k;

	if ((piece->piece = (char **)malloc(sizeof(char *)
					* (piece->height + 1))) == NULL)
		return (-1);
	i = 0;
	j = 0;
	k = (piece->empty_lines * piece->y) + piece->empty_col;
	while (i < piece->height)
	{
		if ((piece->piece[i] = ft_strnew(piece->width)) == NULL)
			return (-1);
		while (j < piece->width && buff[k])
			piece->piece[i][j++] = buff[k++];
		piece->piece[i][j] = '\0';
		k = k + piece->empty_col + piece->empty_col_aft;
		j = 0;
		i++;
	}
	piece->piece[i] = 0;
	return (0);
}

int			ft_get_piece(t_piece *piece, char *line)
{
	int		length;
	char	*buff;

	length = 0;
	ft_bzero(piece, sizeof(t_piece));
	get_piece_size(piece, line);
	if ((buff = ft_strnew(piece->x * piece->y)) == NULL)
		return (-1);
	while (length < piece->x)
	{
		if ((get_next_line(0, &line)) < 0)
			return (-1);
		ft_strcat(buff, line);
		ft_strdel(&line);
		length++;
	}
	empty_lines(piece, buff);
	empty_columns(piece, buff);
	if (parse_piece(piece, buff) < 0)
		return (-1);
	ft_strdel(&buff);
	return (0);
}
