#include "get_next_line.h"
#include <stdio.h>

int			main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	*line;

	fd = (ac == 2 ? open(av[1], O_RDONLY) : 0);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%i|%s\n", ret, line);
		free(line);
	}
	printf("%i|%s\n", ret, line);
	if (ret == 0)
		free(line);
	system("leaks a.out"); // comment if fsanitize used
	return (0);
}
