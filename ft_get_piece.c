/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:00:08 by sgury             #+#    #+#             */
/*   Updated: 2019/06/29 16:23:13 by sgury            ###   ########.fr       */
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
//	char	*buff;
	char	buff[4096];
//	char	*tmp;

	length = 0;
//	if ((buff = ft_strnew(0)) == NULL)
//		return (-1);
	ft_bzero(piece, sizeof(t_piece));
	ft_bzero(buff, sizeof(buff));
	get_piece_size(piece, line);
//	ft_putstr_fd("real piece : \n", 2);
	while (length < piece->x)
	{
		if ((get_next_line(0, &line)) < 0)
			return (-1);
//		ft_putstr_fd(line, 2);
//		ft_putchar_fd('\n', 2);
//		if ((tmp = ft_strdup(ft_strcat(buff, line))) == NULL)
//			return (-1);
		ft_strcat(buff, line);
//		ft_strdel(&buff);
		ft_strdel(&line);
//		buff = tmp;
		length++;
//		ft_putstr_fd("buff :", 2);
//		ft_putendl_fd(buff, 2);
	}
	empty_lines(piece, buff);
	empty_columns(piece, buff);
	if (parse_piece(piece, buff) < 0)
		return (-1);
//	ft_strdel(&buff);
	return (0);
}
