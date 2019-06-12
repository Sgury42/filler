/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:46:08 by sgury             #+#    #+#             */
/*   Updated: 2019/04/12 11:47:02 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			while (haystack[j + i] == needle[j])
			{
				j++;
				if (needle[j] == '\0')
					return ((char *)haystack + i);
			}
			j = 0;
		}
		i++;
	}
	return (0);
}
