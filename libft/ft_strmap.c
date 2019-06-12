/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:24:10 by sgury             #+#    #+#             */
/*   Updated: 2019/04/10 08:47:17 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((str = ft_memalloc(ft_strlen(s) + 1)) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = (f(s[i]));
		i++;
	}
	return (str);
}
