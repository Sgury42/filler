/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 10:15:46 by sgury             #+#    #+#             */
/*   Updated: 2019/04/12 11:19:30 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*un_dst;
	unsigned char	*un_src;
	unsigned char	un_c;
	size_t			i;

	i = 0;
	un_dst = (unsigned char *)dst;
	un_src = (unsigned char *)src;
	un_c = (unsigned char)c;
	while (i < n)
	{
		un_dst[i] = un_src[i];
		if (un_src[i] == un_c)
			return ((char *)dst + i + 1);
		i++;
	}
	return (0);
}
