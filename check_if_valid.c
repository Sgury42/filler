/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 10:58:58 by sgury             #+#    #+#             */
/*   Updated: 2019/07/02 10:59:18 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_piece_valid(t_piece *piece, char *buff)
{
	int	len;
	int	i;

	i = 0;
	while (buff[i] && ft_strchr(".*", buff[i]))
		i++;
	if ((len = ft_strlen(buff)) != piece->x * piece->y || i != len)
	{
		ft_strdel(&buff);
		return (-1);
	}
	return (0);
}
