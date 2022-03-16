#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

void	multi_fd(int fd, char *line)
{
	line = get_next_line(fd);
	printf("fd(%d) line : %s", fd, line);
	free(line);
}

int main()
{
    int fd[3];
    char    *line;

    fd[0] = open("text1.txt", O_RDONLY);
	fd[1] = open("text2.txt", O_RDONLY);
	fd[2] = open("text3.txt", O_RDONLY);

    // while ((line = get_next_line(fd)))
    // {
    //     printf("line : %s", line);
    //     free(line);
    // }
	line = 0;
	multi_fd(fd[0], line);
	multi_fd(fd[1], line);
	multi_fd(fd[2], line);
printf("----------------\n");
	multi_fd(fd[0], line);
	multi_fd(fd[1], line);
	multi_fd(fd[2], line);
printf("----------------\n");
	multi_fd(fd[0], line);
	multi_fd(fd[1], line);
	multi_fd(fd[2], line);

	system("leaks a.out");
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	
    return (0);
}
