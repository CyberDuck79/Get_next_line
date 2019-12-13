#include "get_next_line.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int fd;
	int	ret;
	size_t	count;
	char	*line;

	ret = 0;
	count = 0;
	line = NULL;
	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
		fd = 0;
	while (((ret = get_next_line(fd, &line)) > 0) && count < 200)
	{
		printf("%d %s\n", ret, line);
		free(line);
		count++;
	}
	printf("%d %s\n", ret, line);
	if (ret == 0)
		free(line);
	//system("leaks a.out"); // comment if fsanitize used
	return (0);
}
