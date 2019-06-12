/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 08:55:23 by sgury             #+#    #+#             */
/*   Updated: 2019/04/12 13:21:25 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;

	if ((new_lst = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	new_lst = (f(lst));
	if (lst && f)
	{
		if (new_lst && lst->next)
			new_lst->next = ft_lstmap(lst->next, f);
		return (new_lst);
	}
	return (NULL);
}
