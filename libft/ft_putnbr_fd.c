/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:18:28 by sgury             #+#    #+#             */
/*   Updated: 2019/04/12 11:27:21 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = (long)n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= -1;
	}
	if (ln < 10)
	{
		ft_putchar_fd(ln + '0', fd);
	}
	if (ln > 9)
	{
		ft_putnbr_fd(ln / 10, fd);
		ft_putchar_fd(ln % 10 + '0', fd);
	}
}
