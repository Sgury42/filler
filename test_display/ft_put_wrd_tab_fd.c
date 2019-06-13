/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_wrd_tab_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:06:48 by sgury             #+#    #+#             */
/*   Updated: 2019/06/13 14:48:48 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	ft_put_wrd_tab_fd(char **tab, char *separator, int fd)
{
	int	i;

	i = 0;
	if (*tab == NULL)
		return ;
	while (tab[i])
	{
		ft_putstr_fd(tab[i], fd);
		if (tab[i + 1] != '\0')
			ft_putstr_fd(separator, fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}
