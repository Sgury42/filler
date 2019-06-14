/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:00:08 by sgury             #+#    #+#             */
/*   Updated: 2019/06/14 16:04:20 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	*get_piece_size(t_piece *piece, char *buff)
{
	if ((buff = ft_strstr(buff, "Piece")) == NULL)
		return (NULL);
	while (*buff && !ft_isdigit(*buff))
		buff++;
	piece->x = ft_atoi(buff);
	if ((buff = ft_strchr(buff, ' ')) == NULL)
		return (NULL);
	piece->y = ft_atoi(buff);
	return (buff);
}

static int	check_piece(t_piece *piece, char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((piece->piece = (char **)malloc(sizeof(char *) * (piece->x + 1))) == NULL)
		return (-1);
	while (*buff && !(ft_strchr(".*", *buff)))
		buff++;
	while (*buff && i < piece->x)
	{
		if ((piece->piece[i] = ft_strnew(piece->y)) == NULL)
			return (-1);
		while (*buff && j < piece->y)
			piece->piece[i][j++] = *buff++;
		j = 0;
		i++;
	}
	piece->piece[i] = 0;
	return (0);
}

int			ft_get_piece(t_piece *piece, char *buff)
{
	if ((buff = get_piece_size(piece, buff)) == NULL)
		return (-1);
	if (check_piece(piece, buff) < 0)
		return (-1);
	return (0);
}
