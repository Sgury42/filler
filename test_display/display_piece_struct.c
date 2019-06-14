/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_piece_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:29:39 by sgury             #+#    #+#             */
/*   Updated: 2019/06/14 13:24:48 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	display_piece_struct(t_piece *piece)
{
	ft_put_wrd_tab_fd(piece->piece, "\n", 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("piece->x = ", 2);
	ft_putnbr_fd(piece->x, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("piece->y = ", 2);
	ft_putnbr_fd(piece->y, 2);
	ft_putchar_fd('\n', 2);
}
