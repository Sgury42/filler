/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:03:23 by sgury             #+#    #+#             */
/*   Updated: 2019/04/12 11:20:14 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*un_dst;
	unsigned char	*un_src;

	i = 0;
	un_dst = (unsigned char*)dst;
	un_src = (unsigned char*)src;
	while (i < n)
	{
		un_dst[i] = un_src[i];
		i++;
	}
	return (un_dst);
}
