/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:40:58 by sgury             #+#    #+#             */
/*   Updated: 2019/04/10 08:48:53 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_front_spaces(char const *s, int i)
{
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	return (i);
}

static int		ft_count_back_spaces(char const *s, int i)
{
	int		count;

	count = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i > 0)
	{
		count++;
		i--;
	}
	return (count);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		s_ln;
	int		f_sp;
	int		b_sp;
	int		i;

	if (s == NULL)
		return (NULL);
	s_ln = ft_strlen(s);
	str = NULL;
	i = 0;
	b_sp = 0;
	f_sp = ft_count_front_spaces(s, 0);
	b_sp = ft_count_back_spaces(s, s_ln - 1);
	s_ln = s_ln - f_sp - b_sp;
	if (s[f_sp] == '\0')
		s_ln = 0;
	if ((str = ft_strnew(s_ln)) == NULL)
		return (NULL);
	while (i < s_ln)
		str[i++] = s[f_sp++];
	return (str);
}
