#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * execute_command - exc command with arguments
 * @command: command to be executed
 * @args: the array of arguments for the command
 */
void execute_command(char *command, char *args[])
{
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(command, args, NULL) == -1)
		{
			perror(command);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		int status;

waitpid(pid, &status, 0);
	}
}

