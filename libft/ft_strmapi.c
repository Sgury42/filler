/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:33:14 by sgury             #+#    #+#             */
/*   Updated: 2019/04/10 08:47:26 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((str = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = (f(i, s[i]));
		i++;
	}
	return (str);
}
