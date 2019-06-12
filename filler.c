/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:18:09 by sgury             #+#    #+#             */
/*   Updated: 2019/06/12 15:30:44 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main()
{
	char	*buff;
	char	*line;
	int		ret;

//	if ((buff = (t_buff *)malloc(sizeof(t_buff))) == NULL)
//		return (-1);
//	ft_bzero(buff, sizeof(t_buff));
	while ((ret = get_next_line(0, &line)) > 0)
	{
		ft_strcat(buff, line);
		ft_strdel(&line);
	}
	if (ret < 0)
		return (-1);
	if (ft_get_map(buff) < 0)
		return (-1);
//	if (ft_get_piece(&buffer) < 0)
//		return (-1);
//	return (ft_place_piece(&buffer, piece));
	return (0);
}
