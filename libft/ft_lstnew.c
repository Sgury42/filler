/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:47:50 by sgury             #+#    #+#             */
/*   Updated: 2019/04/12 12:03:45 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_content;

	if ((new_content = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_content->content = NULL;
		new_content->content_size = 0;
	}
	else
	{
		if ((new_content->content = malloc(content_size)) == NULL)
			return (NULL);
		new_content->content = ft_memcpy(new_content->content,
				content, content_size);
		new_content->content_size = content_size;
	}
	new_content->next = NULL;
	return (new_content);
}
