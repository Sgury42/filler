/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:01:12 by sgury             #+#    #+#             */
/*   Updated: 2019/04/12 11:31:40 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*un_s1;
	unsigned char	*un_s2;
	size_t			i;

	un_s1 = (unsigned char *)s1;
	un_s2 = (unsigned char *)s2;
	i = 0;
	if (n <= 0)
		return (0);
	while (un_s1[i] == un_s2[i] && i < n - 1)
		i++;
	return (un_s1[i] - un_s2[i]);
}
