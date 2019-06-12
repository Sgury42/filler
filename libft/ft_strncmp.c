/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 08:38:59 by sgury             #+#    #+#             */
/*   Updated: 2019/04/12 11:40:55 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*un_s1;
	unsigned char	*un_s2;

	i = 0;
	un_s1 = (unsigned char *)s1;
	un_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (un_s1[i] == un_s2[i] && un_s1[i] != '\0'
			&& un_s2[i] != '\0' && i < n - 1)
		i++;
	return (un_s1[i] - un_s2[i]);
}
