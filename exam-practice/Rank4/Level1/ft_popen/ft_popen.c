#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_popen(const char *file, char *const argv[], char type)
{
	int	fd[2];
	int	child;

	if (file == NULL || argv == NULL)
		return (-1);
	if (type != 'r' && type != 'w')
		return (-1);
	if (pipe(fd) == -1)
		return (-1);
	child = fork();
	if (child == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	if (child == 0)
	{
		if(type == 'r')
        {
            if(dup2(fd[1], STDOUT_FILENO) == -1)
                exit(1);
        }
        else
        {
            if(dup2(fd[0], STDIN_FILENO) == -1)
                exit(1);
        }
        close(fd[0]);
        close(fd[1]);
        execvp(file, argv);
        exit(1);
	}
	if(type == 'r')
	{
		close(fd[1]);
		return(fd[0]);
	}
	else
	{
		close(fd[0]);
		return(fd[1]);
	}
}

int main()
{
    int  fd;
    char line[1000];

    fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
    while (read(fd, line, 1000) != 0)
	{
		printf("%s", line);
	}
    return (0);
}
