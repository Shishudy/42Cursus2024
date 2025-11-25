#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int	picoshell(char **cmds[])
{
	int	fd[2];
	int	last_fd = -1;
	int	child;
	int	i;

	if (cmds == NULL)
		return (1);
	if (pipe(fd) == -1)
		return (1);
	i = 0;
	while (cmds[i] != NULL)
	{
		if(cmds[i + 1] && pipe(fd) == -1)
            return 1;
		child = fork();
        if(child == -1)
        {
            if(cmds[i + 1])
            {
                close(fd[0]);
                close(fd[1]);
            }
            return 1;
        }
		if (child == 0)
		{
			if (last_fd != -1)
			{
				if(dup2(last_fd, STDIN_FILENO) == -1)
					exit(1);
				close(last_fd);
			}
			if (cmds[i + 1] != NULL)
			{
				close(fd[0]);
				if(dup2(fd[1], STDOUT_FILENO) == -1)
					exit(1);
				close(fd[1]);
			}
			execvp(*cmds[i], cmds[i]);
			exit(1);
		}
		if (last_fd != -1)
			close(last_fd);
		if(cmds[i + 1] != NULL)
        {
            close(fd[1]);
            last_fd = fd[0];
        }
		i++;
	}
	while (wait(NULL) > 0)
		;
	return (0);
}

static int count_cmds(int argc, char **argv)
{
    int count = 1;
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "|") == 0)
            count++;
    }
    return count;
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return (fprintf(stderr, "Usage: %s cmd1 [args] | cmd2 [args] ...\n", argv[0]), 1);

    int cmd_count = count_cmds(argc, argv);
    char ***cmds = calloc(cmd_count + 1, sizeof(char **));
    if (!cmds)
        return (perror("calloc"), 1);

    int i = 1, j = 0;
    while (i < argc)
    {
        int len = 0;
        while (i + len < argc && strcmp(argv[i + len], "|") != 0)
            len++;
        
        cmds[j] = calloc(len + 1, sizeof(char *));
        if (!cmds[j])
            return (perror("calloc"), 1);
        
        for (int k = 0; k < len; k++)
            cmds[j][k] = argv[i + k];
        cmds[j][len] = NULL;
        
        i += len + 1;  // Saltar el "|"
        j++;
    }
    cmds[cmd_count] = NULL;

    int ret = picoshell(cmds);

    for (int i = 0; cmds[i]; i++)
        free(cmds[i]);
    free(cmds);

    return ret;
}