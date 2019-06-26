/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_piece_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:29:39 by sgury             #+#    #+#             */
/*   Updated: 2019/06/26 17:54:03 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	display_piece_struct(t_piece *piece)
{
	ft_putstr_fd("parsed piece : \n", 2);
	ft_put_wrd_tab_fd(piece->piece, "\n", 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("piece->x = ", 2);
	ft_putnbr_fd(piece->x, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("piece->y = ", 2);
	ft_putnbr_fd(piece->y, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("empty colones = ", 2);
	ft_putnbr_fd(piece->empty_col, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("empty lines = ", 2);
	ft_putnbr_fd(piece->empty_lines, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("heigth = ", 2);
	ft_putnbr_fd(piece->height, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("width = ", 2);
	ft_putnbr_fd(piece->width, 2);
	ft_putchar_fd('\n', 2);
}
