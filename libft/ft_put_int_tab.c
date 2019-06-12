/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:29:28 by sgury             #+#    #+#             */
/*   Updated: 2019/04/11 15:24:25 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_int_tab(int *tab, int size, char *separator)
{
	int	i;

	i = 0;
	if (tab == NULL || size == 0)
		return ;
	while (i < size)
	{
		ft_putnbr(tab[i]);
		if (i + 1 != size)
			ft_putstr(separator);
		i++;
	}
	ft_putchar('\n');
}
