/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wrd_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:31:20 by sgury             #+#    #+#             */
/*   Updated: 2019/04/11 15:47:07 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sort_wrd_tab(char **tab)
{
	int		i;
	char	*tmp;

	i = 1;
	if (*tab == NULL)
		return (NULL);
	while (tab[i] != '\0')
	{
		if (ft_strcmp(tab[i - 1], tab[i]) > 0)
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
