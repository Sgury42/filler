/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mapstruc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:39:25 by sgury             #+#    #+#             */
/*   Updated: 2019/06/13 14:48:28 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	display_mapstruct(t_map *map)
{
	ft_put_wrd_tab_fd(map->map, "\n", 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("map->x = ", 2);
	ft_putnbr_fd(map->x, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("map->y = ", 2);
	ft_putnbr_fd(map->y, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("player = ", 2);
	ft_putstr_fd(map->player, 2);
	ft_putchar_fd('\n', 2);
}
