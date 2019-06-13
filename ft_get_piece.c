/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:00:08 by sgury             #+#    #+#             */
/*   Updated: 2019/06/13 15:52:56 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_piece_size(t_piece *piece, char *buff)
{
	if ((buff = ft_strstr(buff, "Piece")) == NULL)
		return (-1);
	while (!ft_isdigit(*buff))
		buff++;
	ft_putstr_fd("\n\n\n", 2);
	ft_putstr_fd(buff, 2);
	ft_putstr_fd("\n\n\n", 2);
	piece->x = ft_atoi(buff);
	buff = ft_strchr(buff, ' ');
	piece->y = ft_atoi(buff);
	ft_putstr_fd("\n\n\n", 2);
	ft_putnbr_fd(piece->x, 2);
	ft_putstr_fd("\n\n\n", 2);
	ft_putnbr_fd(piece->y, 2);
	return (1);
}

static int	check_piece(t_piece *piece, char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((piece->piece = (char **)malloc(sizeof(char *) * (piece->x + 1))) == NULL)
		return (-1);
	while (*buff && i <= piece->x)
	{
		if ((piece->piece[i] = ft_strnew(piece->y)) == NULL)
			return (-1);
		while (*buff && !(ft_strchr(".*", *buff)))
			buff++;
		while (ft_strchr(".*", *buff))
			piece->piece[i][j++] = *buff++;
		if (j != piece->y)
			return (-1);
		j = 0;
		i++;
	}
	piece->piece[i] = 0;
	if (i != piece->x)
		return (-1);
	return (0);
}

int		ft_get_piece(t_piece *piece, char *buff)
{
/*	if ((piece = (t_piece *)malloc(sizeof(t_piece))) == NULL)
		return (-1);
	ft_bzero(piece, sizeof(t_piece));*/
	if (get_piece_size(piece, buff) < 0)
		return (-1);
	if (check_piece(piece, buff) < 0)
		return (-1);
	return (0);
}
