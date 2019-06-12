/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:22:43 by sgury             #+#    #+#             */
/*   Updated: 2019/04/12 11:31:09 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*un_s;
	unsigned char	un_c;
	size_t			i;

	i = 0;
	un_s = (unsigned char *)s;
	un_c = (unsigned char)c;
	while (i < n)
	{
		if (un_s[i] == un_c)
			return (un_s + i);
		i++;
	}
	return (0);
}
