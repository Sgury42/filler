
#include "filler.h"

int		main()
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		ft_putstr_fd(line, 2);
		ft_putchar_fd('\n', 2);
		ft_strdel(&line);
	}
	return (0);
}
