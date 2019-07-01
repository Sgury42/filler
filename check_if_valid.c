#include "filler.h"

int	ft_piece_valid(t_piece *piece, char *buff)
{
	int	len;
	int	i;

	i = 0;
	if ((len = ft_strlen(buff)) != piece->x * piece->y)
		return (-1);
	while (buff[i] && ft_strchr(".*", buff[i]))
		i++;
	if (i != len)
		return (-1);
	return (0);
}
