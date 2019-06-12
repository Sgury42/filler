/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_wrd_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:09:18 by sgury             #+#    #+#             */
/*   Updated: 2019/04/12 11:22:18 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_wrd_tab(char **tab, char *separator)
{
	int	i;

	i = 0;
	if (*tab == NULL)
		return ;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		if (tab[i + 1] != '\0')
			ft_putstr(separator);
		i++;
	}
	ft_putchar('\n');
}
