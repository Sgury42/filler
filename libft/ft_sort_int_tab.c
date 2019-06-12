/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:00:57 by sgury             #+#    #+#             */
/*   Updated: 2019/04/12 11:32:47 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		*ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = 0;
	if (tab == NULL)
		return (NULL);
	while (i < size)
	{
		if (tab[i - 1] > tab[i])
		{
			tmp = tab[i - 1];
			tab[i - 1] = tab[i];
			tab[i] = tmp;
			i = 0;
		}
		i++;
	}
	return (tab);
}
