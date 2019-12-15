#include "get_next_line.h"
#include <stdio.h>

int			main(int ac, char **av)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		ret;
	size_t	count;
	char	*line;

	count = 0;
	if (ac == 4)
	{
		fd1 = open(av[1], O_RDONLY);
		fd2 = open(av[2], O_RDONLY);
		fd3 = open(av[3], O_RDONLY);
	}
	else
		return (0);
	while (((ret = get_next_line(fd1, &line)) > 0) && count < 10)
	{
		printf("%i|%s\n", ret, line);
		free(line);
		count++;
	}
	count = 0;
	printf("%i|%s\n", ret, line);
	free(line);
	while (((ret = get_next_line(fd2, &line)) > 0) && count < 10)
	{
		printf("%i|%s\n", ret, line);
		free(line);
		count++;
	}
	count = 0;
	printf("%i|%s\n", ret, line);
	free(line);
	while (((ret = get_next_line(fd3, &line)) > 0) && count < 10)
	{
		printf("%i|%s\n", ret, line);
		free(line);
		count++;
	}
	count = 0;
	printf("%i|%s\n", ret, line);
	free(line);
	while (((ret = get_next_line(fd2, &line)) > 0) && count < 200)
	{
		printf("%i|%s\n", ret, line);
		free(line);
		count++;
	}
	count = 0;
	printf("%i|%s\n", ret, line);
	if (ret == 0)
		free(line);
	while (((ret = get_next_line(fd1, &line)) > 0) && count < 200)
	{
		printf("%i|%s\n", ret, line);
		free(line);
		count++;
	}
	count = 0;
	printf("%i|%s\n", ret, line);
	if (ret == 0)
		free(line);
	while (((ret = get_next_line(fd3, &line)) > 0) && count < 200)
	{
		printf("%i|%s\n", ret, line);
		free(line);
		count++;
	}
	count = 0;
	printf("%i|%s\n", ret, line);
	if (ret == 0)
		free(line);
	//system("leaks a.out"); // comment if used with fsanitize
	return (0);
}
